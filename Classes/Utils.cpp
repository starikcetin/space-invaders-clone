#include "Utils.h"

void Utils::logLoadingError(const char* filename)
{
    CCLOG("Error while loading: %s\n", filename);
}

Sprite* Utils::makeRepeatingBg(const std::string &path, const Vec2 &origin, const Size &visibleSize)
{
    Texture2D::TexParams texParams;
    texParams.magFilter = backend::SamplerFilter::LINEAR;
    texParams.minFilter = backend::SamplerFilter::LINEAR;
    texParams.sAddressMode = backend::SamplerAddressMode::REPEAT;
    texParams.tAddressMode = backend::SamplerAddressMode::REPEAT;

    Sprite* sprite = Sprite::create(path, {0,0,visibleSize.width, visibleSize.height});
    sprite->getTexture()->setTexParameters(texParams);
    sprite->setAnchorPoint(Vec2::ZERO);
    sprite->setPosition(origin);

    return sprite;
}
