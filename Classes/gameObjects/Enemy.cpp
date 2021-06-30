#include "Enemy.h"

bool Enemy::init() {
    scheduleUpdate();
    return true;
}

void Enemy::update(float const dt) {
    auto const curPosY = this->getPositionY();
    auto const newPosY = curPosY - speedY * dt;
    this->setPositionY(newPosY);

    if(newPosY <= finishLineY) {
        // game over, emit event
    }
}

void Enemy::takeDamage(float const amount) {
    auto const newHealth = std::max(currentHealth - amount, 0.0f);
    setCurrentHealth(newHealth);
}

bool Enemy::isDead() const {
    return currentHealth < 0.01f;
}
