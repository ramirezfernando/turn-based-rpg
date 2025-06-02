#include "util.h"
#include <fstream>

namespace Util {
std::string GetApiKey() {
  std::ifstream file("api_key.txt");
  std::string api_key;
  file >> api_key;
  file.close();
  return api_key;
}

SDL_Texture* Util::LoadTexture(const char* file_name) {
  SDL_Surface* tmp_surface = IMG_Load(file_name);
  SDL_Texture* texture =
      SDL_CreateTextureFromSurface(Game::renderer_, tmp_surface);
  SDL_FreeSurface(tmp_surface);
  return texture;
}

void Util::RenderInvertedTexture(SDL_Texture* texture, SDL_Rect src,
                                 SDL_Rect dest, SDL_RendererFlip flip) {
  SDL_RenderCopyEx(Game::renderer_, texture, &src, &dest, 0.0, NULL, flip);
}
}  // namespace Util