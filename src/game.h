#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include "background/background.h"
#include "characters/character.h"
#include "characters/fire_knight.h"
#include "characters/ground_monk.h"
#include "characters/water_priestess.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"
#include "text_box/text_box.h"

class Game {
 public:
  ~Game();
  void Init(const char* title, int x_pos, int y_pos, int width, int height);
  void Update();
  void Render();
  void SetIsRunning(bool is_running) { is_running_ = is_running; }
  bool IsRunning() { return is_running_; }
  void HandleEvents();
  void HandleMenuEvents();
  void HandleAttackEvents();
  void HandleStatsEvents();
  void HandleRunEvents();
  void HandleSaveEvents();
  static SDL_Renderer* renderer_;
  static SDL_Event event_;

 private:
  SDL_Window* window_;
  std::unique_ptr<Background> background_;
  std::unique_ptr<TextBox> text_box_;
  std::unique_ptr<Character> player_;
  std::unique_ptr<Character> enemy_;
  bool is_running_, is_player_turn_, is_in_battle_, should_render_text_box_;
};