#include "water_priestess.h"
#include "constants/asset_constants.h"

WaterPriestess::WaterPriestess() {
  SetTexture(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH);
  SetXPos(-80);
  SetYPos(20);

  SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
  SetFrames(8);
  SetSpeed(100);
  SetCount(1);

  SetName("Unknown");
  SetLevel(1);
  SetHealth(100);

  mana_ = 100;
}
WaterPriestess::WaterPriestess(bool isEnemy, std::string name) {
  if (isEnemy) {
    SetEnemy(isEnemy);
    SetTexture(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH);
    SetXPos(200);
    SetYPos(20);

    SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(1);
    SetHealth(100);

    mana_ = 100;
  } else {
    SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);
    SetXPos(-80);
    SetYPos(20);

    SetName(name);
    SetLevel(1);
    SetHealth(100);
    mana_ = 100;

    std::string filename = folder_path_ + "/" + "1.png";
    const char* file = filename.c_str();
    SetTexture(file);
  }
}

WaterPriestess::WaterPriestess(bool isEnemy, std::string name, int level,
                               int health, int mana) {
  if (isEnemy) {
    SetEnemy(isEnemy);
    SetTexture(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH);
    SetXPos(200);
    SetYPos(20);

    SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    mana_ = mana;
  } else {
    SetPath(std::string(constants::WATER_PRIESTESS_IDLE_FOLDER_PATH));
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);
    SetXPos(-80);
    SetYPos(20);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    mana_ = mana;

    std::string filename = folder_path_ + "/" + "1.png";
    const char* file = filename.c_str();
    SetTexture(file);
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
void WaterPriestess::SetEnergy(int energy) {
  mana_ = energy;
}
int WaterPriestess::GetEnergy() {
  return mana_;
}
void WaterPriestess::PrintStats() {
  std::cout << "Character Stats:" << std::endl
            << "> Name: " << name_ << std::endl
            << "> Level: " << level_ << std::endl
            << "> Health: " << health_ << std::endl
            << "> Mana: " << mana_ << std::endl;
}