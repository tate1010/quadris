#include <iostream>
#include <vector>
#include <memory>
#include "grid.h"
#include "TextDisplay.cc"

Grid::Grid(){


std::vector<std::vector<char>> theGrid;

td = new TextDisplay();



}



void Grid::display(){

std::cout << *td;



}
