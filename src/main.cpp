#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "constants/game_constants.h"
#include "game.h"

int main() {
  Uint32 frame_start;
  int frame_time;
  std::unique_ptr<Game> game(new Game());
  game->Init("TURN-BASED-RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             constants::WINDOW_SIZE, constants::WINDOW_SIZE);

  while (game->IsRunning()) {
    frame_start = SDL_GetTicks();
    game->Update();
    game->Render();
    game->HandleEvents();

    // Handles frame rate
    frame_time = SDL_GetTicks() - frame_start;
    if (constants::FRAME_DELAY > frame_time) {
      SDL_Delay(constants::FRAME_DELAY - frame_time);
    }
  }
  return 0;
}