#include "ground_monk.h"
#include "constants/asset_constants.h"

GroundMonk::GroundMonk() {
  SetTexture(constants::GROUND_MONK_IDLE_FOLDER_PATH);
  SetXPos(-80);
  SetYPos(20);

  SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
  SetFrames(6);
  SetSpeed(100);
  SetCount(1);

  SetName("Unknown");
  SetLevel(1);
  SetHealth(100);

  chakra_ = 100;
}
GroundMonk::GroundMonk(bool isEnemy, std::string name) {
  if (isEnemy) {
    SetEnemy(isEnemy);
    SetTexture(constants::GROUND_MONK_IDLE_FOLDER_PATH);
    SetXPos(200);
    SetYPos(20);

    SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
    SetFrames(6);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(1);
    SetHealth(100);

    chakra_ = 100;
  } else {
    SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
    SetFrames(6);
    SetSpeed(100);
    SetCount(1);
    SetXPos(-80);
    SetYPos(20);

    SetName(name);
    SetLevel(1);
    SetHealth(100);
    chakra_ = 100;

    std::string filename = folder_path_ + "/" + "1.png";
    const char* file = filename.c_str();
    SetTexture(file);
  }
}
GroundMonk::GroundMonk(bool isEnemy, std::string name, int level, int health,
                       int chakra) {
  if (isEnemy) {
    SetEnemy(isEnemy);
    SetTexture(constants::GROUND_MONK_IDLE_FOLDER_PATH);
    SetXPos(200);
    SetYPos(20);

    SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
    SetFrames(6);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    chakra_ = chakra;
  } else {
    SetPath(std::string(constants::GROUND_MONK_IDLE_FOLDER_PATH));
    SetFrames(6);
    SetSpeed(100);
    SetCount(1);
    SetXPos(-80);
    SetYPos(20);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    chakra_ = chakra;

    std::string filename = folder_path_ + "/" + "1.png";
    const char* file = filename.c_str();
    SetTexture(file);
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
void GroundMonk::SetEnergy(int energy) {
  chakra_ = energy;
}
int GroundMonk::GetEnergy() {
  return chakra_;
}
void GroundMonk::PrintStats() {
  std::cout << "Character Stats:" << std::endl
            << "> Name: " << name_ << std::endl
            << "> Level: " << level_ << std::endl
            << "> Health: " << health_ << std::endl
            << "> Chakra: " << chakra_ << std::endl;
}