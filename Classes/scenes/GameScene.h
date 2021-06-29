#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Constants.h"
#include "Utils.h"
#include "gameObjects/Player.h"
#include "gameObjects/Enemy.h"
#include "factories/EnemyFactory.h"
#include "factories/BulletFactory.h"

class Game : public cocos2d::Scene
{
public:
    enum TouchState { NONE, LEFT, RIGHT };

    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(Game);

    void spawnBullet(float dt);

private:
    Player *player;
    Vec2 playAreaMin, playAreaMax;

    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);

    TouchState calculateTouchState(const Vec2 touchLocation);
    static float calculatePlayerSpeedX(const TouchState touchState);
    void makeGridOfEnemies(const int rows);
    void makeRowOfEnemies(const float posY, const bool isStrong);
};

#endif // __GAME_SCENE_H__
