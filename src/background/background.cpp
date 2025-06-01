#include "background.h"
#include "constants/game_constants.h"
#include "utils/util.h"

Background::Background(const char* file_path, int x_pos, int y_pos,
                       bool is_text_box) {
  background_texture_ = Util::LoadTexture(file_path);
  file_path_ = std::string(file_path);
  x_pos_ = x_pos;
  y_pos_ = y_pos;
  is_text_box_ = is_text_box;
}

Background::~Background() {
  SDL_DestroyTexture(background_texture_);
  std::cout << "Background destroyed" << std::endl;
}

void Background::Update() {
  if (is_text_box_) {
    src_rect_.h = constants::TEXT_BOX_HEIGHT;
    src_rect_.w = constants::TEXT_BOX_WIDTH;
  } else {
    src_rect_.h = constants::WINDOW_SIZE;
    src_rect_.w = constants::WINDOW_SIZE;
  }
  src_rect_.x = 0;
  src_rect_.y = 0;
  dest_rect_.h = src_rect_.h;
  dest_rect_.w = src_rect_.w;
  dest_rect_.x = x_pos_;
  dest_rect_.y = y_pos_;
}

void Background::Render() {
  SDL_RenderCopy(Game::renderer_, background_texture_, &src_rect_, &dest_rect_);
}