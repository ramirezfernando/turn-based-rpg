#include "database.h"
#include <iostream>
#include "utils/util.h"

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

void Database::SaveGame(int slot, Character* player, Character* enemy) {
  if (!database_) {
    std::cerr << "Database is not open." << std::endl;
    return;
  }

  std::string sql =
      "CREATE TABLE IF NOT EXISTS game_state ("
      "slot INTEGER PRIMARY KEY UNIQUE, "
      "slot INTEGER, "
      // SQLite provides default timestamp as current time in UTC. I want to
      // store it as local time, so I will handle that in the C++ code.
      // "timestamp DATETIME DEFAULT (datetime('now', 'localtime')), " still
      // returns UTC time.
      "timestamp DATETIME, "
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
    return;
  } else {
    std::clog << "Table created successfully" << std::endl;
  }

  sql =
      "INSERT OR REPLACE INTO game_state ("
      "slot, "
      "timestamp, "
      "player_type, player_level, player_health, player_energy, "
      "enemy_type, enemy_level, enemy_health, enemy_energy) "
      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";

  sqlite3_stmt* stmt;
  if (sqlite3_prepare_v2(database_, sql.c_str(), -1, &stmt, nullptr) !=
      SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(database_)
              << std::endl;
    return;
  }

  sqlite3_bind_int(stmt, 1, slot);
  sqlite3_bind_text(stmt, 2, Util::GetLocalTime().c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 3, player->GetCharacterTypeString().c_str(), -1,
                    SQLITE_STATIC);
  sqlite3_bind_int(stmt, 4, player->GetLevel());
  sqlite3_bind_int(stmt, 5, player->GetHealth());
  sqlite3_bind_int(stmt, 6, player->GetEnergy());
  sqlite3_bind_text(stmt, 7, enemy->GetCharacterTypeString().c_str(), -1,
                    SQLITE_STATIC);
  sqlite3_bind_int(stmt, 8, enemy->GetLevel());
  sqlite3_bind_int(stmt, 9, enemy->GetHealth());
  sqlite3_bind_int(stmt, 10, enemy->GetEnergy());

  if (sqlite3_step(stmt) != SQLITE_DONE) {
    std::cerr << "Failed to insert data: " << sqlite3_errmsg(database_)
              << std::endl;
  } else {
    std::clog << "Game state saved successfully" << std::endl;
  }

  sqlite3_finalize(stmt);
  sqlite3_exec(database_, "COMMIT TRANSACTION;", nullptr, nullptr, nullptr);
}

bool Database::isLoadGameAvailable(int slot) {
  if (!database_) {
    std::cerr << "Database is not open." << std::endl;
    return false;
  }

  std::string sql = "SELECT COUNT(*) FROM game_state WHERE slot = ?;";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(database_, sql.c_str(), -1, &stmt, nullptr) !=
      SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(database_)
              << std::endl;
    return false;
  }

  sqlite3_bind_int(stmt, 1, slot);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    int count = sqlite3_column_int(stmt, 0);
    return count > 0;
  } else {
    std::cerr << "Failed to execute query: " << sqlite3_errmsg(database_)
              << std::endl;
  }

  sqlite3_finalize(stmt);
  return false;
}

std::string Database::getLoadGameTime(int slot) {
  if (!database_) {
    std::cerr << "Database is not open." << std::endl;
    return "";
  }

  std::string sql = "SELECT timestamp FROM game_state WHERE slot = ?;";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(database_, sql.c_str(), -1, &stmt, nullptr) !=
      SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(database_)
              << std::endl;
    return "";
  }

  sqlite3_bind_int(stmt, 1, slot);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    const char* timestamp =
        reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    std::string time_str(timestamp);
    sqlite3_finalize(stmt);
    return time_str;
  } else {
    std::cerr << "Failed to execute query: " << sqlite3_errmsg(database_)
              << std::endl;
  }

  sqlite3_finalize(stmt);
  return "";
}
