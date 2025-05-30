#pragma once

#include "game.h"

class Background {
 public:
 Background(const char* background, int xpos, int ypos, bool text);
 ~Background();
  void Update();
  void Render();

  void SetPath(std::string );
  std::string GetPath();

 private:
 SDL_Texture* backgroundTexture;
 SDL_Rect src_rect_, dest_rect_;
 int xpos;
 int ypos;
 bool text;
 std::string path;

};