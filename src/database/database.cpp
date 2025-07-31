#include "database.h"

Database::Database() : database_(nullptr) {
  std::clog << "Database initialized" << std::endl;
}

Database::~Database() {
  if (database_) {
    Close();
  }
  std::clog << "Database destroyed" << std::endl;
}

bool Database::Open(const std::string& db_path) {
  if (sqlite3_open(db_path.c_str(), &database_) != SQLITE_OK) {
    std::cerr << "Failed to open database: " << sqlite3_errmsg(database_)
              << std::endl;
    return false;
  }
  std::clog << "Database opened successfully" << std::endl;
  return true;
}

void Database::Close() {
  if (database_) {
    if (sqlite3_close(database_) != SQLITE_OK) {
      std::cerr << "Failed to close database: " << sqlite3_errmsg(database_)
                << std::endl;
    } else {
      std::clog << "Database closed successfully" << std::endl;
    }
    database_ = nullptr;
  }
}

// TODO: Implement methods for saving and loading game state
// void Game::SaveGameState(Character* player, Character* enemy) {
//   int db = sqlite3_open("data/game_state.db", &database_);
//   if (db) {
//     std::cerr << "Can't open database: " << sqlite3_errmsg(database_)
//               << std::endl;
//   } else {
//     std::clog << "Opened database successfully" << std::endl;
//   }
//   std::string sql =
//       "CREATE TABLE IF NOT EXISTS game_state ("
//       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
//       "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
//       "is_player_turn BOOLEAN, "

//       "player_type TEXT, "
//       "player_level INTEGER, "
//       "player_health INTEGER, "
//       "player_energy INTEGER, "

//       "enemy_type TEXT, "
//       "enemy_level INTEGER, "
//       "enemy_health INTEGER, "
//       "enemy_energy INTEGER);";
//   char* error_message = nullptr;
//   if (sqlite3_exec(database_, sql.c_str(), nullptr, nullptr, &error_message) !=
//       SQLITE_OK) {
//     std::cerr << "SQL error: " << error_message << std::endl;
//     sqlite3_free(error_message);
//   } else {
//     std::clog << "Table created successfully" << std::endl;
//   }
//   sql =
//       "INSERT INTO game_state (is_player_turn, "
//       "player_type, player_level, player_health, player_energy, "
//       "enemy_type, enemy_level, enemy_health, enemy_energy) "
//       "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);";
//   sqlite3_stmt* stmt;
//   if (sqlite3_prepare_v2(database_, sql.c_str(), -1, &stmt, nullptr) !=
//       SQLITE_OK) {
//     std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(database_)
//               << std::endl;
//     return;
//   }
//   sqlite3_bind_int(stmt, 1, is_player_turn_);
//   sqlite3_bind_text(stmt, 2, player->GetCharacterTypeString().c_str(), -1,
//                     SQLITE_STATIC);
//   sqlite3_bind_int(stmt, 3, player->GetLevel());
//   sqlite3_bind_int(stmt, 4, player->GetHealth());
//   sqlite3_bind_int(stmt, 5, player->GetEnergy());
//   sqlite3_bind_text(stmt, 6, enemy->GetCharacterTypeString().c_str(), -1,
//                     SQLITE_STATIC);
//   sqlite3_bind_int(stmt, 7, enemy->GetLevel());
//   sqlite3_bind_int(stmt, 8, enemy->GetHealth());
//   sqlite3_bind_int(stmt, 9, enemy->GetEnergy());
//   if (sqlite3_step(stmt) != SQLITE_DONE) {
//     std::cerr << "Failed to insert data: " << sqlite3_errmsg(database_)
//               << std::endl;
//   } else {
//     std::clog << "Game state saved successfully" << std::endl;
//   }
//   sqlite3_finalize(stmt);
//   // Close the database connection.
//   if (sqlite3_close(database_) != SQLITE_OK) {
//     std::cerr << "Failed to close database: " << sqlite3_errmsg(database_)
//               << std::endl;
//   } else {
//     std::clog << "Database closed successfully" << std::endl;
//   }
// }