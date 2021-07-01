#include "GameScene.h"

USING_NS_CC;

Scene *Game::createScene() {
    return Game::create();
}

bool Game::init() {
    if (!Scene::initWithPhysics()) {
        return false;
    }

    enemiesAlive = 0;
    killStreakCounter = 0;

    _physicsWorld->setGravity(Vec2::ZERO);
//    _physicsWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto const visibleSize = _director->getVisibleSize();
    auto const origin = _director->getVisibleOrigin();

    playAreaMin = Vec2(origin.x + HALF_SHIP_CELL_SIZE + PLAY_AREA_PADDING,
                       origin.y + HALF_SHIP_CELL_SIZE + PLAY_AREA_PADDING);

    playAreaMax = Vec2(origin.x + visibleSize.width - HALF_SHIP_CELL_SIZE - PLAY_AREA_PADDING,
                       origin.y + visibleSize.height - HALF_SHIP_CELL_SIZE - PLAY_AREA_PADDING - PLAY_AREA_EXTRA_TOP_PADDING);

    auto const background = Utils::makeRepeatingBg(PATH_IMG_BG, origin, visibleSize);
    addChild(background);

    player = Player::create();
    player->setLimitMinX(playAreaMin.x);
    player->setLimitMaxX(playAreaMax.x);
    player->resetPosition(playAreaMin.y);
    addChild(player);

    makeGridOfEnemies(3);

    scoreLabel = Label::createWithTTF("", PATH_FONT_FUTURE_THIN, 10);
    scoreLabel->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    scoreLabel->setPosition(Vec2(origin.x + 15, origin.y + visibleSize.height - 10));
    updateScoreLabel();
    addChild(scoreLabel);

    killStreakLabel = Label::createWithTTF("", PATH_FONT_FUTURE_THIN, 10);
    killStreakLabel->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
    killStreakLabel->setPosition(Vec2(origin.x + visibleSize.width - 15, origin.y + visibleSize.height - 10));
    updateKillStreakLabel();
    addChild(killStreakLabel);

    auto const touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(Game::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(Game::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    auto const contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Game::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    auto const enemyPassedFinishListener = EventListenerCustom::create(EVENT_ENEMY_PASSED_FINISH, CC_CALLBACK_0(Game::onEnemyPassedFinish, this));
    _eventDispatcher->addEventListenerWithSceneGraphPriority(enemyPassedFinishListener, this);

    AudioEngine::play2d(PATH_SOUND_WIN); // reuse win sfx

    schedule(CC_SCHEDULE_SELECTOR(Game::spawnBullet), 1.0f / PLAYER_RATE_OF_FIRE);
    return true;
}

void Game::spawnBullet(float const dt) {
    auto const sound = isPowerActive ? PATH_SOUND_FIRE_STRONG : PATH_SOUND_FIRE_WEAK;
    AudioEngine::play2d(sound, false, 0.1f);

    auto const bullet = isPowerActive ? BulletFactory::makeStrongBullet()
                                      : BulletFactory::makeWeakBullet();
    bullet->setPosition(player->getPosition());
    addChild(bullet);
}

bool Game::onTouchBegan(Touch *const touch, Event *const event) {
    auto const touchState = calculateTouchState(touch->getLocation());
    auto const newPlayerSpeedX = calculatePlayerSpeedX(touchState);
    player->setSpeedX(newPlayerSpeedX);

    return true;
}

void Game::onTouchMoved(Touch *const touch, Event *const event) {
    auto const touchState = calculateTouchState(touch->getLocation());
    auto const newPlayerSpeedX = calculatePlayerSpeedX(touchState);
    player->setSpeedX(newPlayerSpeedX);
}

void Game::onTouchEnded(Touch *const touch, Event *const event) {
    auto const newPlayerSpeedX = calculatePlayerSpeedX(NONE);
    player->setSpeedX(newPlayerSpeedX);
}

bool Game::onContactBegin(PhysicsContact const &contact) {
    auto const nodeA = contact.getShapeA()->getBody()->getNode();
    auto const nodeB = contact.getShapeB()->getBody()->getNode();
    auto const contactPoint = contact.getContactData()->points[0];

    if (nodeA && nodeB) {
        if (nodeA->getTag() == TAG_BULLET && nodeB->getTag() == TAG_ENEMY) {
            auto const bullet = static_cast<Bullet *>(nodeA);
            auto const enemy = static_cast<Enemy *>(nodeB);
            handleBulletHit(bullet, enemy, contactPoint);
        } else if (nodeA->getTag() == TAG_ENEMY && nodeB->getTag() == TAG_BULLET) {
            auto const enemy = static_cast<Enemy *>(nodeA);
            auto const bullet = static_cast<Bullet *>(nodeB);
            handleBulletHit(bullet, enemy, contactPoint);
        }
    }

    return false; // no collision
}

void Game::handleBulletHit(Bullet *const bullet, Enemy *const enemy, Vec2 const &contactPoint) {
    auto const damage = bullet->getDamage();
    auto const isBulletStrong = bullet->getIsStrong();
    enemy->takeDamage(damage);

    removeChild(bullet, true);

    if (enemy->isDead()) {
        score += enemy->getScore();
        updateScoreLabel();
        enemiesAlive--;
        removeChild(enemy, true);
        AudioEngine::play2d(PATH_SOUND_KILL);

        if (enemiesAlive <= 0) {
            handleGameOver(true);
        }

        if (!isPowerActive && !isBulletStrong) {
            killStreakCounter++;
            powerUpIfAvailable();
            updateKillStreakLabel();
        }
    }

    spawnHitMarker(contactPoint, isBulletStrong);
}

Game::TouchState Game::calculateTouchState(Vec2 const &touchLocation) {
    auto const visibleSize = _director->getVisibleSize();
    auto const origin = _director->getVisibleOrigin();
    auto const halfScreenX = origin.x + visibleSize.width / 2;
    auto const isLeft = touchLocation.x < halfScreenX;
    return isLeft ? LEFT : RIGHT;
}

float Game::calculatePlayerSpeedX(Game::TouchState const &touchState) {
    switch (touchState) {
        case NONE:
            return 0;
        case LEFT:
            return -PLAYER_SPEED;
        case RIGHT:
            return PLAYER_SPEED;
    }
}

void Game::makeGridOfEnemies(int const rows) {
    const float rowWidth = playAreaMax.x - playAreaMin.x;
    const int cellCount = std::ceil(rowWidth / SHIP_CELL_SIZE);
    const float effectiveRowWidth = SHIP_CELL_SIZE * (float) (cellCount - 1);
    const float halfExcessRowWidth = (rowWidth - effectiveRowWidth) / 2.0f;

    for (int iy = 0; iy < rows; ++iy) {
        auto const posY = playAreaMax.y - (float) iy * SHIP_CELL_SIZE;

        for (int ix = 0; ix < cellCount; ++ix) {
            auto const isStrong = (iy + ix) % 2 == 0;
            float const posX = playAreaMin.x + halfExcessRowWidth + (float) ix * SHIP_CELL_SIZE;
            auto const newEnemy = isStrong ? EnemyFactory::makeStrongEnemy()
                                           : EnemyFactory::makeWeakEnemy();
            newEnemy->setPosition(posX, posY);
            newEnemy->setFinishLineY(playAreaMin.y);
            addChild(newEnemy);
            enemiesAlive++;
        }
    }
}

void Game::spawnHitMarker(Vec2 const &contactPoint, bool const isStrong) {
    auto const hitMarker = isStrong ? HitMarkerFactory::makeStrongHitMarker()
                                    : HitMarkerFactory::makeWeakHitMarker();
    hitMarker->setPosition(contactPoint);
    addChild(hitMarker);
}

void Game::powerUpIfAvailable() {
    if (killStreakCounter >= KILL_STREAK_FOR_POWER) {
        killStreakCounter = 0;
        isPowerActive = true;
        player->enablePowerAura();
        AudioEngine::play2d(PATH_SOUND_POWER_UP);

        scheduleOnce(CC_SCHEDULE_SELECTOR(Game::powerDown), POWER_DURATION);
    }
}

void Game::powerDown(float const dt) {
    isPowerActive = false;
    player->disablePowerAura();
    AudioEngine::play2d(PATH_SOUND_POWER_DOWN);
    updateKillStreakLabel();
}

void Game::handleGameOver(bool const isVictory) {
    _scheduler->unscheduleAllForTarget(this);
    AudioEngine::stopAll();

    GameOverData const gameOverData = {
            .isVictory = isVictory,
            .score = score
    };

    auto const gameOverScene = GameOver::create(gameOverData);
    _director->replaceScene(TransitionFade::create(0.25f, gameOverScene, TRANSITION_FADE_COLOR));
}

void Game::updateScoreLabel() {
    scoreLabel->setString("SCORE: " + std::to_string(score));
}

void Game::updateKillStreakLabel() {
    if (isPowerActive) {
        killStreakLabel->setString("POWER ACTIVE");
        killStreakLabel->setTextColor(Color4B::GREEN);
    } else {
        killStreakLabel->setString("KILL STREAK: " + std::to_string(killStreakCounter));
        killStreakLabel->setTextColor(Color4B::WHITE);
    }
}

void Game::onEnemyPassedFinish() {
    handleGameOver(false);
}
