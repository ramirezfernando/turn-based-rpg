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
    text_box_->SetShouldRender(true);
  }

  // Initial game state is character selection for the player.
  state_ = State::CHARACTER_SELECTION;
  text_box_->SetPlayerSelection();
}

void Game::Update() {
  switch (state_) {
    case State::CHARACTER_SELECTION:
      HandleCharacterSelectionUpdate();
      break;
    case State::BATTLE:
      HandleBattleUpdate();
      break;
    case State::GAME_OVER:
      // TODO: Handle game over logic here.
      break;
  }
}

void Game::Render() {
  SDL_RenderClear(renderer_);
  background_->Render();
  // `TextBox::Render()` will return early if it shouldn't render.
  text_box_->Render();
  switch (state_) {
    case State::CHARACTER_SELECTION:
      HandleCharacterSelectionRender();
      break;
    case State::BATTLE:
      HandleBattleRender();
      break;
    case State::GAME_OVER:
      // TODO: Handle game over logic here.
      break;
  }
  SDL_RenderPresent(renderer_);
}

void Game::HandleEvents() {
  SDL_PollEvent(&event_);
  switch (state_) {
    case State::CHARACTER_SELECTION:
      HandleCharacterSelectionEvents();
      break;
    case State::BATTLE:
      HandleBattleEvents();
      break;
    case State::GAME_OVER:
      // TODO: Handle game over logic here.
      break;
  }
}

void Game::HandleCharacterSelectionUpdate() {
  // `player_` and `enemy_` can be null if not yet selected.
  if (player_) {
    player_->Update();
  }
  if (enemy_) {
    enemy_->Update();
  }
}

void Game::HandleCharacterSelectionRender() {
  // `player_` and `enemy_` can be null if not yet selected.
  if (player_) {
    player_->Render();
  }
  if (enemy_) {
    enemy_->Render();
  }
}

void Game::HandleCharacterSelectionEvents() {
  switch (event_.type) {
    case SDL_QUIT:
      is_running_ = false;
      break;
    case SDL_KEYDOWN:
      TextBox::State current_text_box_state = text_box_->GetState();
      switch (current_text_box_state) {
        case TextBox::State::PLAYER_SELECTION:
          HandlePlayerSelectionEvents();
          break;
        case TextBox::State::ENEMY_SELECTION:
          HandleEnemySelectionEvents();
          break;
        // Adding a default case to avoid compiler warnings for unhandled
        // `TextBox::State` enums.
        default:
          break;
      }
      break;
  }
}

void Game::HandlePlayerSelectionEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      player_ =
          std::unique_ptr<Character>(new WaterPriestess(/*is_enemy=*/false));
      break;
    case SDLK_2:
      player_ = std::unique_ptr<Character>(new GroundMonk(/*is_enemy=*/false));
      break;
    case SDLK_3:
      player_ = std::unique_ptr<Character>(new FireKnight(/*is_enemy=*/false));
      break;
  }
  if (player_) {
    // Since player has been selected, move to enemy selection.
    text_box_->SetEnemySelection();
  }
}

void Game::HandleEnemySelectionEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      enemy_ =
          std::unique_ptr<Character>(new WaterPriestess(/*is_enemy=*/true));
      break;
    case SDLK_2:
      enemy_ = std::unique_ptr<Character>(new GroundMonk(/*is_enemy=*/true));
      break;
    case SDLK_3:
      enemy_ = std::unique_ptr<Character>(new FireKnight(/*is_enemy=*/true));
      break;
    // Go back to player selection if invalid key is pressed.
    default:
      text_box_->SetPlayerSelection();
      player_.reset();
      break;
  }
  if (enemy_) {
    // Since enemy has been selected, move to battle state.
    text_box_->SetBattleOptions();
    is_player_turn_ = true;
    is_in_battle_ = false;
    state_ = State::BATTLE;
  }
}

void Game::HandleBattleUpdate() {
  player_->Update();
  enemy_->Update();

  if (is_in_battle_) {
    // Check if player just finished attacking.
    if (!is_player_turn_ && !player_->IsAttacking() && !enemy_->IsAttacking() &&
        player_->IsAnimationComplete()) {
      constants::AttackType ai_decision = enemy_->GetAiDecision(player_.get());
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
        text_box_->SetShouldRender(true);
        text_box_->SetBattleOptions();
        is_in_battle_ = false;
      }
    }
  }
}

void Game::HandleBattleRender() {
  player_->Render();
  enemy_->Render();
}

void Game::HandleBattleEvents() {
  switch (event_.type) {
    case SDL_QUIT:
      is_running_ = false;
      break;
    case SDL_KEYDOWN:
      if (is_player_turn_) {
        TextBox::State current_text_box_state = text_box_->GetState();
        switch (current_text_box_state) {
          case TextBox::State::BATTLE_OPTIONS:
            HandleBattleOptionEvents();
            break;
          case TextBox::State::BATTLE_ATTACK:
            HandleBattleAttackEvents();
            break;
          case TextBox::State::BATTLE_STATS:
            HandleBattleStatsEvents();
            break;
          case TextBox::State::BATTLE_SAVE:
            HandleBattleSaveEvents();
            break;
          case TextBox::State::BATTLE_RUN:
            HandleBattleRunEvents();
            break;
          // Adding a default case to avoid compiler warnings for unhandled
          // `TextBox::State` enums.
          default:
            break;
        }
      }
      break;
  }
}

void Game::HandleBattleOptionEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      text_box_->SetBattleAttack();
      break;
    case SDLK_2:
      text_box_->SetBattleStats(player_.get());
      break;
    case SDLK_3:
      if (!database_) {
        database_ = std::unique_ptr<Database>(new Database());
        if (!database_->Open(constants::DATABASE_FILE_PATH)) {
          std::cerr << "Failed to open database." << std::endl;
          return;
        }
      }
      if (database_->IsPreviousSaveAvailable(1)) {
        text_box_->SetSaveSlotText(1, database_->GetPreviousSaveTime(1));
      }
      text_box_->SetBattleSave();
      break;
    case SDLK_4:
      text_box_->SetBattleRun();
      break;
    default:
      text_box_->SetBattleOptions();
      break;
  }
}

void Game::HandleBattleAttackEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      player_->Attack1();
      enemy_->TakeDamage(player_->GetAttack1Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      text_box_->SetShouldRender(false);
      break;
    case SDLK_2:
      player_->Attack2();
      enemy_->TakeDamage(player_->GetAttack2Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      text_box_->SetShouldRender(false);
      break;
    case SDLK_3:
      player_->Attack3();
      enemy_->TakeDamage(player_->GetAttack3Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      text_box_->SetShouldRender(false);
      break;
    case SDLK_4:
      player_->Attack4();
      enemy_->TakeDamage(player_->GetAttack4Damage());
      is_player_turn_ = false;
      is_in_battle_ = true;
      text_box_->SetShouldRender(false);
      break;
    default:
      text_box_->SetBattleOptions();
      break;
  }
}

void Game::HandleBattleStatsEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      text_box_->SetBattleStats(player_.get());
      break;
    default:
      text_box_->SetBattleOptions();
      break;
  }
}

void Game::HandleBattleRunEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1:
      SetIsRunning(false);
      break;
    default:
      text_box_->SetBattleOptions();
      break;
  }
}

void Game::HandleBattleSaveEvents() {
  switch (event_.key.keysym.sym) {
    case SDLK_1: {
      if (!database_) {
        database_ = std::unique_ptr<Database>(new Database());
        if (!database_->Open(constants::DATABASE_FILE_PATH)) {
          std::cerr << "Failed to open database." << std::endl;
          return;
        }
      }
      database_->SaveGame(1, player_.get(), enemy_.get());
      text_box_->SetSaveSlotText(1, Util::GetLocalTime());
      text_box_->SetBattleOptions();
      break;
    }
    default:
      text_box_->SetBattleOptions();
      break;
  }
}