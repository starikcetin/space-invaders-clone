#include "Bullet.h"

bool Bullet::init() {
    auto const visibleSize = _director->getVisibleSize();
    auto const origin = _director->getVisibleOrigin();
    screenTopY = origin.y + visibleSize.height;

    scheduleUpdate();
    return true;
}

void Bullet::update(float dt) {
    auto const curPosY = this->getPositionY();
    auto const newPosY = curPosY + speedY * dt;
    this->setPositionY(newPosY);

    if(newPosY >= screenTopY + halfSpriteHeight) {
        removeFromParentAndCleanup(true);
    }
}
