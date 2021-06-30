#include "HitMarkerFactory.h"

Sprite* HitMarkerFactory::makeStrongHitMarker() {
    return makeHitMarker(PATH_IMG_HIT_MARKER_STRONG);
}

Sprite* HitMarkerFactory::makeWeakHitMarker() {
    return makeHitMarker(PATH_IMG_HIT_MARKER_WEAK);
}

Sprite* HitMarkerFactory::makeHitMarker(std::string const &spritePath) {
    auto const sprite = Sprite::create(spritePath);
    sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

    sprite->setOpacity(0.0f);
    sprite->setScale(0.0f);

    // animation, also self destructs at the end
    {
        auto const fadeIn = FadeIn::create(HIT_MARKER_ANIM_DURATION);
        auto const fadeOut = FadeOut::create(HIT_MARKER_ANIM_DURATION);
        auto const fadeInOut = Sequence::create(fadeIn, fadeOut, NULL);
        auto const grow = ScaleTo::create(HIT_MARKER_ANIM_DURATION * 2, 2.0f);
        auto const animation = Spawn::create(fadeInOut, grow, NULL);
        auto const destroy = RemoveSelf::create(true);
        auto const final = Sequence::create(animation, destroy, NULL);

        sprite->runAction(final);
    }

    return sprite;
}
