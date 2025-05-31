#pragma once

#include "game.h"

class Background {
 public:
  Background(const char* file_path, int x_pos, int y_pos, bool is_text_box);
  ~Background();
  void Update();
  void Render();

  void SetImageFilePath(std::string file_path) { file_path_ = file_path; }
  std::string GetImageFilePath() { return file_path_; }

 private:
  SDL_Texture* background_texture_;
  SDL_Rect src_rect_, dest_rect_;
  int x_pos_, y_pos_;
  std::string file_path_;
  bool is_text_box_;
};