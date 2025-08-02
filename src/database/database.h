#include <sqlite3.h>
#include <string>
#include "characters/character.h"

class Database {
 public:
  Database();
  ~Database();
  bool Open(const std::string& db_path);
  void Close();
  void SaveGame(Character* player, Character* enemy);

 private:
  sqlite3* database_;
};