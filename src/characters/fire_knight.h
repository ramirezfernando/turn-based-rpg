#pragma once

#include "character.h"

class FireKnight : public Character {
 public:
  FireKnight();
  FireKnight(bool isEnemy, std::string name);
  FireKnight(bool isEnemy, std::string name, int level, int health,
             int stamina);
  void SetEnergy(int stamina) override;
  int GetEnergy() override;
  void Attack1() override;
  void Attack2() override;
  void Attack3() override;
  void Attack4() override;
  void Death() override;
  void Defend() override;
  void Idle() override;
  void TakeDamage(int damage) override;
  void PrintStats() override;

 private:
  int stamina_;
};