#include "ground_monk.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

GroundMonk::GroundMonk(bool is_enemy) {
  SetTexture(constants::GROUND_MONK_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_IDLE_NUM_FRAMES);
  SetCount(1);
  SetLevel(1);
  SetHealth(100);
  SetEnergy(100);
  SetAttack1Damage(constants::GROUND_MONK_ATTACK_1_DAMAGE);
  SetAttack2Damage(constants::GROUND_MONK_ATTACK_2_DAMAGE);
  SetAttack3Damage(constants::GROUND_MONK_ATTACK_3_DAMAGE);
  SetAttack4Damage(constants::GROUND_MONK_ATTACK_4_DAMAGE);
  SetAttack1EnergyCost(constants::GROUND_MONK_ATTACK_1_ENERGY_COST);
  SetAttack2EnergyCost(constants::GROUND_MONK_ATTACK_2_ENERGY_COST);
  SetAttack3EnergyCost(constants::GROUND_MONK_ATTACK_3_ENERGY_COST);
  SetAttack4EnergyCost(constants::GROUND_MONK_ATTACK_4_ENERGY_COST);

  if (is_enemy) {
    SetEnemy(is_enemy);
    SetXPos(constants::CHARACTER_ENEMY_X_POS);
    SetYPos(constants::CHARACTER_ENEMY_Y_POS);
  } else {
    SetXPos(constants::CHARACTER_PLAYER_X_POS);
    SetYPos(constants::CHARACTER_PLAYER_Y_POS);
  }
}

void GroundMonk::Attack1() {
  SetTexture(constants::GROUND_MONK_ATTACK_1_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_1_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_ATTACK_1_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack1_energy_cost_;
}

void GroundMonk::Attack2() {
  SetTexture(constants::GROUND_MONK_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_2_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_ATTACK_2_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack2_energy_cost_;
}

void GroundMonk::Attack3() {
  SetTexture(constants::GROUND_MONK_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_3_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_ATTACK_3_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack3_energy_cost_;
}

void GroundMonk::Attack4() {
  SetTexture(constants::GROUND_MONK_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_4_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_ATTACK_4_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack4_energy_cost_;
}

void GroundMonk::Death() {
  SetTexture(constants::GROUND_MONK_DEATH_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_DEATH_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_DEATH_NUM_FRAMES);
  SetCount(1);
}

void GroundMonk::Defend() {
  SetTexture(constants::GROUND_MONK_DEFEND_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_DEFEND_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_DEFEND_NUM_FRAMES);
  SetCount(1);
}

void GroundMonk::Idle() {
  SetTexture(constants::GROUND_MONK_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_IDLE_NUM_FRAMES);
  SetCount(1);
}

void GroundMonk::TakeDamage(int damage) {
  SetTexture(constants::GROUND_MONK_TAKE_DAMAGE_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_TAKE_DAMAGE_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_TAKE_DAMAGE_NUM_FRAMES);
  SetCount(1);
  SetHealth(health_ - damage);
}