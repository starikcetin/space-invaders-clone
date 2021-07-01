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

GameOver::GameOver(GameOverData const &data) : gameOverData(data) {}

bool GameOver::init() {
    if (!Scene::init()) {
        return false;
    }

    auto const visibleSize = _director->getVisibleSize();
    auto const origin = _director->getVisibleOrigin();
    auto const xMiddle = origin.x + visibleSize.width / 2.0f;

    auto const background = Utils::makeRepeatingBg(PATH_IMG_BG, origin, visibleSize);
    addChild(background);

    auto const titleText = gameOverData.isVictory ? "VICTORY" : "DEFEAT";
    auto const scoreText = "SCORE: " + std::to_string(gameOverData.score);

    auto const title = Label::createWithTTF(titleText, PATH_FONT_FUTURE_THIN, 20);
    title->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 80 / 100));
    addChild(title);

    auto const score = Label::createWithTTF(scoreText, PATH_FONT_FUTURE_THIN, 10);
    score->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 70 / 100));
    addChild(score);

    auto const playButton = Button::create(PATH_IMG_PLAY, PATH_IMG_PLAY);
    playButton->setPosition(Vec2(xMiddle, origin.y + visibleSize.height * 35 / 100));
    playButton->addTouchEventListener(CC_CALLBACK_2(GameOver::playButtonOnClick, this));
    addChild(playButton);

    auto const sound = gameOverData.isVictory ? PATH_SOUND_WIN : PATH_SOUND_LOSE;
    AudioEngine::play2d(sound);

    return true;
}

void GameOver::playButtonOnClick(Ref *const sender, Widget::TouchEventType const type) {
    auto gameScene = Game::createScene();
    _director->replaceScene(TransitionFade::create(0.25f, gameScene, TRANSITION_FADE_COLOR));
}
