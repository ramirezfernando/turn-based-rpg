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
      Util::LoadText("1.Attack 2.Stats 3.Run 4.Save", font_, {0, 0, 0, 255});
  text_box_type_ = constants::TextBoxType::MAIN;
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
  SDL_RenderCopy(Game::renderer_, box_texture_, &box_src_rect_,
                 &box_dest_rect_);
  SDL_RenderCopy(Game::renderer_, text_texture_, &text_src_rect_,
                 &text_dest_rect_);
}

void TextBox::SetText(const std::string& text, SDL_Color color) {
  text_texture_ = Util::LoadText(text.c_str(), font_, color);
}

void TextBox::SetMainMenu() {
  SetText("1.Attack 2.Stats 3.Run 4.Save");
  text_box_type_ = constants::TextBoxType::MAIN;
}
void TextBox::SetAttackMenu() {
  SetText("1.Atk1 2.Atk2 3.Atk3 4.Atk4");
  text_box_type_ = constants::TextBoxType::ATTACK;
}
void TextBox::SetStatsMenu(Character* player) {
  std::string stats_text = "LVL:" + std::to_string(player->GetLevel()) +
                           " HP:" + std::to_string(player->GetHealth()) +
                           " EN:" + std::to_string(player->GetEnergy());
  SetText(stats_text);
  text_box_type_ = constants::TextBoxType::STATS;
}
void TextBox::SetRunMenu() {
  SetText("1.Run 2.Back");
  text_box_type_ = constants::TextBoxType::RUN;
}
void TextBox::SetSaveMenu() {
  SetText("1.Save 2.Back");
  text_box_type_ = constants::TextBoxType::SAVE;
}