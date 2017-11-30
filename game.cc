#include "game.h"
#include <iostream>
Game::Game(){
    
    Grid *g = new Grid();
    g->setPiece(10,10,'r');
    std::cout << *g;
    g->clear(10);
    std::cout << *g;
}
