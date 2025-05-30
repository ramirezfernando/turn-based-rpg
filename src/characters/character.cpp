#include "character.h"
#include "utils/util.h"

void Character::Update() 
{

    srcRect.h = 220; //200
    srcRect.w = 320; //300
    
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;

    // implement movement animation
    Uint32 current_time = SDL_GetTicks();
    if (current_time > last_frame_time_ + delay_) {
        if (count < frames) {
          string filename = path+"/"+ to_string(count) + ".png";
          const char* file = filename.c_str();
          characterTexture = Util::LoadTexture(file);
          count++;
        } else {
          count = 1;
        }
        last_frame_time_ = current_time;
    }
}


void Character::Render()
{
    // if enemy then the image needs to be inverted to face the other player
    if (enemy) {
        Util::RenderInvertedTexture(characterTexture, srcRect, destRect, SDL_FLIP_HORIZONTAL);
    }
    else {
        SDL_RenderCopy(Game::renderer_, characterTexture, &srcRect, &destRect);
    }
    
}

void Character::Clean()
{
    SDL_DestroyTexture(characterTexture);
}
// Setters 
void Character::SetTexture(const char* texture)
{
    characterTexture = Util::LoadTexture(texture);
}
void Character::SetSourceRect(SDL_Rect src)
{
    srcRect = src;
}
void Character::SetDestinationRect(SDL_Rect dest)
{
    destRect = dest;
}
void Character::SetXPos(int x)
{
    xpos = x;
}
void Character::SetYPos(int y)
{
    ypos = y;
}
void Character::SetPath(string _path)
{
    path = _path;
}
void Character::SetFrames(int _frames)
{
    frames = _frames;
}
void Character::SetSpeed(int _speed)
{
    speed = _speed;
}
void Character::SetCount(int _count)
{
    count = _count;
}

void Character::SetName(string _name)
{
    name = _name;
}
void Character::SetLevel(int _level)
{
    level = _level;
}
void Character::SetHealth(int _health)
{
    // In order for health to not go lower than zero
    if (_health <= 0){
        health = 0;
    }
    else {
        health = _health;
    }
}
void Character::setCharacterType(string _characterType)
{
    characterType = _characterType;
}
void Character::SetEnemy(bool _enemy)
{
    enemy = _enemy;
}

// Getters
string Character::GetPath()
{
    return path;
}
int Character::GetFrames()
{
    return frames;
}
int Character::GetSpeed()
{
    return speed;
}
int Character::GetCount()
{
    return count;
}

string Character::GetName()
{
    return name;
}
int Character::GetLevel()
{
    return level;
}
int Character::GetHealth()
{
    return health;
}
string Character::getCharacterType()
{
    return characterType;
}
bool Character::GetEnemy()
{
    return enemy;
}