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
}

void WaterPriestess::Attack2() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_2_FOLDER_PATH));
  SetFrames(21);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::Attack3() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_3_FOLDER_PATH));
  SetFrames(28);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::Attack4() {
  SetTexture(constants::WATER_PRIESTESS_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::WATER_PRIESTESS_ATTACK_4_FOLDER_PATH));
  SetFrames(33);
  SetCount(1);
  SetSpeed(100);
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