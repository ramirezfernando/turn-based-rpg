#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "characters/character.h"
#include "constants/game_constants.h"

// The class is responsible for rendering text boxes in the game. Owned by the
// `Game` class.
class TextBox {
 public:
  enum class Type {
    CHARACTER_SELECTION_PLAYER,
    CHARACTER_SELECTION_ENEMY,
    BATTLE_OPTIONS,
    BATTLE_ATTACK,
    BATTLE_STATS,
    BATTLE_SAVE,
    BATTLE_RUN,
  };
  TextBox(const char* font_path, const char* background_path, int font_size,
          int width, int height, int x_pos, int y_pos);
  ~TextBox();
  void Render();
  bool ShouldRender() const { return should_render_; }
  void SetShouldRender(bool should_render) { should_render_ = should_render; }
  void SetText(const std::string& text, SDL_Color color = {0, 0, 0, 255});
  void SetCharacterSelection(bool is_enemy);
  void SetBattleOptions();
  void SetBattleAttack();
  void SetBattleStats(Character* player);
  void SetBattleRun();
  void SetBattleSave();
  void SetSaveSlotText(int slot, const std::string& text);
  void SetType(Type type) { text_box_type_ = type; }
  Type GetType() const { return text_box_type_; }

 private:
  Type text_box_type_;
  TTF_Font* font_ = nullptr;
  SDL_Texture* text_texture_ = nullptr;
  SDL_Texture* box_texture_ = nullptr;
  SDL_Rect text_src_rect_, text_dest_rect_, box_src_rect_, box_dest_rect_;
  int text_x_pos_, text_y_pos_, box_x_pos_, box_y_pos_;
  std::string save_slots_text_[1] = {"No saved game"};
  bool should_render_ = true;
};