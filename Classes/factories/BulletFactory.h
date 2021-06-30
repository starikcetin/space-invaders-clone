//
// Created by cetin on 28/06/2021.
//

#ifndef PROJ_ANDROID_BULLETFACTORY_H
#define PROJ_ANDROID_BULLETFACTORY_H


#include "cocos2d.h"
#include "Constants.h"
#include "gameObjects/Bullet.h"

using namespace cocos2d;

namespace BulletFactory {
    Bullet* makeStrongBullet();
    Bullet* makeWeakBullet();
    Bullet* makeBullet(std::string const &spritePath, float const damage);
}


#endif //PROJ_ANDROID_BULLETFACTORY_H
