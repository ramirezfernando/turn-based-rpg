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

void Game::SaveGameState(Character* player, Character* enemy) {
  int db = sqlite3_open("data/game_state.db", &database_);
  if (db) {
    std::cerr << "Can't open database: " << sqlite3_errmsg(database_)
              << std::endl;
  } else {
    std::clog << "Opened database successfully" << std::endl;
  }
  std::string sql =
      "CREATE TABLE IF NOT EXISTS game_state ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
      "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
      "is_player_turn BOOLEAN, "

      "player_type TEXT, "
      "player_level INTEGER, "
      "player_health INTEGER, "
      "player_energy INTEGER, "

      "enemy_type TEXT, "
      "enemy_level INTEGER, "
      "enemy_health INTEGER, "
      "enemy_energy INTEGER);";
  char* error_message = nullptr;
  if (sqlite3_exec(database_, sql.c_str(), nullptr, nullptr, &error_message) !=
      SQLITE_OK) {
    std::cerr << "SQL error: " << error_message << std::endl;
    sqlite3_free(error_message);
  } else {
    std::clog << "Table created successfully" << std::endl;
  }
  sql =
      "INSERT INTO game_state (is_player_turn, "
      "player_type, player_level, player_health, player_energy, "
      "enemy_type, enemy_level, enemy_health, enemy_energy) "
      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);";
  sqlite3_stmt* stmt;
  if (sqlite3_prepare_v2(database_, sql.c_str(), -1, &stmt, nullptr) !=
      SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(database_)
              << std::endl;
    return;
  }
  sqlite3_bind_int(stmt, 1, is_player_turn_);
  sqlite3_bind_text(stmt, 2, player->GetCharacterTypeString().c_str(), -1,
                    SQLITE_STATIC);
  sqlite3_bind_int(stmt, 3, player->GetLevel());
  sqlite3_bind_int(stmt, 4, player->GetHealth());
  sqlite3_bind_int(stmt, 5, player->GetEnergy());
  sqlite3_bind_text(stmt, 6, enemy->GetCharacterTypeString().c_str(), -1,
                    SQLITE_STATIC);
  sqlite3_bind_int(stmt, 7, enemy->GetLevel());
  sqlite3_bind_int(stmt, 8, enemy->GetHealth());
  sqlite3_bind_int(stmt, 9, enemy->GetEnergy());
  if (sqlite3_step(stmt) != SQLITE_DONE) {
    std::cerr << "Failed to insert data: " << sqlite3_errmsg(database_)
              << std::endl;
  } else {
    std::clog << "Game state saved successfully" << std::endl;
  }
  sqlite3_finalize(stmt);
  // Close the database connection.
  if (sqlite3_close(database_) != SQLITE_OK) {
    std::cerr << "Failed to close database: " << sqlite3_errmsg(database_)
              << std::endl;
  } else {
    std::clog << "Database closed successfully" << std::endl;
  }
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
      SaveGameState(player_.get(), enemy_.get());
      text_box_->SetMainMenu();
      break;
    default:
      text_box_->SetMainMenu();
      break;
  }
}