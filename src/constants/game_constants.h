#pragma once

#include <string>

// Constant values used throughout the game.
namespace constants {
extern const int FRAME_DELAY;
extern const int WINDOW_SIZE;

extern const int TEXT_BOX_WIDTH;
extern const int TEXT_BOX_HEIGHT;
extern const int TEXT_BOX_X_POS;
extern const int TEXT_BOX_Y_POS;
extern const int FONT_SIZE;
extern const int CHARACTER_WIDTH;
extern const int CHARACTER_HEIGHT;
extern const int CHARACTER_PLAYER_X_POS;
extern const int CHARACTER_PLAYER_Y_POS;
extern const int CHARACTER_ENEMY_X_POS;
extern const int CHARACTER_ENEMY_Y_POS;

enum class AttackType {
  ATTACK1,
  ATTACK2,
  ATTACK3,
  ATTACK4,
};

extern const std::string FIRE_KNIGHT_CHARACTER_TYPE_STRING;
extern const int FIRE_KNIGHT_ATTACK_1_DAMAGE;
extern const int FIRE_KNIGHT_ATTACK_2_DAMAGE;
extern const int FIRE_KNIGHT_ATTACK_3_DAMAGE;
extern const int FIRE_KNIGHT_ATTACK_4_DAMAGE;
extern const int FIRE_KNIGHT_ATTACK_1_ENERGY_COST;
extern const int FIRE_KNIGHT_ATTACK_2_ENERGY_COST;
extern const int FIRE_KNIGHT_ATTACK_3_ENERGY_COST;
extern const int FIRE_KNIGHT_ATTACK_4_ENERGY_COST;

extern const std::string GROUND_MONK_CHARACTER_TYPE_STRING;
extern const int GROUND_MONK_ATTACK_1_DAMAGE;
extern const int GROUND_MONK_ATTACK_2_DAMAGE;
extern const int GROUND_MONK_ATTACK_3_DAMAGE;
extern const int GROUND_MONK_ATTACK_4_DAMAGE;
extern const int GROUND_MONK_ATTACK_1_ENERGY_COST;
extern const int GROUND_MONK_ATTACK_2_ENERGY_COST;
extern const int GROUND_MONK_ATTACK_3_ENERGY_COST;
extern const int GROUND_MONK_ATTACK_4_ENERGY_COST;

extern const std::string WATER_PRIESTESS_CHARACTER_TYPE_STRING;
extern const int WATER_PRIESTESS_ATTACK_1_DAMAGE;
extern const int WATER_PRIESTESS_ATTACK_2_DAMAGE;
extern const int WATER_PRIESTESS_ATTACK_3_DAMAGE;
extern const int WATER_PRIESTESS_ATTACK_4_DAMAGE;
extern const int WATER_PRIESTESS_ATTACK_1_ENERGY_COST;
extern const int WATER_PRIESTESS_ATTACK_2_ENERGY_COST;
extern const int WATER_PRIESTESS_ATTACK_3_ENERGY_COST;
extern const int WATER_PRIESTESS_ATTACK_4_ENERGY_COST;
}  // namespace constants