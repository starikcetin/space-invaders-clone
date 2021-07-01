#ifndef PROJ_ANDROID_UTILS_H
#define PROJ_ANDROID_UTILS_H


#include "cocos2d.h"

using namespace cocos2d;

namespace Utils {
    void logLoadingError(char *const filename);
    Sprite *makeRepeatingBg(std::string const &path, Vec2 const &origin, Size const &visibleSize);
}


#endif //PROJ_ANDROID_UTILS_H
