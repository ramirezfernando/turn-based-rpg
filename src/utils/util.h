#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace Util {
std::string GetApiKey();
SDL_Texture* LoadTexture(const char* file_name);
void RenderInvertedTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest,
                           SDL_RendererFlip flip);
}  // namespace Util