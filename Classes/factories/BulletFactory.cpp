//
// Created by cetin on 28/06/2021.
//

#include "BulletFactory.h"

Bullet* BulletFactory::makeStrongBullet() {
    return makeBullet(PATH_IMG_BULLET_STRONG, BULLET_STRONG_DAMAGE);
}

Bullet* BulletFactory::makeWeakBullet() {
    return makeBullet(PATH_IMG_BULLET_WEAK, BULLET_WEAK_DAMAGE);
}

Bullet* BulletFactory::makeBullet(const std::string &spritePath, const float damage) {
    const auto newBullet = Bullet::create();
    newBullet->setDamage(damage);
    newBullet->setSpeedY(BULLET_SPEED);

    const auto newBulletSprite = Sprite::create(spritePath);
    newBulletSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    newBulletSprite->setPosition(Vec2::ZERO);
    newBullet->addChild(newBulletSprite);

    return newBullet;
}
