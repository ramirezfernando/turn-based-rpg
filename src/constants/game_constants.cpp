#include "game_constants.h"

namespace constants {
const int FRAME_DELAY =
    1000 / 30;  // The number of milliseconds in a second divided by FPS
const int WINDOW_SIZE = 736;      // The size of the GUI window (736 x 736)
const int TEXT_BOX_WIDTH = 700;   // The width of the text box (640 pixels)
const int TEXT_BOX_HEIGHT = 154;  // The height of the text box (128 pixels)
const int TEXT_BOX_X_POS = 20;    // The x position of the text box (20 pixels)
const int TEXT_BOX_Y_POS = 550;   // The y position of the text box (550 pixels)
const int CHARACTER_WIDTH = 320;  // The width of the character (320 pixels)
const int CHARACTER_HEIGHT = 220;  // The height of the character (220 pixels)
const int CHARACTER_PLAYER_X_POS =
    -80;  // The x position of the character (100 pixels)
const int CHARACTER_PLAYER_Y_POS =
    50;  // The y position of the character (20 pixels)
const int CHARACTER_ENEMY_X_POS =
    200;  // The x position of the enemy character (200 pixels)
const int CHARACTER_ENEMY_Y_POS =
    50;  // The y position of the enemy character (20 pixels)

// Fire Knight - High damage, high energy cost
const int FIRE_KNIGHT_ATTACK_1_DAMAGE = 10;
const int FIRE_KNIGHT_ATTACK_2_DAMAGE = 15;
const int FIRE_KNIGHT_ATTACK_3_DAMAGE = 20;
const int FIRE_KNIGHT_ATTACK_4_DAMAGE = 30;
const int FIRE_KNIGHT_ATTACK_1_ENERGY_COST = 15;
const int FIRE_KNIGHT_ATTACK_2_ENERGY_COST = 20;
const int FIRE_KNIGHT_ATTACK_3_ENERGY_COST = 25;
const int FIRE_KNIGHT_ATTACK_4_ENERGY_COST = 40;

// Ground Monk - Balanced stats
const int GROUND_MONK_ATTACK_1_DAMAGE = 8;
const int GROUND_MONK_ATTACK_2_DAMAGE = 12;
const int GROUND_MONK_ATTACK_3_DAMAGE = 16;
const int GROUND_MONK_ATTACK_4_DAMAGE = 24;
const int GROUND_MONK_ATTACK_1_ENERGY_COST = 10;
const int GROUND_MONK_ATTACK_2_ENERGY_COST = 15;
const int GROUND_MONK_ATTACK_3_ENERGY_COST = 20;
const int GROUND_MONK_ATTACK_4_ENERGY_COST = 30;

// Water Priestess - Lower damage, efficient energy
const int WATER_PRIESTESS_ATTACK_1_DAMAGE = 6;
const int WATER_PRIESTESS_ATTACK_2_DAMAGE = 10;
const int WATER_PRIESTESS_ATTACK_3_DAMAGE = 14;
const int WATER_PRIESTESS_ATTACK_4_DAMAGE = 20;
const int WATER_PRIESTESS_ATTACK_1_ENERGY_COST = 8;
const int WATER_PRIESTESS_ATTACK_2_ENERGY_COST = 12;
const int WATER_PRIESTESS_ATTACK_3_ENERGY_COST = 16;
const int WATER_PRIESTESS_ATTACK_4_ENERGY_COST = 24;
}  // namespace constants