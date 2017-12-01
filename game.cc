#include "game.h"
#include <iostream>
Game::Game(){

    g = new Grid();
    level = 0;
    score = 0;
    hiscore = 0;

}


void Game::left(){
if(CurrentPiece->getleftcol() > 0 ){
CurrentPiece -> move_left();
}

}

void Game::right(){
if (CurrentPiece->getrightcol() < 10){
CurrentPiece -> move_right();
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
