#include "game.h"
#include "background/background.h"
#include "characters/character.h"
#include "characters/fire_knight.h"
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

SDL_Renderer* Game::renderer_ = nullptr;
SDL_Event Game::event_;
std::unique_ptr<Background> forest;
std::unique_ptr<Background> textBox;
std::unique_ptr<Character> player;
std::unique_ptr<Character> enemy;

// Helper functions to handle events based on the text box that is displayed
void handleMenuEvents(SDL_Event& event, std::unique_ptr<Background>& textBox);
void handleAttackEvents(SDL_Event& event, std::unique_ptr<Background>& textBox,
                        std::unique_ptr<Character>& player,
                        std::unique_ptr<Character>& enemy);
void handleStatsEvents(SDL_Event& event, std::unique_ptr<Background>& textBox,
                       std::unique_ptr<Character>& player);
void handleRunEvents(SDL_Event& event, std::unique_ptr<Background>& textBox,
                     Game* game);

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
  textBox = std::unique_ptr<Background>(new Background(
      constants::TEXT_BOX_MAIN_FILE_PATH, 100, 607, /*is_text_box=*/true));
  if (textBox) {
    std::cout << "Text box created" << std::endl;
  }
  player =
      std::unique_ptr<Character>(new FireKnight(/*is_enemy=*/false, "Player"));
  if (player) {
    std::cout << "Character created" << std::endl;
  }
  enemy = std::unique_ptr<Character>(new FireKnight(/*is_enemy=*/true, "Bot"));
  if (enemy) {
    std::cout << "Enemy created" << std::endl;
  }
}

void Game::Update() {
  forest->Update();
  textBox->Update();
  player->Update();
  enemy->Update();
}

void Game::Render() {
  SDL_RenderClear(renderer_);
  forest->Render();
  textBox->Render();
  player->Render();
  enemy->Render();
  SDL_RenderPresent(renderer_);  // Double buffering
}

void Game::HandleEvents() {
  SDL_PollEvent(&event_);
  switch (event_.type) {
    case SDL_QUIT:
      is_running_ = false;
      break;
    case SDL_KEYDOWN:
      if (player_turn_) {
        if (textBox->GetImageFilePath() == constants::TEXT_BOX_MAIN_FILE_PATH) {
          handleMenuEvents(event_, textBox);
        } else if (textBox->GetImageFilePath() ==
                   constants::TEXT_BOX_ATTACK_FILE_PATH) {
          handleAttackEvents(event_, textBox, player, enemy);
          player_turn_ = false;
          textBox->SetImageFilePath(
              std::string(constants::TEXT_BOX_MAIN_FILE_PATH));
        } else if (textBox->GetImageFilePath() ==
                   constants::TEXT_BOX_STATS_FILE_PATH) {
          handleStatsEvents(event_, textBox, player);
        } else if (textBox->GetImageFilePath() ==
                   constants::TEXT_BOX_RUN_FILE_PATH) {
          handleRunEvents(event_, textBox, this);
        }
      } else {
        if (textBox->GetImageFilePath() == constants::TEXT_BOX_MAIN_FILE_PATH) {
          handleMenuEvents(event_, textBox);
        } else if (textBox->GetImageFilePath() ==
                   constants::TEXT_BOX_ATTACK_FILE_PATH) {
          handleAttackEvents(event_, textBox, enemy, player);
          player_turn_ = true;
          textBox->SetImageFilePath(
              std::string(constants::TEXT_BOX_MAIN_FILE_PATH));
        } else if (textBox->GetImageFilePath() ==
                   constants::TEXT_BOX_STATS_FILE_PATH) {
          handleStatsEvents(event_, textBox, enemy);
        } else if (textBox->GetImageFilePath() ==
                   constants::TEXT_BOX_RUN_FILE_PATH) {
          handleRunEvents(event_, textBox, this);
        }
      }
      break;
  }
}

void handleMenuEvents(SDL_Event& event, std::unique_ptr<Background>& textBox) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      textBox->SetImageFilePath(
          std::string(constants::TEXT_BOX_ATTACK_FILE_PATH));
      break;
    case SDLK_2:
      textBox->SetImageFilePath(
          std::string(constants::TEXT_BOX_STATS_FILE_PATH));
      break;
    case SDLK_3:
      textBox->SetImageFilePath(std::string(constants::TEXT_BOX_RUN_FILE_PATH));
      break;
    case SDLK_4:
      textBox->SetImageFilePath(
          std::string(constants::TEXT_BOX_SAVE_FILE_PATH));
      break;
    default:
      textBox->SetImageFilePath(constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void handleAttackEvents(SDL_Event& event, std::unique_ptr<Background>& textBox,
                        std::unique_ptr<Character>& player,
                        std::unique_ptr<Character>& enemy) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      player->Attack1();
      enemy->TakeDamage(2 * player->GetLevel());

      if (enemy->GetHealth() <= 0) {
        enemy->Death();
      }
      player->SetLevel(player->GetLevel() + 1);

      // Wait for attack and take damage animations to finish before going back to idle
      break;
    case SDLK_2:
      player->Attack2();
      enemy->TakeDamage(4 * player->GetLevel());

      if (enemy->GetHealth() <= 0) {
        enemy->Death();
      }
      player->SetLevel(player->GetLevel() + 1);
      break;
    case SDLK_3:
      player->Attack3();
      enemy->TakeDamage(8 * player->GetLevel());

      if (enemy->GetHealth() <= 0) {
        enemy->Death();
      }
      player->SetLevel(player->GetLevel() + 2);
      player->SetEnergy(player->GetEnergy() - 4);
      break;
    case SDLK_4:
      player->Attack4();
      enemy->TakeDamage(10 * player->GetLevel());

      if (enemy->GetHealth() <= 0) {
        enemy->Death();
      }
      player->SetLevel(player->GetLevel() + 3);
      player->SetEnergy(player->GetEnergy() - 8);
      break;
    default:
      textBox->SetImageFilePath(std::string(
          constants::
              TEXT_BOX_MAIN_FILE_PATH));  // if you press any key it will go back to the main text box
      break;
  }
}
void handleStatsEvents(SDL_Event& event, std::unique_ptr<Background>& textBox,
                       std::unique_ptr<Character>& player) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      player->PrintStats();
      break;
    default:
      textBox->SetImageFilePath(std::string(
          constants::
              TEXT_BOX_MAIN_FILE_PATH));  // if you press any key it will go back to the main text box
      break;
  }
}
void handleRunEvents(SDL_Event& event, std::unique_ptr<Background>& textBox,
                     Game* game) {
  switch (event.key.keysym.sym) {
    case SDLK_1:
      game->SetIsRunning(false);
      break;
    case SDLK_2:
      textBox->SetImageFilePath(std::string(
          constants::
              TEXT_BOX_MAIN_FILE_PATH));  // if you press any key it will go back to the main text box
      break;
    default:
      textBox->SetImageFilePath(std::string(
          constants::
              TEXT_BOX_MAIN_FILE_PATH));  // if you press any key it will go back to the main text box
      break;
  }
}