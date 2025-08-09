#pragma once

#include "character.h"

// The implementation of the `Character` interface for the Ground Monk. The
// Ground Monk is a balanced character with standard energy costs.
class GroundMonk : public Character {
 public:
  GroundMonk(bool is_enemy);
  void Attack1() override;
  void Attack2() override;
  void Attack3() override;
  void Attack4() override;
  void Death() override;
  void Defend() override;
  void Idle() override;
  void TakeDamage(int damage) override;
};