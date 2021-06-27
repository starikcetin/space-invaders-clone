#ifndef PROJ_ANDROID_UTILS_H
#define PROJ_ANDROID_UTILS_H

#include "cocos2d.h"

using namespace cocos2d;

namespace Utils {
    void logLoadingError(const char* filename);
    Sprite* makeRepeatingBg(const std::string &path, const Vec2 &origin, const Size &visibleSize);
}


#endif //PROJ_ANDROID_UTILS_H
