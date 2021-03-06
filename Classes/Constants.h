#ifndef PROJ_ANDROID_CONSTANTS_H
#define PROJ_ANDROID_CONSTANTS_H


//
// Font Paths
//

#define PATH_FONT_FUTURE_THIN   "fonts/kenvector_future_thin.ttf"

//
// Image Paths
//

#define PATH_IMG_AURA               "images/aura.png"
#define PATH_IMG_BG                 "images/bg.png"
#define PATH_IMG_ENEMY_STRONG       "images/enemy_strong.png"
#define PATH_IMG_ENEMY_WEAK         "images/enemy_weak.png"
#define PATH_IMG_HIT_MARKER_STRONG  "images/hit_green.png"
#define PATH_IMG_HIT_MARKER_WEAK    "images/hit_red.png"
#define PATH_IMG_BULLET_STRONG      "images/bullet_green.png"
#define PATH_IMG_BULLET_WEAK        "images/bullet_red.png"
#define PATH_IMG_PLAYER             "images/player.png"
#define PATH_IMG_PLAY               "images/play.png"

//
// Sound Paths
//

#define PATH_SOUND_FIRE_WEAK    "sounds/fire_weak.ogg"
#define PATH_SOUND_FIRE_STRONG  "sounds/fire_strong.ogg"
#define PATH_SOUND_KILL         "sounds/kill.ogg"
#define PATH_SOUND_LOSE         "sounds/lose.ogg"
#define PATH_SOUND_WIN          "sounds/win.ogg"
#define PATH_SOUND_POWER_DOWN   "sounds/power_down.ogg"
#define PATH_SOUND_POWER_UP     "sounds/power_up.ogg"

//
// Visual Params
//

#define PLAY_AREA_EXTRA_TOP_PADDING 15.0f
#define PLAY_AREA_PADDING           10.0f
#define SHIP_CELL_SIZE              35.0f
#define HALF_SHIP_CELL_SIZE         SHIP_CELL_SIZE / 2.0f
#define HIT_MARKER_ANIM_DURATION    0.1f
#define AURA_FADE_DURATION          0.25f
#define TRANSITION_FADE_COLOR       Color3B(94,63,107)  // bright purple (main color in bg image)

//
// Gameplay Params
//

#define TAG_PLAYER              0
#define TAG_ENEMY               1
#define TAG_BULLET              2

#define PLAYER_SPEED            50.0f
#define PLAYER_RATE_OF_FIRE     3.0f
#define POWER_DURATION          3.0f
#define KILL_STREAK_FOR_POWER   5

#define BULLET_SPEED            200.0f
#define BULLET_WEAK_DAMAGE      25.0f
#define BULLET_STRONG_DAMAGE    100.0f

#define ENEMY_SPEED             10.0f
#define ENEMY_WEAK_HEALTH       50.0f
#define ENEMY_STRONG_HEALTH     100.0f
#define ENEMY_WEAK_SCORE        5
#define ENEMY_STRONG_SCORE      10

//
// Physics Params
//

// category mask describes identity
#define CATEGORY_MASK_BULLET    1u << 0u
#define CATEGORY_MASK_ENEMY     1u << 1u

// collision mask describes which categories it can collide with
#define COLLISION_MASK_BULLET   CATEGORY_MASK_ENEMY
#define COLLISION_MASK_ENEMY    CATEGORY_MASK_BULLET

//
// Indirection
//

#define EVENT_ENEMY_PASSED_FINISH  "eEnemyPassedFinish"


#endif //PROJ_ANDROID_CONSTANTS_H
