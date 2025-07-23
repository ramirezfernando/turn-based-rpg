#include "game.h"

SDL_Renderer* Game::renderer_ = nullptr;
SDL_Event Game::event_;

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

  background_ = std::unique_ptr<Background>(
      new Background(constants::FOREST_BACKGROUND_FILE_PATH,
                     constants::WINDOW_SIZE, constants::WINDOW_SIZE));
  if (background_) {
    std::cout << "Background created" << std::endl;
  }

  text_box_ = std::unique_ptr<TextBox>(
      new TextBox(constants::TEXT_BOX_MAIN_FILE_PATH, constants::TEXT_BOX_WIDTH,
                  constants::TEXT_BOX_HEIGHT, constants::TEXT_BOX_X_POS,
                  constants::TEXT_BOX_Y_POS));
  if (text_box_) {
    std::cout << "Text box created" << std::endl;
  }

  text_box_v2_ = std::unique_ptr<TextBoxV2>(
      new TextBoxV2(constants::FONT_FILE_PATH, constants::FONT_SIZE,
                    constants::TEXT_BOX_WIDTH, constants::TEXT_BOX_HEIGHT,
                    constants::TEXT_BOX_X_POS, constants::TEXT_BOX_Y_POS));
  if (text_box_v2_) {
    std::cout << "Text box v2 created" << std::endl;
    text_box_v2_->SetFont(constants::FONT_FILE_PATH, constants::FONT_SIZE);
    text_box_v2_->SetText("Welcome to the Turn-Based RPG!");
  }

  player_ = std::unique_ptr<Character>(new WaterPriestess(/*is_enemy=*/false));
  if (player_) {
    std::cout << "Character created" << std::endl;
  }

  enemy_ = std::unique_ptr<Character>(new FireKnight(/*is_enemy=*/true));
  if (enemy_) {
    std::cout << "Enemy created" << std::endl;
  }

  is_player_turn_ = true;
  is_in_battle_ = false;
}

void Game::Update() {
  player_->Update();
  enemy_->Update();

  if (is_in_battle_) {
    // Check if player just finished attacking.
    if (!is_player_turn_ && !player_->IsAttacking() && !enemy_->IsAttacking() &&
        player_->IsAnimationComplete()) {
      constants::AttackType ai_decision = enemy_->GetAiDecision();
      switch (ai_decision) {
        case constants::AttackType::ATTACK1:
          enemy_->Attack1();
          std::cout << "Enemy choice (gpt-3.5-turbo): Attack 1" << std::endl;
          player_->TakeDamage(enemy_->GetAttack1Damage());
          break;
        case constants::AttackType::ATTACK2:
          enemy_->Attack2();
          std::cout << "Enemy choice (gpt-3.5-turbo): Attack 2" << std::endl;
          player_->TakeDamage(enemy_->GetAttack2Damage());
          break;
        case constants::AttackType::ATTACK3:
          enemy_->Attack3();
          std::cout << "Enemy choice (gpt-3.5-turbo): Attack 3" << std::endl;
          player_->TakeDamage(enemy_->GetAttack3Damage());
          break;
        case constants::AttackType::ATTACK4:
          enemy_->Attack4();
          std::cout << "Enemy choice (gpt-3.5-turbo): Attack 4" << std::endl;
          player_->TakeDamage(enemy_->GetAttack4Damage());
          break;
      }
      if (player_->GetHealth() <= 0 || player_->GetEnergy() <= 0) {
        player_->Death();
        is_running_ = false;
      } else {
        is_player_turn_ = true;
      }
    }
    // Check if enemy just finished attacking.
    if (is_player_turn_ && !player_->IsAttacking() && !enemy_->IsAttacking() &&
        enemy_->IsAnimationComplete()) {
      if (enemy_->GetHealth() <= 0 || enemy_->GetEnergy() <= 0) {
        enemy_->Death();
        is_running_ = false;
      } else {
        text_box_->SetImageFilePathAndLoadTexture(
            constants::TEXT_BOX_MAIN_FILE_PATH);
        is_in_battle_ = false;
      }
    }
  }
}

void Game::Render() {
  SDL_RenderClear(renderer_);
  background_->Render();
  //text_box_->Render();
  text_box_v2_->Render();
  player_->Render();
  enemy_->Render();
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
      if (is_player_turn_) {
        std::string current_text_box_file_path = text_box_->GetImageFilePath();
        if (current_text_box_file_path == constants::TEXT_BOX_MAIN_FILE_PATH) {
          HandleMenuEvents();
        } else if (current_text_box_file_path ==
                   constants::TEXT_BOX_ATTACK_FILE_PATH) {
          HandleAttackEvents();
        } else if (current_text_box_file_path ==
                   constants::TEXT_BOX_STATS_FILE_PATH) {
          HandleStatsEvents();
        } else if (current_text_box_file_path ==
                   constants::TEXT_BOX_RUN_FILE_PATH) {
          HandleRunEvents();
        } else if (current_text_box_file_path ==
                   constants::TEXT_BOX_SAVE_FILE_PATH) {
          HandleSaveEvents();
        }
      }
      break;
  }
}

void Game::HandleMenuEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_ATTACK_FILE_PATH);
      break;
    case SDLK_2:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_STATS_FILE_PATH);
      break;
    case SDLK_3:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_RUN_FILE_PATH);
      break;
    case SDLK_4:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_SAVE_FILE_PATH);
      break;
    default:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void Game::HandleAttackEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      text_box_->SetImageFilePathAndLoadTexture("");
      player_->Attack1();
      std::cout << "Player choice (me): Attack 1" << std::endl;
      enemy_->TakeDamage(player_->GetAttack1Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      break;
    case SDLK_2:
      text_box_->SetImageFilePathAndLoadTexture("");
      player_->Attack2();
      std::cout << "Player choice (me): Attack 2" << std::endl;
      enemy_->TakeDamage(player_->GetAttack2Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      break;
    case SDLK_3:
      text_box_->SetImageFilePathAndLoadTexture("");
      player_->Attack3();
      std::cout << "Player choice (me): Attack 3" << std::endl;
      enemy_->TakeDamage(player_->GetAttack3Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      break;
    case SDLK_4:
      text_box_->SetImageFilePathAndLoadTexture("");
      player_->Attack4();
      std::cout << "Player choice (me): Attack 4" << std::endl;
      enemy_->TakeDamage(player_->GetAttack4Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      break;
    default:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void Game::HandleStatsEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_STATS_FILE_PATH);
      std::cout << "Player --------------------------------" << std::endl;
      std::cout << "Level: " << player_->GetLevel() << std::endl;
      std::cout << "Health: " << player_->GetHealth() << std::endl;
      std::cout << "Energy: " << player_->GetEnergy() << std::endl;
      std::cout << "Enemy --------------------------------" << std::endl;
      std::cout << "Level: " << enemy_->GetLevel() << std::endl;
      std::cout << "Health: " << enemy_->GetHealth() << std::endl;
      std::cout << "Energy: " << enemy_->GetEnergy() << std::endl;
      std::cout << "--------------------------------" << std::endl;
      break;
    default:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void Game::HandleRunEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      SetIsRunning(false);
      break;
    case SDLK_2:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
    default:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}

void Game::HandleSaveEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      // TODO: Add SQLite database for saving/loading game state.
      std::cout << "Game saved!" << std::endl;
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
    default:
      text_box_->SetImageFilePathAndLoadTexture(
          constants::TEXT_BOX_MAIN_FILE_PATH);
      break;
  }
}