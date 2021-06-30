#ifndef PROJ_ANDROID_ENEMY_H
#define PROJ_ANDROID_ENEMY_H


#include "cocos2d.h"
#include "Constants.h"

using namespace cocos2d;

class Enemy : public Node {
public:
    CREATE_FUNC(Enemy);
    virtual bool init() override;
    virtual void update(float) override;

    void takeDamage(float const amount);

CC_SYNTHESIZE(float, maxHealth, MaxHealth);
CC_SYNTHESIZE(float, currentHealth, CurrentHealth);
CC_SYNTHESIZE(float, speedY, SpeedY);
};


#endif //PROJ_ANDROID_ENEMY_H
