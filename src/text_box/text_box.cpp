#include "text_box.h"
#include <game.h>
#include "constants/game_constants.h"
#include "utils/util.h"

TextBox::TextBox(const char* file_path, int width, int height, int x_pos,
                 int y_pos) {
  text_box_texture_ = Util::LoadTexture(file_path);
  file_path_ = std::string(file_path);
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

TextBox::~TextBox() {
  SDL_DestroyTexture(text_box_texture_);
  std::cout << "Text Box destroyed" << std::endl;
}

void TextBox::Render() {
  SDL_RenderCopy(Game::renderer_, text_box_texture_, &src_rect_, &dest_rect_);
}

void TextBox::SetImageFilePathAndLoadTexture(const char* file_path) {
  file_path_ = std::string(file_path);
  text_box_texture_ = Util::LoadTexture(file_path);
}