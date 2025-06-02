#include "water_priestess.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

WaterPriestess::WaterPriestess(std::string username, bool is_enemy) {
  SetUsername(username);
  SetTexture(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
  SetFrames(8);
  SetSpeed(100);
  SetCount(1);
  SetLevel(1);
  SetHealth(100);
  SetEnergy(100);

  // Water Priestess specific stat modifications
  base_attack1_damage_ *= constants::WATER_PRIESTESS_DAMAGE_MOD;
  base_attack2_damage_ *= constants::WATER_PRIESTESS_DAMAGE_MOD;
  base_attack3_damage_ *= constants::WATER_PRIESTESS_DAMAGE_MOD;
  base_attack4_damage_ *= constants::WATER_PRIESTESS_DAMAGE_MOD;

  base_attack1_energy_cost_ *= constants::WATER_PRIESTESS_ENERGY_COST_MOD;
  base_attack2_energy_cost_ *= constants::WATER_PRIESTESS_ENERGY_COST_MOD;
  base_attack3_energy_cost_ *= constants::WATER_PRIESTESS_ENERGY_COST_MOD;
  base_attack4_energy_cost_ *= constants::WATER_PRIESTESS_ENERGY_COST_MOD;

  damage_scaling_ = constants::WATER_PRIESTESS_DAMAGE_SCALING;
  health_scaling_ = constants::WATER_PRIESTESS_HEALTH_SCALING;
  energy_scaling_ = constants::WATER_PRIESTESS_ENERGY_SCALING;

  if (is_enemy) {
    SetEnemy(is_enemy);
    SetXPos(constants::CHARACTER_ENEMY_X_POS);
    SetYPos(constants::CHARACTER_ENEMY_Y_POS);
  } else {
    SetXPos(constants::CHARACTER_PLAYER_X_POS);
    SetYPos(constants::CHARACTER_PLAYER_Y_POS);
  }
}

void WaterPriestess::Attack1() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_1_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_1_FOLDER_PATH));
  SetFrames(7);
  SetCount(1);
  SetSpeed(100);
  SetAttacking(true);
  energy_ -= base_attack1_energy_cost_;
}

int WaterPriestess::GetAttack1Damage() const {
  return static_cast<int>(base_attack1_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void WaterPriestess::Attack2() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_2_FOLDER_PATH));
  SetFrames(21);
  SetCount(1);
  SetSpeed(100);
  SetAttacking(true);
  energy_ -= base_attack2_energy_cost_;
}

int WaterPriestess::GetAttack2Damage() const {
  return static_cast<int>(base_attack2_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void WaterPriestess::Attack3() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_3_FOLDER_PATH));
  SetFrames(28);
  SetCount(1);
  SetSpeed(100);
  SetAttacking(true);
  energy_ -= base_attack3_energy_cost_;
}

int WaterPriestess::GetAttack3Damage() const {
  return static_cast<int>(base_attack3_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void WaterPriestess::Attack4() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_4_FOLDER_PATH));
  SetFrames(33);
  SetCount(1);
  SetSpeed(100);
  SetAttacking(true);
  energy_ -= base_attack4_energy_cost_;
}

int WaterPriestess::GetAttack4Damage() const {
  return static_cast<int>(base_attack4_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void WaterPriestess::Death() {
  SetTexture(constants::WATER_PRIESTESS_DEATH_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_DEATH_FOLDER_PATH));
  SetFrames(16);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::Defend() {
  SetTexture(constants::WATER_PRIESTESS_DEFEND_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_DEFEND_FOLDER_PATH));
  SetFrames(12);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::Idle() {
  SetTexture(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
  SetFrames(8);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::TakeDamage(int damage) {
  SetTexture(constants::WATER_PRIESTESS_TAKE_DAMAGE_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_TAKE_DAMAGE_FOLDER_PATH));
  SetFrames(7);
  SetCount(1);
  SetSpeed(100);
  SetHealth(health_ - damage);
}