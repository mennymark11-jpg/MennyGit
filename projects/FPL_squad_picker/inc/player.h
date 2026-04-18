#ifndef PLAYER_H
#define PLAYER_H

#include <string> // for std::string

namespace FPL_Squad_Picker
{

enum Position
{
    Goalkeeper  = 1,
    Defender    = 2,
    Midfielder  = 3,
    Forward     = 4
};


struct Player
{
    int             id;
    std::string     name;
    int             team;
    Position        position;
    int             price;
    int             total_points;
    double          points_per_game;
    int             minutes;
}; // struct Player

} // namespace FPL_Squad_Picker

#endif // PLAYER_H