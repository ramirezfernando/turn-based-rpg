#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

class TextBoxV2 {
 public:
  TextBoxV2(const char* font_path, const char* background_path, int font_size,
            int width, int height, int x_pos, int y_pos);
  ~TextBoxV2();
  void Render();
  void SetText(const std::string& text, SDL_Color color = {0, 0, 0, 255});

 private:
  TTF_Font* font_ = nullptr;
  SDL_Texture* text_texture_ = nullptr;
  SDL_Texture* box_texture_ = nullptr;
  SDL_Rect src_rect_, dest_rect_;
  int x_pos_, y_pos_;
  std::string current_text_;
};