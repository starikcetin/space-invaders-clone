#include "GameOverScene.h"

USING_NS_CC;

GameOver *GameOver::create(GameOverData const &data) {
    auto *pRet = new(std::nothrow)GameOver(data);

    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }

    delete pRet;
    pRet = nullptr;
    return nullptr;
}

GameOver::GameOver(GameOverData const &data): gameOverData(data) {}

bool GameOver::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin = _director->getVisibleOrigin();
    auto xMiddle = origin.x + visibleSize.width / 2.0f;

    auto background = Utils::makeRepeatingBg(PATH_IMG_BG, origin, visibleSize);
    addChild(background);

    auto const titleText = gameOverData.isVictory ? "VICTORY" : "DEFEAT";
    auto const scoreText = "SCORE: " + std::to_string(gameOverData.score);

    auto title = Label::createWithTTF(titleText, PATH_FONT_FUTURE_THIN, 20);
    title->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 80 / 100));
    addChild(title);

    auto score = Label::createWithTTF(scoreText, PATH_FONT_FUTURE_THIN, 10);
    score->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 70 / 100));
    addChild(score);

    auto playButton = Button::create(PATH_IMG_PLAY, PATH_IMG_PLAY);
    playButton->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 35 / 100));
    playButton->addTouchEventListener(CC_CALLBACK_2(GameOver::playButtonOnClick, this));
    addChild(playButton);

    return true;
}

void GameOver::playButtonOnClick(Ref *const sender, Widget::TouchEventType const type) {
    auto gameScene = Game::createScene();
    _director->replaceScene(TransitionFade::create(0.25f, gameScene, TRANSITION_FADE_COLOR));
}
