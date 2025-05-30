#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "constants/game_constants.h"
#include "game.h"

int main() {
  Uint32 frame_start;
  int frame_time;
  // Once out of scope, the destructor will be called since it is a `unique_ptr`
  std::unique_ptr<Game> game(new Game());

  // Create the window
  game->Init("TURN-BASED-RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             Constants::WINDOW_SIZE, Constants::WINDOW_SIZE);

  // Game loop
  while (game->IsRunning()) {
    frame_start = SDL_GetTicks();
    game->Update();
    game->Render();
    game->HandleEvents();

    // Handles frame rate
    frame_time = SDL_GetTicks() - frame_start;
    if (Constants::FRAME_DELAY > frame_time) {
      SDL_Delay(Constants::FRAME_DELAY - frame_time);
    }
  }
  return 0;
}