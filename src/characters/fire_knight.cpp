#include "fire_knight.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

FireKnight::FireKnight(bool is_enemy) {
  SetTexture(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH));
  SetFrames(constants::FIRE_KNIGHT_IDLE_NUM_FRAMES);
  SetCount(1);
  SetLevel(1);
  SetHealth(100);
  SetEnergy(100);
  SetAttack1Damage(constants::FIRE_KNIGHT_ATTACK_1_DAMAGE);
  SetAttack2Damage(constants::FIRE_KNIGHT_ATTACK_2_DAMAGE);
  SetAttack3Damage(constants::FIRE_KNIGHT_ATTACK_3_DAMAGE);
  SetAttack4Damage(constants::FIRE_KNIGHT_ATTACK_4_DAMAGE);
  SetAttack1EnergyCost(constants::FIRE_KNIGHT_ATTACK_1_ENERGY_COST);
  SetAttack2EnergyCost(constants::FIRE_KNIGHT_ATTACK_2_ENERGY_COST);
  SetAttack3EnergyCost(constants::FIRE_KNIGHT_ATTACK_3_ENERGY_COST);
  SetAttack4EnergyCost(constants::FIRE_KNIGHT_ATTACK_4_ENERGY_COST);

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
  SetFrames(constants::FIRE_KNIGHT_ATTACK_1_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack1_energy_cost_;
}

void FireKnight::Attack2() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_2_FOLDER_PATH));
  SetFrames(constants::FIRE_KNIGHT_ATTACK_2_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack2_energy_cost_;
}

void FireKnight::Attack3() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_3_FOLDER_PATH));
  SetFrames(constants::FIRE_KNIGHT_ATTACK_3_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack3_energy_cost_;
}

void FireKnight::Attack4() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_4_FOLDER_PATH));
  SetFrames(constants::FIRE_KNIGHT_ATTACK_4_NUM_FRAMES);
  SetCount(1);
  SetAttacking(true);
  energy_ -= attack4_energy_cost_;
}

void FireKnight::Death() {
  SetTexture(constants::FIRE_KNIGHT_DEATH_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_DEATH_FOLDER_PATH));
  SetFrames(constants::FIRE_KNIGHT_DEATH_NUM_FRAMES);
  SetCount(1);
}

void FireKnight::Defend() {
  SetTexture(constants::FIRE_KNIGHT_DEFEND_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_DEFEND_FOLDER_PATH));
  SetFrames(constants::FIRE_KNIGHT_DEFEND_NUM_FRAMES);
  SetCount(1);
}

void FireKnight::Idle() {
  SetTexture(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH));
  SetFrames(constants::FIRE_KNIGHT_IDLE_NUM_FRAMES);
  SetCount(1);
}

void FireKnight::TakeDamage(int damage) {
  SetTexture(constants::FIRE_KNIGHT_TAKE_DAMAGE_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_TAKE_DAMAGE_FOLDER_PATH));
  SetFrames(constants::FIRE_KNIGHT_TAKE_DAMAGE_NUM_FRAMES);
  SetCount(1);
  SetHealth(health_ - damage);
}