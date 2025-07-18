#pragma once

#include "character.h"

class FireKnight : public Character {
 public:
  FireKnight(std::string username, bool is_enemy);
  void Attack1() override;
  int GetAttack1Damage() const override;
  void Attack2() override;
  int GetAttack2Damage() const override;
  void Attack3() override;
  int GetAttack3Damage() const override;
  void Attack4() override;
  int GetAttack4Damage() const override;
  void Death() override;
  void Defend() override;
  void Idle() override;
  void TakeDamage(int damage) override;
};