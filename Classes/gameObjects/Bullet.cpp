#include "Bullet.h"

bool Bullet::init() {
    scheduleUpdate();
    return true;
}

void Bullet::update(float dt) {
    auto const curPosY = this->getPositionY();
    auto const newPosY = curPosY + speedY * dt;
    this->setPositionY(newPosY);
}
