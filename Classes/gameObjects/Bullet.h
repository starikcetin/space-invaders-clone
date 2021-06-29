//
// Created by cetin on 28/06/2021.
//

#ifndef PROJ_ANDROID_BULLET_H
#define PROJ_ANDROID_BULLET_H


#include "cocos2d.h"
#include "Constants.h"

using namespace cocos2d;

class Bullet : public Node {
public:
    CREATE_FUNC(Bullet);
    virtual bool init() override;
    virtual void update(float) override;

CC_SYNTHESIZE(float, damage, Damage);
CC_SYNTHESIZE(float, speedY, SpeedY);
};


#endif //PROJ_ANDROID_BULLET_H
