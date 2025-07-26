#include "game.h"

SDL_Renderer* Game::renderer_ = nullptr;
SDL_Event Game::event_;

Game::~Game() {
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
  SDL_Quit();
  IMG_Quit();
  std::clog << "Game destroyed" << std::endl;
}

void Game::Init(const char* title, int x_pos, int y_pos, int width,
                int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    window_ = SDL_CreateWindow(title, x_pos, y_pos, width, height, 0);
    if (window_) {
      std::clog << "Window created" << std::endl;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
    if (renderer_) {
      std::clog << "Renderer created" << std::endl;
    }
    is_running_ = true;
  } else {
    is_running_ = false;
  }

  background_ = std::unique_ptr<Background>(
      new Background(constants::FOREST_BACKGROUND_FILE_PATH,
                     constants::WINDOW_SIZE, constants::WINDOW_SIZE));
  if (background_) {
    std::clog << "Background created" << std::endl;
  }

  text_box_ = std::unique_ptr<TextBox>(new TextBox(
      constants::FONT_FILE_PATH, constants::TEXT_BOX_BACKGROUND_FILE_PATH,
      constants::FONT_SIZE, constants::TEXT_BOX_WIDTH,
      constants::TEXT_BOX_HEIGHT, constants::TEXT_BOX_X_POS,
      constants::TEXT_BOX_Y_POS));
  if (text_box_) {
    std::clog << "Text box created" << std::endl;
    should_render_text_box_ = true;
  }

  player_ = std::unique_ptr<Character>(new WaterPriestess(/*is_enemy=*/false));
  if (player_) {
    std::clog << "Character created" << std::endl;
  }

  enemy_ = std::unique_ptr<Character>(new FireKnight(/*is_enemy=*/true));
  if (enemy_) {
    std::clog << "Enemy created" << std::endl;
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
          player_->TakeDamage(enemy_->GetAttack1Damage());
          break;
        case constants::AttackType::ATTACK2:
          enemy_->Attack2();
          player_->TakeDamage(enemy_->GetAttack2Damage());
          break;
        case constants::AttackType::ATTACK3:
          enemy_->Attack3();
          player_->TakeDamage(enemy_->GetAttack3Damage());
          break;
        case constants::AttackType::ATTACK4:
          enemy_->Attack4();
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
        should_render_text_box_ = true;
        text_box_->SetMainMenu();
        is_in_battle_ = false;
      }
    }
  }
}

void Game::Render() {
  SDL_RenderClear(renderer_);
  background_->Render();
  if (should_render_text_box_) {
    text_box_->Render();
  }
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
        constants::TextBoxType current_text_box_type =
            text_box_->GetTextBoxType();
        switch (current_text_box_type) {
          case constants::TextBoxType::MAIN:
            HandleMenuEvents();
            break;
          case constants::TextBoxType::ATTACK:
            HandleAttackEvents();
            break;
          case constants::TextBoxType::STATS:
            HandleStatsEvents();
            break;
          case constants::TextBoxType::RUN:
            HandleRunEvents();
            break;
          case constants::TextBoxType::SAVE:
            HandleSaveEvents();
            break;
        }
      }
      break;
  }
}

void Game::HandleMenuEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      text_box_->SetAttackMenu();
      break;
    case SDLK_2:
      text_box_->SetStatsMenu(player_.get());
      break;
    case SDLK_3:
      text_box_->SetRunMenu();
      break;
    case SDLK_4:
      text_box_->SetSaveMenu();
      break;
    default:
      text_box_->SetMainMenu();
      break;
  }
}

void Game::HandleAttackEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      player_->Attack1();
      enemy_->TakeDamage(player_->GetAttack1Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      should_render_text_box_ = false;
      break;
    case SDLK_2:
      player_->Attack2();
      enemy_->TakeDamage(player_->GetAttack2Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      should_render_text_box_ = false;
      break;
    case SDLK_3:
      player_->Attack3();
      enemy_->TakeDamage(player_->GetAttack3Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      should_render_text_box_ = false;
      break;
    case SDLK_4:
      player_->Attack4();
      enemy_->TakeDamage(player_->GetAttack4Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      should_render_text_box_ = false;
      break;
    default:
      text_box_->SetMainMenu();
      break;
  }
}

void Game::HandleStatsEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      text_box_->SetStatsMenu(player_.get());
      break;
    default:
      text_box_->SetMainMenu();
      break;
  }
}

void Game::HandleRunEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      SetIsRunning(false);
      break;
    default:
      text_box_->SetMainMenu();
      break;
  }
}

void Game::HandleSaveEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      // TODO: Add SQLite database for saving/loading game state.
      std::clog << "Game saved!" << std::endl;
      text_box_->SetMainMenu();
      break;
    default:
      text_box_->SetMainMenu();
      break;
  }
}