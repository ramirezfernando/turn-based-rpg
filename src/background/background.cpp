#include "background.h"
#include <game.h>
#include "constants/game_constants.h"
#include "utils/util.h"

Background::Background(const char* file_path, int width, int height) {
  background_texture_ = Util::LoadTexture(file_path);
  file_path_ = std::string(file_path);
  x_pos_ = 0;
  y_pos_ = 0;
  src_rect_.h = width;
  src_rect_.w = height;
  src_rect_.x = 0;
  src_rect_.y = 0;
  dest_rect_.h = src_rect_.h;
  dest_rect_.w = src_rect_.w;
  dest_rect_.x = x_pos_;
  dest_rect_.y = y_pos_;
}

Background::~Background() {
  SDL_DestroyTexture(background_texture_);
  std::cout << "Background destroyed" << std::endl;
}

void Background::Render() {
  SDL_RenderCopy(Game::renderer_, background_texture_, &src_rect_, &dest_rect_);
}

void Background::SetImageFilePathAndLoadTexture(const char* file_path) {
  file_path_ = std::string(file_path);
  background_texture_ = Util::LoadTexture(file_path);
}