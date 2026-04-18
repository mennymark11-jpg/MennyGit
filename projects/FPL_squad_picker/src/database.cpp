#include <iostream> // for std::cerr
#include <iomanip>  // for std::setw, std::left, std::right

#include "database.h" // for Database class

namespace FPL_Squad_Picker
{   

Database::Database(const char* filename)
{
    sqlite3_open(filename, &m_db_ptr);
}

Database::~Database()
{
    sqlite3_close(m_db_ptr);
}

void Database::init()
{
    const char* sql =
        "CREATE TABLE IF NOT EXISTS players ("
        "id INTEGER PRIMARY KEY,"
        "name TEXT,"
        "team INTEGER,"
        "position INTEGER,"
        "price INTEGER,"
        "total_points INTEGER,"
        "points_per_game REAL,"
        "minutes INTEGER"
        ");";

    sqlite3_exec(m_db_ptr, sql, nullptr, nullptr, nullptr);
}

void Database::insert_players(const std::vector<Player>& players)
{
    const char* sql =
        "INSERT OR REPLACE INTO players "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(m_db_ptr, sql, -1, &stmt, nullptr);

    for (const auto& p : players)
    {
        sqlite3_bind_int    (stmt, 1, p.id);
        sqlite3_bind_text   (stmt, 2, p.name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int    (stmt, 3, p.team);
        sqlite3_bind_int    (stmt, 4, p.position);
        sqlite3_bind_int    (stmt, 5, p.price);
        sqlite3_bind_int    (stmt, 6, p.total_points);
        sqlite3_bind_double (stmt, 7, p.points_per_game);
        sqlite3_bind_int    (stmt, 8, p.minutes);

        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }

    sqlite3_finalize(stmt);
}

void Database::print_all_players()
{
    static std::string s_positions[] = {"", "GK", "DEF", "MID", "FWD"};
    static std::string s_teams[] =
    {   
    "Arsenal",
    "Aston Villa",
    "Bournemouth",
    "Brentford",
    "Brighton & Hove Albion",
    "Burnley",
    "Chelsea",
    "Crystal Palace",
    "Everton",
    "Fulham",
    "Leeds United",
    "Liverpool",
    "Manchester City",
    "Manchester United",
    "Newcastle United",
    "Nottingham Forest",
    "Sunderland",
    "Tottenham Hotspur",
    "West Ham United",
    "Wolverhampton Wanderers",
    "NO TEAM"
    };

    const char* sql = "SELECT * FROM players;";

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(m_db_ptr, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement\n";
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id                      = sqlite3_column_int(stmt, 0);
        const unsigned char* name   = sqlite3_column_text(stmt, 1);
        int team                    = sqlite3_column_int(stmt, 2);
        Position position           = static_cast<Position>(sqlite3_column_int(stmt, 3));
        int price                   = sqlite3_column_int(stmt, 4);
        int total_points            = sqlite3_column_int(stmt, 5);
        double ppg                  = sqlite3_column_double(stmt, 6);
        int minutes                 = sqlite3_column_int(stmt, 7);

        std::cout
            << std::setw(4) << std::right << id
            << " | " << std::setw(35) << std::left << reinterpret_cast<const char*>(name)
            << " | " << std::setw(25) << std::left << s_teams[team]
            << " | " << std::setw(4) << std::left << s_positions[position]
            << " | " << std::setw(6) << std::right << price
            << " | " << std::setw(7) << std::right << total_points
            << " | " << std::setw(5) << std::right << ppg
            << " | " << std::setw(8) << std::right << minutes
            << std::endl;
    }

    sqlite3_finalize(stmt);
}

} // namespace FPL_Squad_Picker