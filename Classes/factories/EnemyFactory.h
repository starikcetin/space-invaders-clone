#ifndef PROJ_ANDROID_ENEMYFACTORY_H
#define PROJ_ANDROID_ENEMYFACTORY_H


#include <gameObjects/Enemy.h>

namespace EnemyFactory {
    Enemy* makeStrongEnemy();
    Enemy* makeWeakEnemy();
    Enemy* makeEnemy(const std::string &spritePath, const float maxHealth);
}


#endif //PROJ_ANDROID_ENEMYFACTORY_H
