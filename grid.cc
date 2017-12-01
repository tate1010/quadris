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
        theGrid[0][cell].setPiece(' ');

    }
}

void Grid::setPiece(int r, int c, char piece){

    theGrid[r][c].setPiece(piece);
}
void Grid::display(){

    std::cout << *td;



}
std::vector<int> Grid::Hitbox(){
    std::vector<int> hitbox(11,0);

    for (int C= 0; C < 11 ; ++C){
        for (int R = 17; R >= 0 ; --R){


            if (theGrid[R][C].Filled()){
                hitbox[C] = R;
            }

        }
    }

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
