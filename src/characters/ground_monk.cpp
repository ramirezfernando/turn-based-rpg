#include "ground_monk.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

GroundMonk::GroundMonk(std::string username, bool is_enemy) {
  SetUsername(username);
  SetTexture(constants::GROUND_MONK_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
  SetFrames(6);
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

void GroundMonk::Attack1() {
  SetTexture(constants::GROUND_MONK_ATTACK_1_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_1_FOLDER_PATH));
  SetFrames(6);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Attack2() {
  SetTexture(constants::GROUND_MONK_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_2_FOLDER_PATH));
  SetFrames(12);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Attack3() {
  SetTexture(constants::GROUND_MONK_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_3_FOLDER_PATH));
  SetFrames(24);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Attack4() {
  SetTexture(constants::GROUND_MONK_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_ATTACK_4_FOLDER_PATH));
  SetFrames(25);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Death() {
  SetTexture(constants::GROUND_MONK_DEATH_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_DEATH_FOLDER_PATH));
  SetFrames(18);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Defend() {
  SetTexture(constants::GROUND_MONK_DEFEND_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_DEFEND_FOLDER_PATH));
  SetFrames(13);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Idle() {
  SetTexture(constants::GROUND_MONK_IDLE_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
  SetFrames(6);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::TakeDamage(int damage) {
  SetTexture(constants::GROUND_MONK_TAKE_DAMAGE_FOLDER_PATH);
  SetPath(std::string(constants::GROUND_MONK_TAKE_DAMAGE_FOLDER_PATH));
  SetFrames(6);
  SetCount(1);
  SetSpeed(100);

  SetHealth(health_ - damage);
}