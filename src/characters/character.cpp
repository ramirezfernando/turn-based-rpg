#include "character.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

Character::~Character() {
  SDL_DestroyTexture(character_texture_);
  std::cout << "Character destroyed" << std::endl;
}

void Character::Update() {
  src_rect_.h = constants::CHARACTER_HEIGHT;
  src_rect_.w = constants::CHARACTER_WIDTH;
  src_rect_.x = 0;
  src_rect_.y = 0;
  dest_rect_.x = x_pos_;
  dest_rect_.y = y_pos_;
  dest_rect_.h = src_rect_.h * 2;
  dest_rect_.w = src_rect_.w * 2;

  Uint32 current_time = SDL_GetTicks();
  if (current_time > last_frame_time_ + delay_) {
    if (count_ < frames_) {
      std::string filename =
          folder_path_ + "/" + std::to_string(count_) + ".png";
      const char* file = filename.c_str();
      character_texture_ = Util::LoadTexture(file);
      count_++;
    } else {
      // This ensures that the character returns to an idle state after
      // performing an action (attack, defend, etc.) and that the idle animation
      // is played only once after the action is completed.
      this->Idle();
      this->Update();
    }
    last_frame_time_ = current_time;
  }
}

void Character::Render() {
  if (is_enemy_) {
    Util::RenderInvertedTexture(character_texture_, src_rect_, dest_rect_,
                                SDL_FLIP_HORIZONTAL);
  } else {
    SDL_RenderCopy(Game::renderer_, character_texture_, &src_rect_,
                   &dest_rect_);
  }
}