#include "Player.h"

bool Player::init() {
    setTag(TAG_PLAYER);

    sprite = Sprite::create(PATH_IMG_PLAYER);
    sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    sprite->setPosition(Vec2::ZERO);
    addChild(sprite);

    scheduleUpdate();
    return true;
}

void Player::update(float const dt) {
    auto const deltaX = speedX * dt;
    auto const newX = calculateNewXWithinLimits(deltaX);
    setPositionX(newX);
}

void Player::resetPosition(float const posY) {
    auto const x = (limitMinX + limitMaxX) / 2.0f;
    setPosition(x, posY);
}

float Player::calculateNewXWithinLimits(float const deltaX) {
    auto const newUnboundX = getPositionX() + deltaX;
    auto const newBoundX = clampf(newUnboundX, limitMinX, limitMaxX);
    return newBoundX;
}
