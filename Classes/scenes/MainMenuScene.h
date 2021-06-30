#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "Constants.h"
#include "Utils.h"
#include "GameScene.h"

using namespace ui;

class MainMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

private:
    void playButtonOnClick(Ref* const sender, Widget::TouchEventType const type);

    CREATE_FUNC(MainMenu);
};

#endif // __MAINMENU_SCENE_H__
