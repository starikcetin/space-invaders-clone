#ifndef PROJ_ANDROID_PLAYER_H
#define PROJ_ANDROID_PLAYER_H

#include "cocos2d.h"
#include "Constants.h"

using namespace cocos2d;

class Player : public Node {
public:
    CREATE_FUNC(Player);
    virtual bool init() override;
    virtual void update(float) override;

    void resetPosition();

private:
    Sprite *sprite;

    float calculateNewXWithinLimits(const float deltaX);

CC_SYNTHESIZE(float, speedX, SpeedX);
CC_SYNTHESIZE(float, limitMinX, LimitMinX);
CC_SYNTHESIZE(float, limitMaxX, LimitMaxX);
};


#endif //PROJ_ANDROID_PLAYER_H
