#include <iostream> // for std::cout

#include "fpl_client.h" // for FPLClient class
#include "database.h"   // for Database class    

int main()
{
    FPL_Squad_Picker::FPLClient client;

    std::vector<FPL_Squad_Picker::Player> players = client.fetch_players();

    FPL_Squad_Picker::Database db("../data/fpl.db");

    db.init();
    db.insert_players(players);
    db.print_all_players();

    std::cout << "Inserted " << players.size() << " players\n";

    return 0;
}