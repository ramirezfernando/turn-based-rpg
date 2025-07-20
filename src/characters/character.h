#pragma once

#include <string>
#include "constants/game_constants.h"
#include "utils/util.h"

class Character {
 public:
  virtual ~Character();
  void Update();
  void Render();

  void SetTexture(const char* character_texture) {
    character_texture_ = Util::LoadTexture(character_texture);
  }
  void SetXPos(int x_pos) { x_pos_ = x_pos; }
  void SetYPos(int y_pos) { y_pos_ = y_pos; }
  void SetPath(std::string folder_path) { folder_path_ = folder_path; }
  void SetFrames(int frames) { frames_ = frames; }
  void SetCount(int count) { count_ = count; }
  void SetUsername(std::string username) { username_ = username; }
  void SetLevel(int level) { level_ = level; }
  void SetHealth(int health) { health_ = (health <= 0) ? 0 : health; }
  void SetEnergy(int energy) { energy_ = (energy <= 0) ? 0 : energy; }
  void SetEnemy(bool is_enemy) { is_enemy_ = is_enemy; }

  SDL_Texture* GetTexture() { return character_texture_; }
  int GetXPos() { return x_pos_; }
  int GetYPos() { return y_pos_; }
  std::string GetPath() { return folder_path_; }
  int GetFrames() { return frames_; }
  int GetCount() { return count_; }
  std::string GetUsername() { return username_; }
  int GetLevel() { return level_; }
  int GetHealth() { return health_; }
  int GetEnergy() { return energy_; }
  bool GetEnemy() { return is_enemy_; }

  bool IsAnimationComplete() const { return count_ >= frames_; }
  bool IsAttacking() const { return is_attacking_; }
  void SetAttacking(bool attacking) { is_attacking_ = attacking; }

  virtual void Attack1() = 0;
  virtual int GetAttack1Damage() const = 0;
  virtual void Attack2() = 0;
  virtual int GetAttack2Damage() const = 0;
  virtual void Attack3() = 0;
  virtual int GetAttack3Damage() const = 0;
  virtual void Attack4() = 0;
  virtual int GetAttack4Damage() const = 0;
  virtual void Death() = 0;
  virtual void Defend() = 0;
  virtual void Idle() = 0;
  virtual void TakeDamage(int damage) = 0;

  constants::AttackType GetAiDecision();

 protected:
  SDL_Texture* character_texture_;
  SDL_Rect src_rect_, dest_rect_;
  int x_pos_, y_pos_, frames_, count_, level_, health_, energy_, delay_ = 70;
  std::string folder_path_, username_;
  Uint32 last_frame_time_ = 0;
  bool is_enemy_ = false;
  bool is_attacking_ = false;

  // Base damage values for attacks - initialized from constants
  int base_attack1_damage_ = constants::BASE_ATTACK1_DAMAGE;
  int base_attack2_damage_ = constants::BASE_ATTACK2_DAMAGE;
  int base_attack3_damage_ = constants::BASE_ATTACK3_DAMAGE;
  int base_attack4_damage_ = constants::BASE_ATTACK4_DAMAGE;

  // Base energy costs for attacks - initialized from constants
  int base_attack1_energy_cost_ = constants::BASE_ATTACK1_ENERGY_COST;
  int base_attack2_energy_cost_ = constants::BASE_ATTACK2_ENERGY_COST;
  int base_attack3_energy_cost_ = constants::BASE_ATTACK3_ENERGY_COST;
  int base_attack4_energy_cost_ = constants::BASE_ATTACK4_ENERGY_COST;

  // Level scaling factors - initialized from constants
  float damage_scaling_ = constants::BASE_DAMAGE_SCALING;
  float health_scaling_ = constants::BASE_HEALTH_SCALING;
  float energy_scaling_ = constants::BASE_ENERGY_SCALING;
};