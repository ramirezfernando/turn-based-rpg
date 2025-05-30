#pragma once

#include "game.h"

namespace Util {

SDL_Texture* LoadTexture(const char* file_name);
void RenderInvertedTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
}  // namespace Util