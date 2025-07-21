#include "character.h"

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