#ifndef interpreter_H
#define interpreter_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "game.h"
class interpreter{
    Game *livegame;
    //to  do
    //GraphicDisplay
public:
    interpreter();
    void seed (int seed );
    void left();
    void right();
    void down();
    void clockwise();
    void counterclockwise();
    void drop();
    void levelup();
    void leveldown();
    void norandom();
    void sequence(std::string file);
    void restart();
    void Hint();
    void call(std::string command, std::string arg);
};
#endif

