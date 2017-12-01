#include "cell.h"


Cell::Cell(size_t r,size_t c):r(r),c(c){
  block = ' ';
};

void Cell::setPiece(char b){

block  = b;
filled = true;
}


char Cell::getBlock(){

return block;

}

bool Cell::Filled(){
return filled;


}
