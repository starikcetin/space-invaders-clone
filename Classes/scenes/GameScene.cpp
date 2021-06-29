#include "GameScene.h"

USING_NS_CC;

Scene* Game::createScene()
{
    return Game::create();
}

bool Game::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    const auto visibleSize = _director->getVisibleSize();
    const auto origin = _director->getVisibleOrigin();

    playAreaMin = Vec2(origin.x + HALF_SHIP_CELL_SIZE + PLAY_AREA_PADDING,
                       origin.y + HALF_SHIP_CELL_SIZE + PLAY_AREA_PADDING);

    playAreaMax = Vec2(origin.x + visibleSize.width - HALF_SHIP_CELL_SIZE - PLAY_AREA_PADDING,
                       origin.y + visibleSize.height - HALF_SHIP_CELL_SIZE - PLAY_AREA_PADDING);

    const auto sprite_bg = Utils::makeRepeatingBg(PATH_IMG_BG, origin, visibleSize);
    addChild(sprite_bg);

    player = Player::create();
    player->setLimitMinX(playAreaMin.x);
    player->setLimitMaxX(playAreaMax.x);
    player->resetPosition(playAreaMin.y);
    addChild(player);

    makeGridOfEnemies(3);

    const auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(Game::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(Game::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    schedule(CC_SCHEDULE_SELECTOR(Game::spawnBullet), 1.0f / PLAYER_RATE_OF_FIRE);
    return true;
}

void Game::spawnBullet(float dt) {
    const auto bullet = BulletFactory::makeWeakBullet();
    bullet->setPosition(player->getPosition());
    addChild(bullet);
}

bool Game::onTouchBegan(Touch *touch, Event *event) {
    const auto touchState = calculateTouchState(touch->getLocation());
    const auto newPlayerSpeedX = calculatePlayerSpeedX(touchState);
    player->setSpeedX(newPlayerSpeedX);

    return true;
}

void Game::onTouchMoved(Touch *touch, Event *event) {
    const auto touchState = calculateTouchState(touch->getLocation());
    const auto newPlayerSpeedX = calculatePlayerSpeedX(touchState);
    player->setSpeedX(newPlayerSpeedX);
}

void Game::onTouchEnded(Touch *touch, Event *event) {
    const auto newPlayerSpeedX = calculatePlayerSpeedX(NONE);
    player->setSpeedX(newPlayerSpeedX);
}

Game::TouchState Game::calculateTouchState(const Vec2 touchLocation) {
    const auto visibleSize = _director->getVisibleSize();
    const auto origin = _director->getVisibleOrigin();
    const auto halfScreenX = origin.x + visibleSize.width / 2;
    const auto isLeft = touchLocation.x < halfScreenX;
    return isLeft ? LEFT : RIGHT;
}

float Game::calculatePlayerSpeedX(const Game::TouchState touchState) {
    switch (touchState) {
        case NONE:  return 0;
        case LEFT:  return -PLAYER_SPEED;
        case RIGHT: return PLAYER_SPEED;
    }
}

void Game::makeGridOfEnemies(const int rows) {
    for (int i = 0; i < rows; ++i) {
        const auto posY = playAreaMax.y - (float) i * SHIP_CELL_SIZE;
        const auto isStrong = i % 2 == 1;
        makeRowOfEnemies(posY, isStrong);
    }
}

// TODO: inline this into makeGridOfEnemies
void Game::makeRowOfEnemies(const float posY, const bool isStrong) {
    const float rowWidth = playAreaMax.x - playAreaMin.x;
    const int cellCount = std::ceil(rowWidth / SHIP_CELL_SIZE);
    const float effectiveRowWidth = SHIP_CELL_SIZE * (float)(cellCount - 1);
    const float halfExcessRowWidth = (rowWidth - effectiveRowWidth) / 2.0f;

    for (int i = 0; i < cellCount; ++i) {
        const float posX = playAreaMin.x + halfExcessRowWidth + (float)i * SHIP_CELL_SIZE;
        const auto newEnemy = isStrong ? EnemyFactory::makeStrongEnemy() : EnemyFactory::makeWeakEnemy();
        newEnemy->setPosition(posX, posY);
        addChild(newEnemy);
    }
}
