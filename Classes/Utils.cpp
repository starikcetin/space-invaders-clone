#include "Utils.h"

void Utils::logLoadingError(char *const filename) {
    CCLOG("Error while loading: %s\n", filename);
}

// repeats the given image so that it tiles the given area
Sprite *Utils::makeRepeatingBg(std::string const &path, Vec2 const &origin, Size const &visibleSize) {
    Texture2D::TexParams texParams;
    texParams.magFilter = backend::SamplerFilter::LINEAR;
    texParams.minFilter = backend::SamplerFilter::LINEAR;
    texParams.sAddressMode = backend::SamplerAddressMode::REPEAT;
    texParams.tAddressMode = backend::SamplerAddressMode::REPEAT;

    Sprite *sprite = Sprite::create(path, {0, 0, visibleSize.width, visibleSize.height});
    sprite->getTexture()->setTexParameters(texParams);
    sprite->setAnchorPoint(Vec2::ZERO);
    sprite->setPosition(origin);

    return sprite;
}
