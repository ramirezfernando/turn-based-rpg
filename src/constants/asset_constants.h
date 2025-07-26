#pragma once

namespace constants {
// Use `extern` to prevent internal linkage, meaning that source files will only
// have one instance of the variable that is shared across all source files that
// include the header file.
// Not using `extern` would result in copying the variable for each source file
// that includes the header file. This would result in multiple instances of the
// variable, which is not ideal.
// Note: `extern` needs to be used with a declaration in a header file, and the
// variable needs to be defined in a source file.
extern const char* FOREST_BACKGROUND_FILE_PATH;

extern const char* FIRE_KNIGHT_ATTACK_1_FOLDER_PATH;
extern const int FIRE_KNIGHT_ATTACK_1_NUM_FRAMES;
extern const char* FIRE_KNIGHT_ATTACK_2_FOLDER_PATH;
extern const int FIRE_KNIGHT_ATTACK_2_NUM_FRAMES;
extern const char* FIRE_KNIGHT_ATTACK_3_FOLDER_PATH;
extern const int FIRE_KNIGHT_ATTACK_3_NUM_FRAMES;
extern const char* FIRE_KNIGHT_ATTACK_4_FOLDER_PATH;
extern const int FIRE_KNIGHT_ATTACK_4_NUM_FRAMES;
extern const char* FIRE_KNIGHT_DEATH_FOLDER_PATH;
extern const int FIRE_KNIGHT_DEATH_NUM_FRAMES;
extern const char* FIRE_KNIGHT_DEFEND_FOLDER_PATH;
extern const int FIRE_KNIGHT_DEFEND_NUM_FRAMES;
extern const char* FIRE_KNIGHT_IDLE_FOLDER_PATH;
extern const int FIRE_KNIGHT_IDLE_NUM_FRAMES;
extern const char* FIRE_KNIGHT_TAKE_DAMAGE_FOLDER_PATH;
extern const int FIRE_KNIGHT_TAKE_DAMAGE_NUM_FRAMES;

extern const char* GROUND_MONK_ATTACK_1_FOLDER_PATH;
extern const int GROUND_MONK_ATTACK_1_NUM_FRAMES;
extern const char* GROUND_MONK_ATTACK_2_FOLDER_PATH;
extern const int GROUND_MONK_ATTACK_2_NUM_FRAMES;
extern const char* GROUND_MONK_ATTACK_3_FOLDER_PATH;
extern const int GROUND_MONK_ATTACK_3_NUM_FRAMES;
extern const char* GROUND_MONK_ATTACK_4_FOLDER_PATH;
extern const int GROUND_MONK_ATTACK_4_NUM_FRAMES;
extern const char* GROUND_MONK_DEATH_FOLDER_PATH;
extern const int GROUND_MONK_DEATH_NUM_FRAMES;
extern const char* GROUND_MONK_DEFEND_FOLDER_PATH;
extern const int GROUND_MONK_DEFEND_NUM_FRAMES;
extern const char* GROUND_MONK_IDLE_FOLDER_PATH;
extern const int GROUND_MONK_IDLE_NUM_FRAMES;
extern const char* GROUND_MONK_MEDITATE_FOLDER_PATH;
extern const char* GROUND_MONK_TAKE_DAMAGE_FOLDER_PATH;
extern const int GROUND_MONK_TAKE_DAMAGE_NUM_FRAMES;

extern const char* WATER_PRIESTESS_ATTACK_1_FOLDER_PATH;
extern const int WATER_PRIESTESS_ATTACK_1_NUM_FRAMES;
extern const char* WATER_PRIESTESS_ATTACK_2_FOLDER_PATH;
extern const int WATER_PRIESTESS_ATTACK_2_NUM_FRAMES;
extern const char* WATER_PRIESTESS_ATTACK_3_FOLDER_PATH;
extern const int WATER_PRIESTESS_ATTACK_3_NUM_FRAMES;
extern const char* WATER_PRIESTESS_ATTACK_4_FOLDER_PATH;
extern const int WATER_PRIESTESS_ATTACK_4_NUM_FRAMES;
extern const char* WATER_PRIESTESS_DEATH_FOLDER_PATH;
extern const int WATER_PRIESTESS_DEATH_NUM_FRAMES;
extern const char* WATER_PRIESTESS_DEFEND_FOLDER_PATH;
extern const int WATER_PRIESTESS_DEFEND_NUM_FRAMES;
extern const char* WATER_PRIESTESS_HEAL_FOLDER_PATH;
extern const char* WATER_PRIESTESS_IDLE_FOLDER_PATH;
extern const int WATER_PRIESTESS_IDLE_NUM_FRAMES;
extern const char* WATER_PRIESTESS_TAKE_DAMAGE_FOLDER_PATH;
extern const int WATER_PRIESTESS_TAKE_DAMAGE_NUM_FRAMES;

extern const char* TEXT_BOX_BACKGROUND_FILE_PATH;
extern const char* FONT_FILE_PATH;
}  // namespace constants