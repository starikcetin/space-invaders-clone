#ifndef PROJ_ANDROID_ENEMYFACTORY_H
#define PROJ_ANDROID_ENEMYFACTORY_H


#include "cocos2d.h"
#include "Constants.h"
#include "gameObjects/Enemy.h"

using namespace cocos2d;

namespace EnemyFactory {
    Enemy *makeStrongEnemy();

    Enemy *makeWeakEnemy();

    Enemy *makeEnemy(std::string const &spritePath, float const maxHealth);
}


#endif //PROJ_ANDROID_ENEMYFACTORY_H
