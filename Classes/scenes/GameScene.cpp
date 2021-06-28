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

    const auto sprite_bg = Utils::makeRepeatingBg(PATH_IMG_BG, origin, visibleSize);
    addChild(sprite_bg);

    player = Player::create();
    player->setLimitMinX(origin.x);
    player->setLimitMaxX(origin.x + visibleSize.width);
    player->resetPosition();
    addChild(player);

    const auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(Game::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(Game::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    scheduleUpdate();
    return true;
}

void Game::update(float dt) {
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
