#pragma once

#include "character.h"

// The implementation of the `Character` interface for the Water Priestess. The
// Water Priestess is a character with lower base damage but efficient energy
// usage, excelling at sustained combat.
class WaterPriestess : public Character {
 public:
  WaterPriestess(bool is_enemy);
  void Attack1() override;
  void Attack2() override;
  void Attack3() override;
  void Attack4() override;
  void Death() override;
  void Defend() override;
  void Idle() override;
  void TakeDamage(int damage) override;
};