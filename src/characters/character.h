#pragma once

#include <string>
#include "constants/game_constants.h"
#include "utils/util.h"

class Character {
 public:
  virtual ~Character();
  void Update();
  void Render();
  void SetTexture(const char* file_path) {
    character_texture_ = Util::LoadTexture(file_path);
  }
  void SetXPos(int x_pos) { x_pos_ = x_pos; }
  void SetYPos(int y_pos) { y_pos_ = y_pos; }
  void SetPath(std::string folder_path) { folder_path_ = folder_path; }
  void SetFrames(int frames) { frames_ = frames; }
  void SetCount(int count) { count_ = count; }
  void SetLevel(int level) { level_ = level; }
  void SetHealth(int health) { health_ = health; }
  void SetEnergy(int energy) { energy_ = energy; }
  void SetEnemy(bool is_enemy) { is_enemy_ = is_enemy; }
  void SetAttack1Damage(int damage) { attack1_damage_ = damage; }
  void SetAttack2Damage(int damage) { attack2_damage_ = damage; }
  void SetAttack3Damage(int damage) { attack3_damage_ = damage; }
  void SetAttack4Damage(int damage) { attack4_damage_ = damage; }
  void SetAttack1EnergyCost(int energy) { attack1_energy_cost_ = energy; }
  void SetAttack2EnergyCost(int energy) { attack2_energy_cost_ = energy; }
  void SetAttack3EnergyCost(int energy) { attack3_energy_cost_ = energy; }
  void SetAttack4EnergyCost(int energy) { attack4_energy_cost_ = energy; }
  SDL_Texture* GetTexture() { return character_texture_; }
  int GetXPos() { return x_pos_; }
  int GetYPos() { return y_pos_; }
  std::string GetPath() { return folder_path_; }
  int GetFrames() { return frames_; }
  int GetCount() { return count_; }
  int GetLevel() { return level_; }
  int GetHealth() { return health_; }
  int GetEnergy() { return energy_; }
  bool GetEnemy() { return is_enemy_; }
  int GetAttack1Damage() const { return attack1_damage_; }
  int GetAttack2Damage() const { return attack2_damage_; }
  int GetAttack3Damage() const { return attack3_damage_; }
  int GetAttack4Damage() const { return attack4_damage_; }
  constants::AttackType GetAiDecision();
  bool IsAnimationComplete() const { return count_ >= frames_; }
  bool IsAttacking() const { return is_attacking_; }
  void SetAttacking(bool attacking) { is_attacking_ = attacking; }
  virtual void Attack1() = 0;
  virtual void Attack2() = 0;
  virtual void Attack3() = 0;
  virtual void Attack4() = 0;
  virtual void Death() = 0;
  virtual void Defend() = 0;
  virtual void Idle() = 0;
  virtual void TakeDamage(int damage) = 0;

 protected:
  SDL_Texture* character_texture_;
  SDL_Rect src_rect_, dest_rect_;
  int x_pos_, y_pos_, frames_, count_, level_, health_, energy_, delay_ = 70;
  int attack1_damage_, attack2_damage_, attack3_damage_, attack4_damage_,
      attack1_energy_cost_, attack2_energy_cost_, attack3_energy_cost_,
      attack4_energy_cost_;
  float damage_scaling_ = 1.0f, health_scaling_ = 1.0f, energy_scaling_ = 1.0f;
  std::string folder_path_;
  Uint32 last_frame_time_ = 0;
  bool is_enemy_ = false, is_attacking_ = false;
};