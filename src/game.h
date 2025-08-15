#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sqlite3.h>
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
#include "database/database.h"
#include "text_box/text_box.h"

// The main game class that manages the game loop, rendering, and events.
class Game {
 public:
  enum class State {
    CHARACTER_SELECTION,
    BATTLE,
    GAME_OVER,
  };
  ~Game();
  void Init(const char* title, int x_pos, int y_pos, int width, int height);
  void Update();
  void Render();
  void SetState(State state) { state_ = state; }
  void SetIsRunning(bool is_running) { is_running_ = is_running; }
  bool IsRunning() { return is_running_; }
  void HandleEvents();
  static SDL_Renderer* renderer_;
  static SDL_Event event_;

 private:
  void HandleBattleUpdate();
  void HandleBattleEvents();
  void HandleBattleChoiceEvents();
  void HandleBattleAttackEvents();
  void HandleBattleStatsEvents();
  void HandleBattleSaveEvents();
  void HandleBattleRunEvents();
  SDL_Window* window_;
  std::unique_ptr<Database> database_;
  std::unique_ptr<Background> background_;
  std::unique_ptr<TextBox> text_box_;
  std::unique_ptr<Character> player_;
  std::unique_ptr<Character> enemy_;
  bool is_running_, is_player_turn_, is_in_battle_, should_render_text_box_;
  State state_;
};