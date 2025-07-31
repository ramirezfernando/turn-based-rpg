#include "game_constants.h"
#include <string>

namespace constants {
const int FRAME_DELAY =
    1000 / 30;  // The number of milliseconds in a second divided by FPS
const int WINDOW_SIZE = 736;      // The size of the GUI window (736 x 736)
const int TEXT_BOX_WIDTH = 700;   // The width of the text box (640 pixels)
const int TEXT_BOX_HEIGHT = 154;  // The height of the text box (128 pixels)
const int TEXT_BOX_X_POS = 20;    // The x position of the text box (20 pixels)
const int TEXT_BOX_Y_POS = 550;   // The y position of the text box (550 pixels)
const int FONT_SIZE = 10;  // The font size used in the text box (12 pixels)
const int CHARACTER_WIDTH = 320;   // The width of the character (320 pixels)
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
const std::string FIRE_KNIGHT_CHARACTER_TYPE_STRING = "FIRE_KNIGHT";
const int FIRE_KNIGHT_ATTACK_1_DAMAGE = 12;
const int FIRE_KNIGHT_ATTACK_2_DAMAGE = 18;
const int FIRE_KNIGHT_ATTACK_3_DAMAGE = 25;
const int FIRE_KNIGHT_ATTACK_4_DAMAGE = 35;
const int FIRE_KNIGHT_ATTACK_1_ENERGY_COST = 18;
const int FIRE_KNIGHT_ATTACK_2_ENERGY_COST = 25;
const int FIRE_KNIGHT_ATTACK_3_ENERGY_COST = 35;
const int FIRE_KNIGHT_ATTACK_4_ENERGY_COST = 50;

// Ground Monk - Balanced stats
const std::string GROUND_MONK_CHARACTER_TYPE_STRING = "GROUND_MONK";
const int GROUND_MONK_ATTACK_1_DAMAGE = 9;
const int GROUND_MONK_ATTACK_2_DAMAGE = 14;
const int GROUND_MONK_ATTACK_3_DAMAGE = 19;
const int GROUND_MONK_ATTACK_4_DAMAGE = 28;
const int GROUND_MONK_ATTACK_1_ENERGY_COST = 12;
const int GROUND_MONK_ATTACK_2_ENERGY_COST = 18;
const int GROUND_MONK_ATTACK_3_ENERGY_COST = 25;
const int GROUND_MONK_ATTACK_4_ENERGY_COST = 38;

// Water Priestess - Lower damage, efficient energy
const std::string WATER_PRIESTESS_CHARACTER_TYPE_STRING = "WATER_PRIESTESS";
const int WATER_PRIESTESS_ATTACK_1_DAMAGE = 7;
const int WATER_PRIESTESS_ATTACK_2_DAMAGE = 11;
const int WATER_PRIESTESS_ATTACK_3_DAMAGE = 16;
const int WATER_PRIESTESS_ATTACK_4_DAMAGE = 22;
const int WATER_PRIESTESS_ATTACK_1_ENERGY_COST = 9;
const int WATER_PRIESTESS_ATTACK_2_ENERGY_COST = 14;
const int WATER_PRIESTESS_ATTACK_3_ENERGY_COST = 19;
const int WATER_PRIESTESS_ATTACK_4_ENERGY_COST = 28;
}  // namespace constants