#include <iostream>
#include <vector>
#include <memory>
#include "grid.h"
#include "TextDisplay.h"
#include "cell.h"

Grid::Grid(){


    theGrid = std::vector<std::vector<Cell>>(18);

    for (size_t i = 0; i < 18; ++i){
        for (size_t j = 0; j < 11 ; ++j){
            theGrid[i].emplace_back(Cell(i,j));

            //attach

        }
    }

    td = new TextDisplay();
    hitbox = std::vector<int> (11,17);


}



char Grid::getBlock(int r, int c){

    return theGrid[r][c].getBlock();


}

void Grid::clear(int line){

    for (int i = line; i > 0; --i){

        for (int col = 0; col < 11; ++col){
            theGrid[i][col].setPiece(theGrid[i-1][col].getBlock());


        }
    }

    for (int cell = 0; cell < 11; ++cell){
        theGrid[0][cell].setPiece(' ');

    }
    for(auto &cell : hitbox){
      --cell;


    }
}
void Grid::Check(){

  for (int row = 0; row < 18; ++row){
    bool full = true;
    for (auto &col : theGrid[row]){
      if (!col.Filled()){

        full = false;
      }


    }
    if (full) clear(row);
    full = true;

  }

}

void Grid::setPiece(int r, int c, char piece){


    theGrid[r][c].setPiece(piece);
    if (piece ==' '){

        theGrid[r][c].unfill();

    }
}
void Grid::display(){

    std::cout << *td;



}
std::vector<int>& Grid::Hitbox(){

    return hitbox;
}






std::ostream& operator<<(std::ostream &out,  Grid &grd){

    for (int row = 3; row < 18; ++row){
        for (int col = 0; col < 11; ++ col){

            out << grd.getBlock(row,col);

        }
        out << std::endl;
    }
return out;
}
