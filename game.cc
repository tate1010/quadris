#include "game.h"
#include "Opiece.h"
#include "Ipiece.h"
#include "Tpiece.h"
#include "Lpiece.h"
#include "Zpiece.h"
#include "Spiece.h"
#include "Jpiece.h"
#include <iostream>
Game::Game(){

    g = new Grid();
    level = 0;
    score = 0;
    hiscore = 0;

}


void Game::left(){
  for (auto &row: CurrentPiece->getlayout()){
  for (auto &col : row){

  g->setPiece(col.getRow(),col.getCol(),' ');
  }
  }

  CurrentPiece -> move_left();

  for (auto &row: CurrentPiece->getlayout()){
  for (auto &col : row){

  g->setPiece(col.getRow(),col.getCol(),col.getType());
  }
  }

}

void Game::right(){

  for (auto &row: CurrentPiece->getlayout()){
  for (auto &col : row){

  g->setPiece(col.getRow(),col.getCol(),' ');
  }
  }

  CurrentPiece -> move_right();

  for (auto &row: CurrentPiece->getlayout()){
  for (auto &col : row){

  g->setPiece(col.getRow(),col.getCol(),col.getType());
  }
  }
}
void Game::down(){
  for (auto &row: CurrentPiece->getlayout()){
  for (auto &col : row){

  g->setPiece(col.getRow(),col.getCol(),' ');
  }
  }

  CurrentPiece -> softdrop();

  for (auto &row: CurrentPiece->getlayout()){
  for (auto &col : row){

  g->setPiece(col.getRow(),col.getCol(),col.getType());
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
CurrentPiece = new Spiece();

for (auto &row: CurrentPiece->getlayout()){
for (auto &col : row){

g->setPiece(col.getRow(),col.getCol(),col.getType());
}
}


}
void Game::T(){
CurrentPiece = new Tpiece();

for (auto &row: CurrentPiece->getlayout()){
for (auto &col : row){

g->setPiece(col.getRow(),col.getCol(),col.getType());
}
}


}
void Game::I(){
CurrentPiece = new Ipiece();

for (auto &row: CurrentPiece->getlayout()){
for (auto &col : row){

g->setPiece(col.getRow(),col.getCol(),col.getType());
}
}


}
void Game::L(){
CurrentPiece = new Lpiece();

for (auto &row: CurrentPiece->getlayout()){
for (auto &col : row){

g->setPiece(col.getRow(),col.getCol(),col.getType());
}
}


}
void Game::J(){
CurrentPiece = new Jpiece();

for (auto &row: CurrentPiece->getlayout()){
for (auto &col : row){

g->setPiece(col.getRow(),col.getCol(),col.getType());
}
}


}
void Game::O(){
CurrentPiece = new Opiece();

for (auto &row: CurrentPiece->getlayout()){
for (auto &col : row){

g->setPiece(col.getRow(),col.getCol(),col.getType());
}
}


}
void Game::Z(){
CurrentPiece = new Zpiece();

for (auto &row: CurrentPiece->getlayout()){
for (auto &col : row){

g->setPiece(col.getRow(),col.getCol(),col.getType());
}
}


}
