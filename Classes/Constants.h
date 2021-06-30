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
#define PATH_IMG_ENEMY_STRONG   "images/enemy_orange.png"
#define PATH_IMG_ENEMY_WEAK     "images/enemy_black.png"
#define PATH_IMG_HIT_STRONG     "images/hit_green.png"
#define PATH_IMG_HIT_WEAK       "images/hit_red.png"
#define PATH_IMG_BULLET_STRONG  "images/bullet_green.png"
#define PATH_IMG_BULLET_WEAK    "images/bullet_red.png"
#define PATH_IMG_PLAYER         "images/player.png"
#define PATH_IMG_POWER_ICON     "images/power_icon.png"
#define PATH_IMG_BUTTON         "images/button.png"
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

//
// Physics Params
//

#define DUMMY_PHYSICS_BODY      PhysicsMaterial(0.0f, 0.0f, 0.0f)

// category mask describes identity
#define CATEGORY_MASK_BULLET    1u << 0u
#define CATEGORY_MASK_ENEMY     1u << 1u

// collision mask describes which categories it can collide with
#define COLLISION_MASK_BULLET   CATEGORY_MASK_ENEMY
#define COLLISION_MASK_ENEMY    CATEGORY_MASK_BULLET


#endif //PROJ_ANDROID_CONSTANTS_H
