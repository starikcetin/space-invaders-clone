#include "EnemyFactory.h"

Enemy* EnemyFactory::makeStrongEnemy() {
    return makeEnemy(PATH_IMG_ENEMY_STRONG, ENEMY_STRONG_HEALTH);
}

Enemy* EnemyFactory::makeWeakEnemy() {
    return makeEnemy(PATH_IMG_ENEMY_WEAK, ENEMY_WEAK_HEALTH);
}

Enemy* EnemyFactory::makeEnemy(const std::string &spritePath, const float maxHealth) {
    const auto newEnemy = Enemy::create();
    newEnemy->setMaxHealth(maxHealth);
    newEnemy->setCurrentHealth(maxHealth);
    newEnemy->setSpeedY(ENEMY_SPEED);

    const auto newEnemySprite = Sprite::create(spritePath);
    newEnemySprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    newEnemySprite->setPosition(Vec2::ZERO);
    newEnemy->addChild(newEnemySprite);

    return newEnemy;
}
