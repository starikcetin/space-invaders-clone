#include "EnemyFactory.h"

Enemy *EnemyFactory::makeStrongEnemy() {
    return makeEnemy(PATH_IMG_ENEMY_STRONG, ENEMY_STRONG_HEALTH, ENEMY_STRONG_SCORE);
}

Enemy *EnemyFactory::makeWeakEnemy() {
    return makeEnemy(PATH_IMG_ENEMY_WEAK, ENEMY_WEAK_HEALTH, ENEMY_WEAK_SCORE);
}

Enemy *EnemyFactory::makeEnemy(std::string const &spritePath, float const maxHealth, int const score) {
    auto const enemy = Enemy::create();
    enemy->setMaxHealth(maxHealth);
    enemy->setCurrentHealth(maxHealth);
    enemy->setScore(score);
    enemy->setSpeedY(ENEMY_SPEED);
    enemy->setTag(TAG_ENEMY);

    auto const sprite = Sprite::create(spritePath);
    sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    sprite->setPosition(Vec2::ZERO);
    enemy->addChild(sprite);

    auto const physicsBody = PhysicsBody::createBox(sprite->getContentSize());
    physicsBody->setDynamic(true);
    physicsBody->setCategoryBitmask(CATEGORY_MASK_ENEMY);
    physicsBody->setCollisionBitmask(COLLISION_MASK_ENEMY);
    physicsBody->setContactTestBitmask(COLLISION_MASK_ENEMY);
    enemy->setPhysicsBody(physicsBody);

    return enemy;
}
