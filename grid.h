#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "TextDisplay.h"

class Grid{
    std::vector<std::vector<Cell>> theGrid;
    TextDisplay *td = nullptr;
    bool textonlydisplay = true;
    std::vector<int> hitbox;

    //to  do
    //GraphicDisplay
public:
    Grid();

    void display();
    int  Check();
    void  setPiece(int r, int c, char piece, int level);
    void setPiece(int r, int c , char piece );
    char getBlock(int r, int c);
    void unfill(int r, int c);
    int clear(int line ); //CLEAR THE LINE Count FRom the top
    //line start from 0 to 15 (+3)
    //
    std::vector<std::vector<char>> layout();
    std::vector<int>& Hitbox();


    friend std::ostream &operator<<(std::ostream &out,  Grid &grd);
};
#endif

