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

    playerVelocity = Vec2::ZERO;

    auto visibleSize = _director->getVisibleSize();
    auto origin = _director->getVisibleOrigin();

    auto sprite_bg = Utils::makeRepeatingBg(PATH_IMG_BG, origin, visibleSize);
    addChild(sprite_bg);

    player = Sprite::create(PATH_IMG_PLAYER);
    player->setPosition(origin.x + visibleSize.width / 2, origin.y + 50);
    player->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    addChild(player);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(Game::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(Game::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    this->scheduleUpdate();
    return true;
}

void Game::update(float dt) {
    auto playerCurrentPosition = player->getPosition();
    auto playerNewPosition = playerCurrentPosition + (playerVelocity * dt);
    player->setPosition(playerNewPosition);
}

bool Game::onTouchBegan(Touch *touch, Event *event) {
    auto touchState = calculateTouchState(touch->getLocation());
    playerVelocity = calculatePlayerVelocity(touchState);
    return true;
}

void Game::onTouchMoved(Touch *touch, Event *event) {
    auto touchState = calculateTouchState(touch->getLocation());
    playerVelocity = calculatePlayerVelocity(touchState);
}

void Game::onTouchEnded(Touch *touch, Event *event) {
    playerVelocity = calculatePlayerVelocity(UP);
}

Game::TouchState Game::calculateTouchState(const Vec2 touchLocation) {
    auto visibleSize = _director->getVisibleSize();
    auto origin = _director->getVisibleOrigin();
    auto halfScreenX = origin.x + visibleSize.width / 2;

    auto isLeft = touchLocation.x < halfScreenX;
    return isLeft ? LEFT : RIGHT;
}

Vec2 Game::calculatePlayerVelocity(const Game::TouchState touchState) {
    switch (touchState) {
        case UP:    return {0, 0};
        case LEFT:  return {-PLAYER_SPEED, 0};
        case RIGHT: return {PLAYER_SPEED, 0};
    }
}
