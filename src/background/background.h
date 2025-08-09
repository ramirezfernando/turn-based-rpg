#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

// The class is responsible for rendering the background in the game. Owned by
// the `Game` class.
class Background {
 public:
  Background(const char* file_path, int width, int height);
  ~Background();
  void Render();
  void SetImageFilePathAndLoadTexture(const char* file_path);
  std::string GetImageFilePath() { return file_path_; }

 private:
  SDL_Texture* background_texture_;
  SDL_Rect src_rect_, dest_rect_;
  int x_pos_, y_pos_;
  std::string file_path_;
};