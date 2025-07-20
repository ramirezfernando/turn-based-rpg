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

  // Ground Monk specific stat modifications
  base_attack1_damage_ *= constants::GROUND_MONK_DAMAGE_MOD;
  base_attack2_damage_ *= constants::GROUND_MONK_DAMAGE_MOD;
  base_attack3_damage_ *= constants::GROUND_MONK_DAMAGE_MOD;
  base_attack4_damage_ *= constants::GROUND_MONK_DAMAGE_MOD;

  base_attack1_energy_cost_ *= constants::GROUND_MONK_ENERGY_COST_MOD;
  base_attack2_energy_cost_ *= constants::GROUND_MONK_ENERGY_COST_MOD;
  base_attack3_energy_cost_ *= constants::GROUND_MONK_ENERGY_COST_MOD;
  base_attack4_energy_cost_ *= constants::GROUND_MONK_ENERGY_COST_MOD;

  damage_scaling_ = constants::GROUND_MONK_DAMAGE_SCALING;
  health_scaling_ = constants::GROUND_MONK_HEALTH_SCALING;
  energy_scaling_ = constants::GROUND_MONK_ENERGY_SCALING;

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
  energy_ -= base_attack1_energy_cost_;
}

int GroundMonk::GetAttack1Damage() const {
  return static_cast<int>(base_attack1_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void GroundMonk::Attack2() {
  SetTexture(constants::GROUND_MONK_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_2_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_ATTACK_2_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= base_attack2_energy_cost_;
}

int GroundMonk::GetAttack2Damage() const {
  return static_cast<int>(base_attack2_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void GroundMonk::Attack3() {
  SetTexture(constants::GROUND_MONK_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_3_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_ATTACK_3_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= base_attack3_energy_cost_;
}

int GroundMonk::GetAttack3Damage() const {
  return static_cast<int>(base_attack3_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void GroundMonk::Attack4() {
  SetTexture(constants::GROUND_MONK_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_4_FOLDER_PATH));
  SetFrames(constants::GROUND_MONK_ATTACK_4_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= base_attack4_energy_cost_;
}

int GroundMonk::GetAttack4Damage() const {
  return static_cast<int>(base_attack4_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
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