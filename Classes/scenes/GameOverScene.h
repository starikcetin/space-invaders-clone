#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__


#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "Constants.h"
#include "Utils.h"
#include "GameOverData.h"
#include "GameScene.h"

using namespace ui;

class GameOver : public cocos2d::Scene {
public:
    static GameOver *create(GameOverData const &data);

    virtual bool init() override;

private:
    GameOverData const &gameOverData;

    GameOver(GameOverData const &data);

    void playButtonOnClick(Ref *const sender, const Widget::TouchEventType type);
};


#endif // __GAMEOVER_SCENE_H__
