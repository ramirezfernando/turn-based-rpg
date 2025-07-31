#include <sqlite3.h>
#include <string>

class Database {
 public:
  Database();
  ~Database();
  bool Open(const std::string& db_path);
  void Close();

 private:
  sqlite3* database_;
}