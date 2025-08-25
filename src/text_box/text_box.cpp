#include "text_box.h"
#include <game.h>
#include "constants/game_constants.h"
#include "utils/util.h"

TextBox::TextBox(const char* font_path, const char* background_path,
                 int font_size, int width, int height, int x_pos, int y_pos) {
  TTF_Init();
  font_ = TTF_OpenFont(font_path, font_size);
  box_texture_ = Util::LoadTexture(background_path);
  text_texture_ =
      Util::LoadText("1.Attack 2.Stats 3.Save 4.Run", font_, {0, 0, 0, 255});
  text_box_type_ = Type::BATTLE_OPTIONS;
  box_x_pos_ = x_pos;
  box_y_pos_ = y_pos;

  box_src_rect_.h = height;
  box_src_rect_.w = width;
  box_src_rect_.x = 0;
  box_src_rect_.y = 0;
  box_dest_rect_.h = box_src_rect_.h;
  box_dest_rect_.w = box_src_rect_.w;
  box_dest_rect_.x = box_x_pos_;
  box_dest_rect_.y = box_y_pos_;

  const int padding = 40;
  text_src_rect_.h = height - 2 * padding;
  text_src_rect_.w = width - 2 * padding;
  text_src_rect_.x = 0;
  text_src_rect_.y = 0;
  text_dest_rect_.h = box_src_rect_.h - 2 * padding;
  text_dest_rect_.w = box_src_rect_.w - 2 * padding;
  text_dest_rect_.x = box_x_pos_ + padding;
  text_dest_rect_.y = box_y_pos_ + padding;
}

TextBox::~TextBox() {
  SDL_DestroyTexture(text_texture_);
  SDL_DestroyTexture(box_texture_);
  TTF_CloseFont(font_);
  font_ = nullptr;
  std::clog << "Text Box destroyed" << std::endl;
}

void TextBox::Render() {
  if (!should_render_) {
    return;
  }
  SDL_RenderCopy(Game::renderer_, box_texture_, &box_src_rect_,
                 &box_dest_rect_);
  SDL_RenderCopy(Game::renderer_, text_texture_, &text_src_rect_,
                 &text_dest_rect_);
}

void TextBox::SetText(const std::string& text, SDL_Color color) {
  text_texture_ = Util::LoadText(text.c_str(), font_, color);
}

// This function does not change the text box type (unlike other setters)
// because we need to set the type separately for player and enemy selection.
void TextBox::SetCharacterSelection(bool is_enemy) {
  // Omitting full class names for brevity.
  if (is_enemy) {
    SetText("Enemy: 1.Priestess 2.Monk 3.Knight");
  } else {
    SetText("You: 1.Priestess 2.Monk 3.Knight");
  }
}

void TextBox::SetBattleOptions() {
  SetText("1.Attack 2.Stats 3.Save 4.Run");
  text_box_type_ = Type::BATTLE_OPTIONS;
}
void TextBox::SetBattleAttack() {
  SetText("1.Atk1 2.Atk2 3.Atk3 4.Atk4");
  text_box_type_ = Type::BATTLE_ATTACK;
}
void TextBox::SetBattleStats(Character* player) {
  std::string stats_text = "LVL:" + std::to_string(player->GetLevel()) +
                           " HP:" + std::to_string(player->GetHealth()) +
                           " EN:" + std::to_string(player->GetEnergy());
  SetText(stats_text);
  text_box_type_ = Type::BATTLE_STATS;
}
void TextBox::SetBattleRun() {
  SetText("1. Are you sure you want to run?");
  text_box_type_ = Type::BATTLE_RUN;
}
void TextBox::SetBattleSave() {
  std::string save_slots_text = "1. " + save_slots_text_[0];
  SetText(save_slots_text);
  text_box_type_ = Type::BATTLE_SAVE;
}

void TextBox::SetSaveSlotText(int slot, const std::string& text) {
  // Only 1 save slot is implemented for now.
  if (slot != 1) {
    std::cerr << "Invalid save slot: " << slot << std::endl;
    return;
  }
  save_slots_text_[slot - 1] = text;
}