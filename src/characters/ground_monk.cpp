#include "ground_monk.h"

GroundMonk::GroundMonk() {
  std::string path = "assets/GroundMonk/idle";
  const char* file = path.c_str();
  SetTexture(file);
  SetXPos(-80);
  SetYPos(20);

  SetPath(path);
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
    const char* file = "assets/GroundMonk/idle";
    SetTexture(file);
    SetXPos(200);
    SetYPos(20);

    SetPath("assets/GroundMonk/idle");
    SetFrames(6);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(1);
    SetHealth(100);

    chakra_ = 100;
  } else {
    SetPath("assets/GroundMonk/idle");
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
    const char* file = "assets/GroundMonk/idle";
    SetTexture(file);
    SetXPos(200);
    SetYPos(20);

    SetPath("assets/GroundMonk/idle");
    SetFrames(6);
    SetSpeed(100);
    SetCount(1);

    SetName(name);
    SetLevel(level);
    SetHealth(health);
    chakra_ = chakra;
  } else {
    SetPath("assets/GroundMonk/idle");
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
  std::string filename = "assets/GroundMonk/1_atk";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/GroundMonk/1_atk");
  SetFrames(6);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Attack2() {
  std::string filename = "assets/GroundMonk/2_atk";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/GroundMonk/2_atk");
  SetFrames(12);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Attack3() {
  std::string filename = "assets/GroundMonk/3_atk";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/GroundMonk/3_atk");
  SetFrames(24);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Attack4() {
  std::string filename = "assets/GroundMonk/4_sp_atk";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/GroundMonk/4_sp_atk");
  SetFrames(25);
  SetCount(1);
  SetSpeed(100);
}

void GroundMonk::Death() {
  std::string filename = "assets/GroundMonk/death";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/GroundMonk/death");
  SetFrames(18);
  SetCount(1);
  SetSpeed(100);
}
void GroundMonk::Defend() {
  std::string filename = "assets/GroundMonk/defend";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/GroundMonk/defend");
  SetFrames(13);
  SetCount(1);
  SetSpeed(100);
}
void GroundMonk::Idle() {
  std::string filename = "assets/GroundMonk/idle";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/GroundMonk/idle");
  SetFrames(6);
  SetCount(1);
  SetSpeed(100);
}
void GroundMonk::TakeDamage(int damage) {
  std::string filename = "assets/GroundMonk/take_hit";
  const char* file = filename.c_str();
  SetTexture(file);
  SetPath("assets/GroundMonk/take_hit");
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