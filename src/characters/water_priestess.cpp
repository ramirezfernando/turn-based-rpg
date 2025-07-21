#include "water_priestess.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

WaterPriestess::WaterPriestess(bool is_enemy) {
  SetTexture(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
  SetFrames(constants::WATER_PRIESTESS_IDLE_NUM_FRAMES);
  SetCount(1);
  SetLevel(1);
  SetHealth(100);
  SetEnergy(100);
  SetAttack1Damage(constants::WATER_PRIESTESS_ATTACK_1_DAMAGE);
  SetAttack2Damage(constants::WATER_PRIESTESS_ATTACK_2_DAMAGE);
  SetAttack3Damage(constants::WATER_PRIESTESS_ATTACK_3_DAMAGE);
  SetAttack4Damage(constants::WATER_PRIESTESS_ATTACK_4_DAMAGE);
  SetAttack1EnergyCost(constants::WATER_PRIESTESS_ATTACK_1_ENERGY_COST);
  SetAttack2EnergyCost(constants::WATER_PRIESTESS_ATTACK_2_ENERGY_COST);
  SetAttack3EnergyCost(constants::WATER_PRIESTESS_ATTACK_3_ENERGY_COST);
  SetAttack4EnergyCost(constants::WATER_PRIESTESS_ATTACK_4_ENERGY_COST);

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
  SetFrames(constants::WATER_PRIESTESS_ATTACK_1_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack1_energy_cost_;
}

void WaterPriestess::Attack2() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_2_FOLDER_PATH));
  SetFrames(constants::WATER_PRIESTESS_ATTACK_2_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack2_energy_cost_;
}

void WaterPriestess::Attack3() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_3_FOLDER_PATH));
  SetFrames(constants::WATER_PRIESTESS_ATTACK_3_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack3_energy_cost_;
}

void WaterPriestess::Attack4() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_4_FOLDER_PATH));
  SetFrames(constants::WATER_PRIESTESS_ATTACK_4_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack4_energy_cost_;
}

void WaterPriestess::Death() {
  SetTexture(constants::WATER_PRIESTESS_DEATH_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_DEATH_FOLDER_PATH));
  SetFrames(constants::WATER_PRIESTESS_DEATH_NUM_FRAMES);
  SetCount(1);
}

void WaterPriestess::Defend() {
  SetTexture(constants::WATER_PRIESTESS_DEFEND_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_DEFEND_FOLDER_PATH));
  SetFrames(constants::WATER_PRIESTESS_DEFEND_NUM_FRAMES);
  SetCount(1);
}

void WaterPriestess::Idle() {
  SetTexture(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
  SetFrames(constants::WATER_PRIESTESS_IDLE_NUM_FRAMES);
  SetCount(1);
}

void WaterPriestess::TakeDamage(int damage) {
  SetTexture(constants::WATER_PRIESTESS_TAKE_DAMAGE_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_TAKE_DAMAGE_FOLDER_PATH));
  SetFrames(constants::WATER_PRIESTESS_TAKE_DAMAGE_NUM_FRAMES);
  SetCount(1);
  SetHealth(health_ - damage);
}