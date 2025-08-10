#include "util.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include "game.h"

namespace Util {
std::string GetApiKey() {
  std::ifstream file("api_key.txt");
  std::string api_key;
  file >> api_key;
  file.close();
  return api_key;
}

std::string GetLocalTime() {
  auto t = std::time(nullptr);
  std::tm local_tm;
  localtime_r(&t, &local_tm);
  std::ostringstream oss;
  // Returns the local time in 12-hour format.
  oss << std::put_time(&local_tm, "%Y-%m-%d %I:%M:%S %p");
  std::string local_timestamp = oss.str();
  return local_timestamp;
}

SDL_Texture* LoadTexture(const char* file_name) {
  SDL_Surface* tmp_surface = IMG_Load(file_name);
  SDL_Texture* texture =
      SDL_CreateTextureFromSurface(Game::renderer_, tmp_surface);
  SDL_FreeSurface(tmp_surface);
  return texture;
}

SDL_Texture* LoadText(const char* text, TTF_Font* font, SDL_Color color) {
  SDL_Surface* tmp_surface = TTF_RenderText_Solid(font, text, color);
  SDL_Texture* texture =
      SDL_CreateTextureFromSurface(Game::renderer_, tmp_surface);
  SDL_FreeSurface(tmp_surface);
  return texture;
}

void RenderInvertedTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest,
                           SDL_RendererFlip flip) {
  SDL_RenderCopyEx(Game::renderer_, texture, &src, &dest, 0.0, NULL, flip);
}
}  // namespace Util