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


char Grid::getBlock(int r, int c){

  return theGrid[r][c].getBlock();


}

void Grid::clear(int line){

for (int i = line+2; i > 0; --i){

for (int col = 0; col < 11; ++col){
theGrid[i][col].setPiece(theGrid[i-1][col].getBlock());


}
}

for (int cell = 0; cell < 11; ++cell){
theGrid[0][cell].setPiece('P');

}
}

void Grid::setPiece(int r, int c, char piece){

theGrid[r][c].setPiece(piece);
}
void Grid::display(){

std::cout << *td;



}


std::ostream& operator<<(std::ostream &out,  Grid &grd){
int dividerlength = 11;
out << "level" << std::endl;
out << "score" << std::endl;
out << "Hi Score:" << std::endl;
//divider here
for(int divider= 1 ; divider <= dividerlength; ++divider){
out << "-";
}
out << std::endl;
//grid here
for (int row = 3; row < 18; ++row){
for (int col = 0; col < 11; ++ col){

out << grd.getBlock(row,col);

}
out << endl;
}

//
for(int divider= 1 ; divider <= dividerlength; ++divider){
out << "-";
}
out << std::endl;
//
out << "Next:" << std::endl;


return out;
}
