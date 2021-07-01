#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "Constants.h"
#include "Utils.h"
#include "GameScene.h"

using namespace cocos2d;
using namespace ui;

class MainMenu : public cocos2d::Scene {
public:
    static cocos2d::Scene *createScene();
    virtual bool init();
    CREATE_FUNC(MainMenu);

private:
    void playButtonOnClick(Ref *const sender, Widget::TouchEventType const type);
};

#endif // __MAINMENU_SCENE_H__
