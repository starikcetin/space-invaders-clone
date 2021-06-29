#include "Player.h"

bool Player::init() {
    sprite = Sprite::create(PATH_IMG_PLAYER);
    sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    sprite->setPosition(Vec2::ZERO);
    addChild(sprite);

    scheduleUpdate();
    return true;
}

void Player::resetPosition(const float posY) {
    auto const x = (limitMinX + limitMaxX) / 2.0f;
    setPosition(x, posY);
}

void Player::update(float dt) {
    const auto deltaX = speedX * dt;
    const auto newX = calculateNewXWithinLimits(deltaX);
    setPositionX(newX);
}

float Player::calculateNewXWithinLimits(const float deltaX) {
    const auto newUnboundX = getPositionX() + deltaX;
    const auto newBoundX = clampf(newUnboundX, limitMinX, limitMaxX);
    return newBoundX;
}
