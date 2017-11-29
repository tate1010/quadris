#include <iostream>
#include <vector>
#include <memory>
#include "grid.h"
#include "TextDisplay.cc"
#include "cell.cc"

Grid::Grid(){


  theGrid = std::vector<std::vector<Cell>>(18);

  for (size_t i = 0; i < 18; ++i){
      for (size_t j = 0; j < 11 ; ++j){
             theGrid[i].emplace_back(Cell(i,j));
             
     //attach

      }
  }

td = new TextDisplay();



}



void Grid::display(){

std::cout << *td;



}
