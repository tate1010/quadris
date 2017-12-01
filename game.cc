#include "game.h"
#include "squarepiece.h"
#include <iostream>
Game::Game(){

    g = new Grid();
    level = 0;
    score = 0;
    hiscore = 0;

}


void Game::left(){
for (auto &row : CurrentPiece ->getlayout()){
for (auto &col : row){

std::cout<< col.getCol();
}
}
}

void Game::right(){

  for (auto &row: CurrentPiece->getlayout()){
  for (auto &col : row){

  g->setPiece(col.getCol(),col.getRow(),' ');
  }
  }

  CurrentPiece -> move_right();

  for (auto &row: CurrentPiece->getlayout()){
  for (auto &col : row){
std::cout << col.getCol();
  g->setPiece(col.getCol(),col.getRow(),col.getType());
  }
  }


}

std::ostream& operator<<(std::ostream &out,  Game &game){

  int dividerlength = 11;
  out << "level: " <<  game.level<< std::endl;
  out << "score: " << game.score << std::endl;
  out << "Hi Score: " << game.hiscore << std::endl;
  //divider here
  for(int divider= 1 ; divider <= dividerlength; ++divider){
      out << "-";
  }
  out << std::endl;
  //grid here
  out << *(game.g);

//
for(int divider= 1 ; divider <= dividerlength; ++divider){
    out << "-";
}
out << std::endl;
//
out << "Next:" << std::endl;


return out;

}


void Game::S(){
CurrentPiece = new squarepiece();
for (auto &row: CurrentPiece->getlayout()){
for (auto &col : row){

g->setPiece(col.getCol(),col.getRow(),col.getType());
}
}


}
