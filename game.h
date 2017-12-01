#ifndef Game_H
#define Game_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "grid.h"
#include "piece.h"

class Game{
    Grid *g;
    piece *CurrentPiece;
    int level;
    int score;
    int hiscore;
public:
    Game();
    void left();
    void right();
    friend  std::ostream& operator<<(std::ostream &out,  Game &game);

};
#endif
