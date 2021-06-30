#ifndef PROJ_ANDROID_HITMARKERFACTORY_H
#define PROJ_ANDROID_HITMARKERFACTORY_H


#include "cocos2d.h"
#include "Constants.h"

using namespace cocos2d;

namespace HitMarkerFactory {
    Sprite* makeStrongHitMarker();
    Sprite* makeWeakHitMarker();
    Sprite* makeHitMarker(std::string const &spritePath);
}


#endif //PROJ_ANDROID_HITMARKERFACTORY_H
