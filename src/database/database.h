#include <sqlite3.h>
#include <string>
#include "characters/character.h"

class Database {
 public:
  Database();
  ~Database();
  bool Open(const std::string& db_path);
  void Close();
  void SaveGame(int slot, Character* player, Character* enemy);
  // TODO: Create `LoadGame()` member function to load game state from the
  // database. Add this once there is a UI to load a saved game before starting
  // a new game.
 private:
  sqlite3* database_;
};