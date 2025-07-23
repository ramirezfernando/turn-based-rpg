#include "text_box_v2.h"
#include <game.h>
#include "constants/game_constants.h"
#include "utils/util.h"

TextBoxV2::TextBoxV2(const char* font_path, int font_size, int width,
                     int height, int x_pos, int y_pos) {
  TTF_Init();
  font_ = TTF_OpenFont(font_path, font_size);
  if (font_ == nullptr) {
    std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
  }
  // TODO: initialize text_box_texture_?
  x_pos_ = x_pos;
  y_pos_ = y_pos;
  src_rect_.h = height;
  src_rect_.w = width;
  src_rect_.x = 0;
  src_rect_.y = 0;
  dest_rect_.h = src_rect_.h;
  dest_rect_.w = src_rect_.w;
  dest_rect_.x = x_pos_;
  dest_rect_.y = y_pos_;
}

TextBoxV2::~TextBoxV2() {
  SDL_DestroyTexture(text_box_texture_);
  std::cout << "Text Box destroyed" << std::endl;
}

void TextBoxV2::Render() {
  SDL_RenderCopy(Game::renderer_, text_box_texture_, &src_rect_, &dest_rect_);
}

void TextBoxV2::SetFont(const char* font_path, int font_size) {
  if (font_ != nullptr) {
    TTF_CloseFont(font_);
  }
  font_ = TTF_OpenFont(font_path, font_size);
  if (font_ == nullptr) {
    std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
  }
}

void TextBoxV2::SetText(const std::string& text, SDL_Color color) {
  if (font_ == nullptr) {
    std::cerr << "Font not set. Call SetFont() before setting text."
              << std::endl;
    return;
  }

  // TODO: Add to utils/util.h
  SDL_Surface* tmp_surface = TTF_RenderText_Solid(font_, text.c_str(), color);
  text_box_texture_ =
      SDL_CreateTextureFromSurface(Game::renderer_, tmp_surface);
  SDL_FreeSurface(tmp_surface);
}