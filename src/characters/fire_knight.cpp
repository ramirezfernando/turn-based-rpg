#include "fire_knight.h"
#include "constants/asset_constants.h"

FireKnight::FireKnight() {
  const char* file = constants::FIRE_KNIGHT_IDLE_FOLDER_PATH;
  SetTexture(file);
  SetXPos(-80);
  SetYPos(20);

  SetPath("assets/FireKnight/idle");
  SetFrames(8);
  SetSpeed(20);
  SetCount(1);

  SetName("Unknown");
  SetLevel(1);
  SetHealth(100);

  stamina_ = 100;
}

FireKnight::FireKnight(bool isEnemy, std::string name) {
  if (isEnemy) {
    SetEnemy(isEnemy);
    const char* file = constants::FIRE_KNIGHT_IDLE_FOLDER_PATH;
    SetTexture(file);
    SetXPos(200);
    SetYPos(20);

    SetPath(std::string(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH));
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(1);
    SetHealth(100);

    stamina_ = 100;
  } else {
    SetPath(std::string(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH));
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);
    SetXPos(-80);
    SetYPos(20);

    SetName(name);
    SetLevel(1);
    SetHealth(100);
    stamina_ = 100;

    std::string filename = folder_path_ + "/" + "1.png";
    const char* file = filename.c_str();
    SetTexture(file);
  }
}
FireKnight::FireKnight(bool isEnemy, std::string name, int level, int health,
                       int stamina) {
  if (isEnemy) {
    SetEnemy(isEnemy);
    const char* file = constants::FIRE_KNIGHT_IDLE_FOLDER_PATH;
    SetTexture(file);
    SetXPos(200);
    SetYPos(20);

    SetPath(std::string(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH));
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    stamina_ = stamina;
  } else {
    SetPath(std::string(constants::FIRE_KNIGHT_IDLE_FOLDER_PATH));
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);
    SetXPos(-80);
    SetYPos(20);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    stamina_ = stamina;

    std::string filename = folder_path_ + "/" + "1.png";
    const char* file = filename.c_str();
    SetTexture(file);
  }
}

void FireKnight::Attack1() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_1_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_1_FOLDER_PATH));
  SetFrames(11);
  SetCount(1);
  SetSpeed(100);
}

void FireKnight::Attack2() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_2_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_2_FOLDER_PATH));
  SetFrames(19);
  SetCount(1);
  SetSpeed(100);
}

void FireKnight::Attack3() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_3_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_3_FOLDER_PATH));
  SetFrames(29);
  SetCount(1);
  SetSpeed(100);
}

void FireKnight::Attack4() {
  SetTexture(constants::FIRE_KNIGHT_ATTACK_4_FOLDER_PATH);
  SetPath(std::string(constants::FIRE_KNIGHT_ATTACK_4_FOLDER_PATH));
  SetFrames(18);
  SetCount(1);
  SetSpeed(100);
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
  SetFrames(6);
  SetCount(1);
  SetSpeed(100);
  SetHealth(health_ - damage);
}

void FireKnight::SetEnergy(int stamina) {
  stamina_ = stamina;
}

int FireKnight::GetEnergy() {
  return stamina_;
}
void FireKnight::PrintStats() {
  std::cout << "Character Stats:" << std::endl
            << "> Name: " << name_ << std::endl
            << "> Level: " << level_ << std::endl
            << "> Health: " << health_ << std::endl
            << "> Stamina: " << stamina_ << std::endl;
}