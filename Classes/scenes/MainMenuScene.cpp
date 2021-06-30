#include "MainMenuScene.h"

USING_NS_CC;

Scene *MainMenu::createScene() {
    return MainMenu::create();
}

bool MainMenu::init() {
    if (!Scene::init()) {
        return false;
    }

    auto const visibleSize = _director->getVisibleSize();
    auto const origin = _director->getVisibleOrigin();
    auto const xMiddle = origin.x + visibleSize.width / 2.0f;

    auto const sprite_bg = Utils::makeRepeatingBg(PATH_IMG_BG, origin, visibleSize);
    addChild(sprite_bg);

    auto const label_title = Label::createWithTTF("SPACE INVADERS", PATH_FONT_FUTURE_THIN, 20);
    label_title->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 80 / 100));
    addChild(label_title);

    auto const label_subtitle = Label::createWithTTF("S. TARIK ÇETIN", PATH_FONT_FUTURE_THIN, 10);
    label_subtitle->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 70 / 100));
    addChild(label_subtitle);

    auto const button_play = Button::create(PATH_IMG_PLAY, PATH_IMG_PLAY);
    button_play->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 35 / 100));
    button_play->addTouchEventListener(CC_CALLBACK_2(MainMenu::playButtonOnClick, this));
    addChild(button_play);

    return true;
}

void MainMenu::playButtonOnClick(Ref *const sender, Widget::TouchEventType const type) {
    auto const gameScene = Game::createScene();
    _director->replaceScene(TransitionFade::create(0.25f, gameScene, TRANSITION_FADE_COLOR));
}
