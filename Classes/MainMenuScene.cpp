#include "MainMenuScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

bool MainMenu::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin = _director->getVisibleOrigin();

    auto sprite_bg = Utils::makeRepeatingBg(PATH_IMG_BG, origin, visibleSize);
    addChild(sprite_bg);

    auto label_title = Label::createWithTTF("SPACE INVADERS", PATH_FONT_FUTURE_THIN, 20);
    label_title->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 80 / 100));
    addChild(label_title);

    auto label_subtitle = Label::createWithTTF("S. TARIK ÇETIN", PATH_FONT_FUTURE_THIN, 10);
    label_subtitle->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 70 / 100));
    addChild(label_subtitle);

    auto button_play = Button::create(PATH_IMG_PLAY, PATH_IMG_PLAY);
    button_play->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y  + visibleSize.height * 35 / 100));
    addChild(button_play);

    return true;
}
