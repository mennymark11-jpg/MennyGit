#ifndef DATABASE_H
#define DATABASE_H

#include <vector> // for std::vector

#include <sqlite3.h> // for sqlite3 database handling

#include "player.h" // for Player struct

namespace FPL_Squad_Picker
{

class Database
{
public:
    Database(const char* filename);
    ~Database();

    void init();
    void insert_players(const std::vector<Player>& players);

    void print_all_players();

private:
    sqlite3* m_db_ptr;
}; // class Database

} // namespace FPL_Squad_Picker

#endif // DATABASE_H