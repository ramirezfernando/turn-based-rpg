#include "game.h"
#include "background/background.h"
#include "characters/character.h"
#include "characters/fire_knight.h"
#include "characters/ground_monk.h"
#include "characters/water_priestess.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

SDL_Renderer* Game::renderer_ = nullptr;
SDL_Event Game::event_;
std::unique_ptr<Background> forest;
std::unique_ptr<Background> text_box;
std::unique_ptr<Character> player;
std::unique_ptr<Character> enemy;

// Helper functions to handle events based on the current text box displayed.
void handleMenuEvents(SDL_Event& event, std::unique_ptr<Background>& text_box);
void handleAttackEvents(SDL_Event& event, std::unique_ptr<Background>& text_box,
                        std::unique_ptr<Character>& player,
                        std::unique_ptr<Character>& enemy, bool& player_turn,
                        bool& is_in_battle);
void handleStatsEvents(SDL_Event& event, std::unique_ptr<Background>& text_box,
                       std::unique_ptr<Character>& player,
                       std::unique_ptr<Character>& enemy);
void printStats(std::unique_ptr<Character>& player,
                std::unique_ptr<Character>& enemy);
void handleRunEvents(SDL_Event& event, std::unique_ptr<Background>& text_box,
                     Game* game);
void handleSaveEvents(SDL_Event& event, std::unique_ptr<Background>& text_box);

Game::~Game() {
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
  SDL_Quit();
  IMG_Quit();
  std::cout << "Game destroyed" << std::endl;
}

void Game::Init(const char* title, int x_pos, int y_pos, int width,
                int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    window_ = SDL_CreateWindow(title, x_pos, y_pos, width, height, 0);
    if (window_) {
      std::cout << "Window created" << std::endl;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
    if (renderer_) {
      SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
      std::cout << "Renderer created" << std::endl;
    }
    is_running_ = true;
  } else {
    is_running_ = false;
  }

  forest = std::unique_ptr<Background>(
      new Background(constants::FOREST_BACKGROUND_FILE_PATH, 0, 0,
                     /*is_text_box=*/false));
  if (forest) {
    std::cout << "Forest created" << std::endl;
  }
  text_box = std::unique_ptr<Background>(new Background(
      constants::TEXT_BOX_MAIN_FILE_PATH, constants::TEXT_BOX_X_POS,
      constants::TEXT_BOX_Y_POS, /*is_text_box=*/true));
  if (text_box) {
    std::cout << "Text box created" << std::endl;
  }
  player = std::unique_ptr<Character>(
      new WaterPriestess("Player", /*is_enemy=*/false));
  if (player) {
    std::cout << "Character created" << std::endl;
  }
  enemy =
      std::unique_ptr<Character>(new FireKnight("Enemy", /*is_enemy=*/true));
  if (enemy) {
    std::cout << "Enemy created" << std::endl;
  }
}

void Game::Update() {
  player->Update();
  enemy->Update();

  if (is_in_battle_) {
    // Check if player just finished attacking.
    if (!player_turn_ && !player->IsAttacking() && !enemy->IsAttacking() &&
        player->IsAnimationComplete()) {
      constants::AttackType ai_decision = enemy->GetAiDecision();
      switch (ai_decision) {
        case constants::AttackType::ATTACK1:
          enemy->Attack1();
          player->TakeDamage(enemy->GetAttack1Damage());
          break;
        case constants::AttackType::ATTACK2:
          enemy->Attack2();
          player->TakeDamage(enemy->GetAttack2Damage());
          break;
        case constants::AttackType::ATTACK3:
          enemy->Attack3();
          player->TakeDamage(enemy->GetAttack3Damage());
          break;
        case constants::AttackType::ATTACK4:
          enemy->Attack4();
          player->TakeDamage(enemy->GetAttack4Damage());
          break;
      }
      if (player->GetHealth() <= 0 || player->GetEnergy() <= 0) {
        player->Death();
        is_running_ = false;
        printStats(player, enemy);
      } else {
        player_turn_ = true;
      }
    }
    // Check if enemy just finished attacking.
    if (player_turn_ && !player->IsAttacking() && !enemy->IsAttacking() &&
        enemy->IsAnimationComplete()) {
      if (enemy->GetHealth() <= 0 || enemy->GetEnergy() <= 0) {
        enemy->Death();
        printStats(player, enemy);
        is_running_ = false;
      } else {
        text_box->SetImageFilePathAndLoadTexture(
            constants::TEXT_BOX_MAIN_FILE_PATH);
        is_in_battle_ = false;
      }
    }
  }
}

void Game::Render() {
  SDL_RenderClear(renderer_);
  forest->Render();
  text_box->Render();
  player->Render();
  enemy->Render();
  // Double buffering.
  SDL_RenderPresent(renderer_);
}

void Game::HandleEvents() {
  SDL_PollEvent(&event_);
  switch (event_.type) {
    case SDL_QUIT:
      is_running_ = false;
      break;
    case SDL_KEYDOWN:
      if (player_turn_) {
        std::string current_text_box_file_path = text_box->GetImageFilePath();
        if (current_text_box_file_path == constants::TEXT_BOX_MAIN_FILE_PATH) {
          handleMenuEvents(event_, text_box);
        } else if (current_text_box_file_path ==
                   constants::TEXT_BOX_ATTACK_FILE_PATH) {
          handleAttackEvents(event_, text_box, player, enemy, player_turn_,
                             is_in_battle_);
        } else if (current_text_box_file_path ==
                   constants::TEXT_BOX_STATS_FILE_PATH) {
          handleStatsEvents(event_, text_box, player, enemy);
        } else if (current_text_box_file_path ==
                   constants::TEXT_BOX_RUN_FILE_PATH) {
          handleRunEvents(event_, text_box, this);
        } else if (current_text_box_file_path ==
                   constants::TEXT_BOX_SAVE_FILE_PATH) {
          handleSaveEvents(event_, text_box);
        }
      }
      break;
  }
}

void handleMenuEvents(SDL_Event& event, std::unique_ptr<Background>& text_box) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_ATTACK_FILE_PATH);
      break;
    case SDLK_2:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_STATS_FILE_PATH);
      break;
    case SDLK_3:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_RUN_FILE_PATH);
      break;
    case SDLK_4:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_SAVE_FILE_PATH);
      break;
    default:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void handleAttackEvents(SDL_Event& event, std::unique_ptr<Background>& text_box,
                        std::unique_ptr<Character>& player,
                        std::unique_ptr<Character>& enemy, bool& player_turn,
                        bool& is_in_battle) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      // This ensures that the text box is not visible when the player attacks.
      // The text box is re-enabled after the enemy's animation is complete.
      text_box->SetImageFilePathAndLoadTexture("");
      player->Attack1();
      enemy->TakeDamage(player->GetAttack1Damage());
      player_turn = false;
      is_in_battle = true;
      break;
    case SDLK_2:
      // This ensures that the text box is not visible when the player attacks.
      // The text box is re-enabled after the enemy's animation is complete.
      text_box->SetImageFilePathAndLoadTexture("");
      player->Attack2();
      enemy->TakeDamage(player->GetAttack2Damage());
      player_turn = false;
      is_in_battle = true;
      break;
    case SDLK_3:
      // This ensures that the text box is not visible when the player attacks.
      // The text box is re-enabled after the enemy's animation is complete.
      text_box->SetImageFilePathAndLoadTexture("");
      player->Attack3();
      enemy->TakeDamage(player->GetAttack3Damage());
      player_turn = false;
      is_in_battle = true;
      break;
    case SDLK_4:
      // This ensures that the text box is not visible when the player attacks.
      // The text box is re-enabled after the enemy's animation is complete.
      text_box->SetImageFilePathAndLoadTexture("");
      player->Attack4();
      enemy->TakeDamage(player->GetAttack4Damage());
      player_turn = false;
      is_in_battle = true;
      break;
    default:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void handleStatsEvents(SDL_Event& event, std::unique_ptr<Background>& text_box,
                       std::unique_ptr<Character>& player,
                       std::unique_ptr<Character>& enemy) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_STATS_FILE_PATH);
      printStats(player, enemy);
      break;
    default:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void printStats(std::unique_ptr<Character>& player,
                std::unique_ptr<Character>& enemy) {
  std::cout << "--------------------------------" << std::endl;
  std::cout << "Player: " << player->GetUsername() << std::endl;
  std::cout << "Level: " << player->GetLevel() << std::endl;
  std::cout << "Health: " << player->GetHealth() << std::endl;
  std::cout << "Energy: " << player->GetEnergy() << std::endl;
  std::cout << "--------------------------------" << std::endl;
  std::cout << "Enemy: " << enemy->GetUsername() << std::endl;
  std::cout << "Level: " << enemy->GetLevel() << std::endl;
  std::cout << "Health: " << enemy->GetHealth() << std::endl;
  std::cout << "Energy: " << enemy->GetEnergy() << std::endl;
  std::cout << "--------------------------------" << std::endl;
}

void handleRunEvents(SDL_Event& event, std::unique_ptr<Background>& text_box,
                     Game* game) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      game->SetIsRunning(false);
      break;
    case SDLK_2:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
    default:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void handleSaveEvents(SDL_Event& event, std::unique_ptr<Background>& text_box) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      // Implement save functionality here
      std::cout << "Game saved!" << std::endl;
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
    default:
      text_box->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}