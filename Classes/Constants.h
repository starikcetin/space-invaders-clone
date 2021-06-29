#ifndef PROJ_ANDROID_CONSTANTS_H
#define PROJ_ANDROID_CONSTANTS_H

//
// Font Paths
//

#define PATH_FONT_FUTURE_THIN   "fonts/kenvector_future_thin.ttf"

//
// Image Paths
//

#define PATH_IMG_AURA           "images/aura.png"
#define PATH_IMG_BG             "images/bg.png"
#define PATH_IMG_ENEMY_RED      "images/enemy_red.png"
#define PATH_IMG_ENEMY_BLACK    "images/enemy_black.png"
#define PATH_IMG_HIT_GREEN      "images/hit_green.png"
#define PATH_IMG_HIT_RED        "images/hit_red.png"
#define PATH_IMG_LASER_GREEN    "images/laser_green.png"
#define PATH_IMG_LASER_RED      "images/laser_red.png"
#define PATH_IMG_PLAYER         "images/player.png"
#define PATH_IMG_POWER_ICON     "images/power_icon.png"
//#define PATH_IMG_BUTTON         "images/button.png"
#define PATH_IMG_PLAY           "images/play.png"

//
// Sound Paths
//

#define PATH_SOUND_KILL         "sounds/kill.png"
#define PATH_SOUND_LOSE         "sounds/lose.png"
#define PATH_SOUND_POWER_DOWN   "sounds/power_down.png"
#define PATH_SOUND_POWER_UP     "sounds/power_up.png"

//
// Visual Params
//

#define PLAY_AREA_PADDING       10.0f
#define SHIP_CELL_SIZE          35.0f
#define HALF_SHIP_CELL_SIZE     SHIP_CELL_SIZE / 2.0f

//
// Gameplay Params
//

#define PLAYER_SPEED            50
#define PLAYER_RATE_OF_FIRE     3
#define BULLET_SPEED            200
#define NORMAL_BULLET_DAMAGE    25
#define POWER_BULLET_DAMAGE     100
#define KILL_STREAK_FOR_POWER   5
#define POWER_DURATION          3
#define ENEMY_SPEED             10
#define WEAK_ENEMY_HEALTH       50
#define STRONG_ENEMY_HEALTH     100

#endif //PROJ_ANDROID_CONSTANTS_H
