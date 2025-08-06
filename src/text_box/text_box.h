#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "characters/character.h"
#include "constants/game_constants.h"

class TextBox {
 public:
  TextBox(const char* font_path, const char* background_path, int font_size,
          int width, int height, int x_pos, int y_pos);
  ~TextBox();
  void Render();
  void SetText(const std::string& text, SDL_Color color = {0, 0, 0, 255});
  void SetMainMenu();
  void SetAttackMenu();
  void SetStatsMenu(Character* player);
  void SetRunMenu();
  void SetSaveMenu();
  void SetSaveSlotText(int slot, const std::string& text);
  constants::TextBoxType GetTextBoxType() const { return text_box_type_; }

 private:
  constants::TextBoxType text_box_type_;
  TTF_Font* font_ = nullptr;
  SDL_Texture* text_texture_ = nullptr;
  SDL_Texture* box_texture_ = nullptr;
  SDL_Rect text_src_rect_, text_dest_rect_, box_src_rect_, box_dest_rect_;
  int text_x_pos_, text_y_pos_, box_x_pos_, box_y_pos_;
  std::string save_slots_text_[2] = {"No saved game", "No saved game"};
};