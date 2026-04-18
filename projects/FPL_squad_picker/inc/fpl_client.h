#ifndef FPL_CLIENT_H
#define FPL_CLIENT_H

#include <vector> // for std::vector

#include "player.h" // for Player struct

namespace FPL_Squad_Picker
{

class FPLClient
{
public:
    std::vector<Player> fetch_players();
}; // class FPLClient

} // namespace FPL_Squad_Picker

#endif // FPL_CLIENT_H