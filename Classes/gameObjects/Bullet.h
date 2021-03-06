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

private:
    float screenTopY;

CC_SYNTHESIZE(float, damage, Damage);
CC_SYNTHESIZE(float, speedY, SpeedY);
CC_SYNTHESIZE(bool, isStrong, IsStrong);
CC_SYNTHESIZE(float, halfSpriteHeight, HalfSpriteHeight);
};


#endif //PROJ_ANDROID_BULLET_H
