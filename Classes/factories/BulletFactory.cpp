#include "BulletFactory.h"

Bullet *BulletFactory::makeStrongBullet() {
    return makeBullet(PATH_IMG_BULLET_STRONG, BULLET_STRONG_DAMAGE, true);
}

Bullet *BulletFactory::makeWeakBullet() {
    return makeBullet(PATH_IMG_BULLET_WEAK, BULLET_WEAK_DAMAGE, false);
}

Bullet *BulletFactory::makeBullet(std::string const &spritePath, float const damage, bool const isStrong) {
    auto const sprite = Sprite::create(spritePath);
    sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    sprite->setPosition(Vec2::ZERO);

    auto const physicsBody = PhysicsBody::createBox(sprite->getContentSize());
    physicsBody->setDynamic(true);
    physicsBody->setCategoryBitmask(CATEGORY_MASK_BULLET);
    physicsBody->setCollisionBitmask(COLLISION_MASK_BULLET);
    physicsBody->setContactTestBitmask(COLLISION_MASK_BULLET);

    auto const bullet = Bullet::create();
    bullet->setDamage(damage);
    bullet->setSpeedY(BULLET_SPEED);
    bullet->setTag(TAG_BULLET);
    bullet->setIsStrong(isStrong);

    bullet->addChild(sprite);
    bullet->setPhysicsBody(physicsBody);
    bullet->setHalfSpriteHeight(sprite->getContentSize().height / 2.0f);

    return bullet;
}
