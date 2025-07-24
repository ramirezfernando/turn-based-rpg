#include "text_box_v2.h"
#include <game.h>
#include "constants/game_constants.h"
#include "utils/util.h"

TextBoxV2::TextBoxV2(const char* font_path, const char* background_path,
                     int font_size, int width, int height, int x_pos,
                     int y_pos) {
  TTF_Init();
  font_ = TTF_OpenFont(font_path, font_size);
  box_texture_ = Util::LoadTexture(background_path);
  text_texture_ = Util::LoadText("Hello, world!", font_, {0, 0, 0, 255});
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
  SDL_DestroyTexture(text_texture_);
  SDL_DestroyTexture(box_texture_);
  std::cout << "Text Box destroyed" << std::endl;
}

void TextBoxV2::Render() {
  SDL_Rect box_src_rect = {0, 0, src_rect_.w, src_rect_.h};
  SDL_Rect box_dest_rect = {x_pos_, y_pos_, src_rect_.w, src_rect_.h};
  SDL_RenderCopy(Game::renderer_, box_texture_, &box_src_rect, &box_dest_rect);

  SDL_Rect text_src_rect = {0, 0, src_rect_.w, src_rect_.h};
  SDL_Rect text_dest_rect = {x_pos_ + 10, y_pos_ + 10, src_rect_.w - 20,
                             src_rect_.h - 20};
  SDL_RenderCopy(Game::renderer_, text_texture_, &text_src_rect,
                 &text_dest_rect);
}

void TextBoxV2::SetText(const std::string& text, SDL_Color color) {
  text_texture_ = Util::LoadText(text.c_str(), font_, color);
}