#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Constants.h"
#include "Utils.h"

class Game : public cocos2d::Scene
{
public:
    enum TouchState { UP, LEFT, RIGHT };

    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(Game);

    void update(float) override;

private:
    Sprite* player;
    Vec2 playerVelocity;

    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);

    TouchState calculateTouchState(const Vec2 touchLocation);
    Vec2 calculatePlayerVelocity(const TouchState touchState);
};

#endif // __GAME_SCENE_H__
