#include "Enemy.h"

bool Enemy::init() {
    scheduleUpdate();
    return true;
}

void Enemy::update(float dt) {
    const auto curPosY = this->getPositionY();
    const auto newPosY = curPosY - speedY * dt;
    this->setPositionY(newPosY);
}
