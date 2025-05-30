#include "character.h"

class GroundMonk : public Character {
 public:
  GroundMonk();
  GroundMonk(bool isEnemy, std::string name);
  GroundMonk(bool isEnemy, std::string name, int level, int health, int chakra);
  void SetEnergy(int) override;
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
  int chakra_;
};