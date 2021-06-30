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

    void spawnBullet(float const dt);

private:
    Player *player;
    Vec2 playAreaMin, playAreaMax;

    bool onTouchBegan(Touch* const touch, Event* const event);
    void onTouchMoved(Touch* const touch, Event* const event);
    void onTouchEnded(Touch* const touch, Event* const event);
    bool onContactBegin(PhysicsContact const &contact);

    TouchState calculateTouchState(Vec2 const &touchLocation);
    static float calculatePlayerSpeedX(TouchState const &touchState);
    void makeGridOfEnemies(int const rows);
    void makeRowOfEnemies(float const posY, bool const isStrong);
    void handleBulletHit(Bullet* const bullet, Enemy* const enemy);
};

#endif // __GAME_SCENE_H__
