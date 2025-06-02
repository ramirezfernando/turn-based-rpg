#pragma once

namespace constants {
extern const int FRAME_DELAY;
extern const int WINDOW_SIZE;
extern const int TEXT_BOX_WIDTH;
extern const int TEXT_BOX_HEIGHT;
extern const int TEXT_BOX_X_POS;
extern const int TEXT_BOX_Y_POS;
extern const int CHARACTER_WIDTH;
extern const int CHARACTER_HEIGHT;
extern const int CHARACTER_PLAYER_X_POS;
extern const int CHARACTER_PLAYER_Y_POS;
extern const int CHARACTER_ENEMY_X_POS;
extern const int CHARACTER_ENEMY_Y_POS;

// Base attack damage values
extern const int BASE_ATTACK1_DAMAGE;
extern const int BASE_ATTACK2_DAMAGE;
extern const int BASE_ATTACK3_DAMAGE;
extern const int BASE_ATTACK4_DAMAGE;

// Base energy costs
extern const int BASE_ATTACK1_ENERGY_COST;
extern const int BASE_ATTACK2_ENERGY_COST;
extern const int BASE_ATTACK3_ENERGY_COST;
extern const int BASE_ATTACK4_ENERGY_COST;

// Character stat scaling factors
extern const float BASE_DAMAGE_SCALING;
extern const float BASE_HEALTH_SCALING;
extern const float BASE_ENERGY_SCALING;

// Character type specific modifiers
extern const float FIRE_KNIGHT_DAMAGE_MOD;
extern const float FIRE_KNIGHT_ENERGY_COST_MOD;
extern const float FIRE_KNIGHT_DAMAGE_SCALING;
extern const float FIRE_KNIGHT_HEALTH_SCALING;
extern const float FIRE_KNIGHT_ENERGY_SCALING;

extern const float GROUND_MONK_DAMAGE_MOD;
extern const float GROUND_MONK_ENERGY_COST_MOD;
extern const float GROUND_MONK_DAMAGE_SCALING;
extern const float GROUND_MONK_HEALTH_SCALING;
extern const float GROUND_MONK_ENERGY_SCALING;

extern const float WATER_PRIESTESS_DAMAGE_MOD;
extern const float WATER_PRIESTESS_ENERGY_COST_MOD;
extern const float WATER_PRIESTESS_DAMAGE_SCALING;
extern const float WATER_PRIESTESS_HEALTH_SCALING;
extern const float WATER_PRIESTESS_ENERGY_SCALING;
}  // namespace constants