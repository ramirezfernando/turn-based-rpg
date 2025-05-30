#include "water_priestess.h"

WaterPriestess::WaterPriestess() {
  std::string path = "assets/WaterPriestess/idle";
  const char* file = path.c_str();
  SetTexture(file);
  SetXPos(-80);
  SetYPos(20);

  SetPath(path);
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
    const char* file = "assets/WaterPriestess/idle";
    SetTexture(file);
    SetXPos(200);
    SetYPos(20);

    SetPath("assets/WaterPriestess/idle");
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(1);
    SetHealth(100);

    mana_ = 100;
  } else {
    SetPath("assets/WaterPriestess/idle");
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
    const char* file = "assets/WaterPriestess/idle";
    SetTexture(file);
    SetXPos(200);
    SetYPos(20);

    SetPath("assets/WaterPriestess/idle");
    SetFrames(8);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    mana_ = mana;
  } else {
    SetPath("assets/WaterPriestess/idle");
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
  std::string filename = "assets/WaterPriestess/1_atk";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/WaterPriestess/1_atk");
  SetFrames(7);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::Attack2() {
  std::string filename = "assets/WaterPriestess/2_atk";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/WaterPriestess/2_atk");
  SetFrames(21);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::Attack3() {
  std::string filename = "assets/WaterPriestess/3_atk";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/WaterPriestess/3_atk");
  SetFrames(28);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::Attack4() {
  std::string filename = "assets/WaterPriestess/4_sp_atk";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/WaterPriestess/4_sp_atk");
  SetFrames(33);
  SetCount(1);
  SetSpeed(100);
}

void WaterPriestess::Death() {
  std::string filename = "assets/WaterPriestess/death";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/WaterPriestess/death");
  SetFrames(16);
  SetCount(1);
  SetSpeed(100);
}
void WaterPriestess::Defend() {
  std::string filename = "assets/WaterPriestess/defend";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/WaterPriestess/defend");
  SetFrames(12);
  SetCount(1);
  SetSpeed(100);
}
void WaterPriestess::Idle() {
  std::string filename = "assets/WaterPriestess/idle";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/WaterPriestess/idle");
  SetFrames(8);
  SetCount(1);
  SetSpeed(100);
}
void WaterPriestess::TakeDamage(int damage) {
  std::string filename = "assets/WaterPriestess/take_hit";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/WaterPriestess/take_hit");
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