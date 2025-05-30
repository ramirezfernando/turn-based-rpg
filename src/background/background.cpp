#include "background.h"
#include "constants/game_constants.h"
#include "utils/util.h"

Background::Background(const char* background, int x, int y, bool _text)
{
    // Loads texture with the help of the Textures class
    backgroundTexture = Util::LoadTexture(background);
    xpos = x;
    ypos = y;
    text = _text;
    path = std::string(background);
}

Background::~Background() {
  SDL_DestroyTexture(backgroundTexture);
  std::cout << "Background destroyed" << std::endl;
}

void Background::Update() {
  src_rect_.w = Constants::WINDOW_SIZE;
  src_rect_.h = Constants::WINDOW_SIZE;
  src_rect_.x = 0;
  src_rect_.y = 0;
  dest_rect_.h = src_rect_.h;
  dest_rect_.w = src_rect_.w;
  dest_rect_.x = xpos;
  dest_rect_.y = ypos;
}

void Background::Render() {
  SDL_RenderCopy(Game::renderer_, backgroundTexture, &src_rect_, &dest_rect_);
}

void Background::SetPath(std::string _path)
{
    path = _path;
}
std::string Background::GetPath()
{
    return path;
}