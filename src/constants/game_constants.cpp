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

// Base attack damage values
const int BASE_ATTACK1_DAMAGE = 10;
const int BASE_ATTACK2_DAMAGE = 15;
const int BASE_ATTACK3_DAMAGE = 20;
const int BASE_ATTACK4_DAMAGE = 30;

// Base energy costs
const int BASE_ATTACK1_ENERGY_COST = 10;
const int BASE_ATTACK2_ENERGY_COST = 20;
const int BASE_ATTACK3_ENERGY_COST = 30;
const int BASE_ATTACK4_ENERGY_COST = 50;

// Character stat scaling factors
const float BASE_DAMAGE_SCALING = 1.2f;   // 20% increase per level
const float BASE_HEALTH_SCALING = 1.3f;   // 30% increase per level
const float BASE_ENERGY_SCALING = 1.15f;  // 15% increase per level

// Fire Knight - High damage, high energy cost
const float FIRE_KNIGHT_DAMAGE_MOD = 1.3f;       // 30% more base damage
const float FIRE_KNIGHT_ENERGY_COST_MOD = 1.2f;  // 20% more energy cost
const float FIRE_KNIGHT_DAMAGE_SCALING = 1.25f;  // Better damage scaling
const float FIRE_KNIGHT_HEALTH_SCALING = 1.2f;   // Lower health scaling
const float FIRE_KNIGHT_ENERGY_SCALING = 1.1f;   // Lower energy scaling

// Ground Monk - Balanced stats
const float GROUND_MONK_DAMAGE_MOD = 1.1f;       // 10% more base damage
const float GROUND_MONK_ENERGY_COST_MOD = 1.0f;  // Standard energy cost
const float GROUND_MONK_DAMAGE_SCALING = 1.2f;   // Standard damage scaling
const float GROUND_MONK_HEALTH_SCALING = 1.3f;   // Standard health scaling
const float GROUND_MONK_ENERGY_SCALING = 1.15f;  // Standard energy scaling

// Water Priestess - Lower damage, efficient energy
const float WATER_PRIESTESS_DAMAGE_MOD = 0.9f;       // 10% less base damage
const float WATER_PRIESTESS_ENERGY_COST_MOD = 0.8f;  // 20% less energy cost
const float WATER_PRIESTESS_DAMAGE_SCALING = 1.15f;  // Lower damage scaling
const float WATER_PRIESTESS_HEALTH_SCALING = 1.3f;   // Standard health scaling
const float WATER_PRIESTESS_ENERGY_SCALING = 1.2f;   // Better energy scaling
}  // namespace constants