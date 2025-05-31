#include "game_constants.h"

namespace Constants {
const int WINDOW_SIZE = 736;  // The size of the GUI window (736 x 736)
const int TEXT_BOX_WIDTH = 640;  // The width of the text box (640 pixels)
const int TEXT_BOX_HEIGHT = 128;  // The height of the text box (128 pixels)
const int FRAME_DELAY =
    1000 / 30;  // The number of milliseconds in a second divided by FPS
const int CHARACTER_SIZE = 64;  // The size of the character (64 x 64)
const int CHARACTER_MOVEMENT_GAP =
    20;                            // The number of pixels to move the character
const int ENEMY_MOVEMENT_GAP = 2;  // The number of pixels to move the enemy
const int ENEMY_SIZE = 96;         // The size of the enemy (96 x 96)
const int ATTACK_RANGE = 100;
}  // namespace Constants