#include "cell.h"


Cell::Cell(size_t r,size_t c  ):r(r),c(c){
    block = 'e';
};

void Cell::setPiece(char b, int l){

    block  = b;
    level = l;
    filled = true;
}
int Cell::getLevel(){
return level;

}

void Cell::setPiece(char b){
  block = b;
  filled = true;

}
char Cell::getBlock(){return block;}

void Cell::unfill(){filled = false;}

bool Cell::Filled(){return filled;}
