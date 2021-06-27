#include "MainMenuScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    return true;
}
