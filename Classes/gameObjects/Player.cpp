#include "Player.h"

bool Player::init() {
    setTag(TAG_PLAYER);

    body = Sprite::create(PATH_IMG_PLAYER);
    body->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    body->setPosition(Vec2::ZERO);
    addChild(body);

    aura = Sprite::create(PATH_IMG_AURA);
    aura->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    aura->setPosition(Vec2::ZERO);
    aura->setOpacity(0.0f);
    addChild(aura);

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

void Player::enablePowerAura() {
    auto const fadeIn = FadeIn::create(AURA_FADE_DURATION);
    aura->runAction(fadeIn);
}

void Player::disablePowerAura() {
    auto const fadeOut = FadeOut::create(AURA_FADE_DURATION);
    aura->runAction(fadeOut);
}
