#pragma once

#include "character.h"

// The implementation of the `Character` interface for the Fire Knight. The Fire
// Knight is a high-damage, high-energy-cost character.
class FireKnight : public Character {
 public:
  FireKnight(bool is_enemy);
  void Attack1() override;
  void Attack2() override;
  void Attack3() override;
  void Attack4() override;
  void Death() override;
  void Defend() override;
  void Idle() override;
  void TakeDamage(int damage) override;
};