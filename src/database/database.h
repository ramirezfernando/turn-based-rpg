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
  void LoadGame(int slot, Character* player, Character* enemy);
  bool isLoadGameAvailable(int slot);
  std::string getLoadGameTime(int slot);

 private:
  sqlite3* database_;
};