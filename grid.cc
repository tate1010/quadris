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
void Grid::unfill(int r, int c){

theGrid[r][c].setPiece('e');
theGrid[r][c].unfill();




}


void Grid::clear(int line){

    for (int i = line; i > 0; --i){

        for (int col = 0; col < 11; ++col){
            theGrid[i][col].setPiece(theGrid[i-1][col].getBlock());

            if (!theGrid[i-1][col].Filled()){
                theGrid[i][col].unfill();

            }
        }
    }


    for(auto &cell : hitbox){
        ++cell;


    }
}

// -------PLEASE CHECK AGAIN WHAT YOU DID HERE PLEASE TATE-----------
// -----------IM SORRY BUT WE NEED TO REMOVE CONFLICTS---------------

bool Grid::Check(){
    bool something_cleared = false; // use in level 4
    for (int row = 0; row < 18; ++row){
        bool full = false;
        for (int col = 0; col < 11; ++ col){
            if (!theGrid[row][col].Filled()){full = true;}
        }

        if (!full) {
            clear(row);
            something_cleared = true;
        }

    }
    return something_cleared; // moved outside of the loop, please revise
}


void Grid::setPiece(int r, int c, char piece){


    theGrid[r][c].setPiece(piece);

    if(piece == 'e'){
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
        for (int col = 0; col < 11; ++ col)
        {
            if (grd.getBlock(row,col) == 'e')
                out << ' ';
            else
                out << grd.getBlock(row,col);

        }
        out << std::endl;
    }
    return out;
}
