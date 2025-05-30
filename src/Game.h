#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>

class Game {
 public:
  ~Game();
  void Init(const char* title, int x_pos, int y_pos, int width, int height);
  void Update();
  void Render();
  void HandleEvents();
  void SetIsRunning(bool is_running) { is_running_ = is_running; }
  bool IsRunning() { return is_running_; }
  static SDL_Renderer* renderer_;
  static SDL_Event event_;

 private:
  SDL_Window* window_;
  bool is_running_;
};