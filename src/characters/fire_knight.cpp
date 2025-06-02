#include "fire_knight.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

FireKnight::FireKnight(std::string username, bool is_enemy) {
  SetUsername(username);
  SetTexture(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH));
  SetFrames(8);
  SetSpeed(100);
  SetCount(1);
  SetLevel(1);
  SetHealth(100);
  SetEnergy(100);

  // Fire Knight specific stat modifications
  base_attack1_damage_ *= constants::FIRE_KNIGHT_DAMAGE_MOD;
  base_attack2_damage_ *= constants::FIRE_KNIGHT_DAMAGE_MOD;
  base_attack3_damage_ *= constants::FIRE_KNIGHT_DAMAGE_MOD;
  base_attack4_damage_ *= constants::FIRE_KNIGHT_DAMAGE_MOD;

  base_attack1_energy_cost_ *= constants::FIRE_KNIGHT_ENERGY_COST_MOD;
  base_attack2_energy_cost_ *= constants::FIRE_KNIGHT_ENERGY_COST_MOD;
  base_attack3_energy_cost_ *= constants::FIRE_KNIGHT_ENERGY_COST_MOD;
  base_attack4_energy_cost_ *= constants::FIRE_KNIGHT_ENERGY_COST_MOD;

  damage_scaling_ = constants::FIRE_KNIGHT_DAMAGE_SCALING;
  health_scaling_ = constants::FIRE_KNIGHT_HEALTH_SCALING;
  energy_scaling_ = constants::FIRE_KNIGHT_ENERGY_SCALING;

  if (is_enemy) {
    SetEnemy(is_enemy);
    SetXPos(constants::CHARACTER_ENEMY_X_POS);
    SetYPos(constants::CHARACTER_ENEMY_Y_POS);
  } else {
    SetXPos(constants::CHARACTER_PLAYER_X_POS);
    SetYPos(constants::CHARACTER_PLAYER_Y_POS);
  }
}

void FireKnight::Attack1() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_1_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_1_FOLDER_PATH));
  SetFrames(11);
  SetCount(1);
  SetSpeed(100);
  SetAttacking(true);
  energy_ -= base_attack1_energy_cost_;
}

int FireKnight::GetAttack1Damage() const {
  return static_cast<int>(base_attack1_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void FireKnight::Attack2() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_2_FOLDER_PATH));
  SetFrames(19);
  SetCount(1);
  SetSpeed(100);
  SetAttacking(true);
  energy_ -= base_attack2_energy_cost_;
}

int FireKnight::GetAttack2Damage() const {
  return static_cast<int>(base_attack2_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void FireKnight::Attack3() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_3_FOLDER_PATH));
  SetFrames(29);
  SetCount(1);
  SetSpeed(100);
  SetAttacking(true);
  energy_ -= base_attack3_energy_cost_;
}

int FireKnight::GetAttack3Damage() const {
  return static_cast<int>(base_attack3_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void FireKnight::Attack4() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_4_FOLDER_PATH));
  SetFrames(18);
  SetCount(1);
  SetSpeed(100);
  SetAttacking(true);
  energy_ -= base_attack4_energy_cost_;
}

int FireKnight::GetAttack4Damage() const {
  return static_cast<int>(base_attack4_damage_ *
                          std::pow(damage_scaling_, level_ - 1));
}

void FireKnight::Death() {
  SetTexture(constants::FIRE_KNIGHT_DEATH_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_DEATH_FOLDER_PATH));
  SetFrames(13);
  SetCount(1);
  SetSpeed(100);
}

void FireKnight::Defend() {
  SetTexture(constants::FIRE_KNIGHT_DEFEND_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_DEFEND_FOLDER_PATH));
  SetFrames(10);
  SetCount(1);
  SetSpeed(100);
}

void FireKnight::Idle() {
  SetTexture(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH));
  SetFrames(8);
  SetCount(1);
  SetSpeed(100);
}

void FireKnight::TakeDamage(int damage) {
  SetTexture(constants::FIRE_KNIGHT_TAKE_DAMAGE_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_TAKE_DAMAGE_FOLDER_PATH));
  SetFrames(7);
  SetCount(1);
  SetSpeed(100);
  SetHealth(health_ - damage);
}