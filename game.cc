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
    GD = new GraphicsDisplay(20,500);
    level = 1; //set at 1 for testing. please reset when needed
    score = 0;
    hiscore = 0;
    CurrentPiece = nullptr;
    GeneratePiece();
    NextPiece();

}


void Game::graphic(){

GD->update(g);

}



void Game::NextPiece(){

    if (nextPiece == 'I'){I();}
    else if (nextPiece == 'T'){T();}
    else if (nextPiece == 'O'){O();}
    else if (nextPiece == 'Z'){Z();}
    else if (nextPiece == 'S'){S();}
    else if (nextPiece == 'J'){J();}
    else if (nextPiece == 'L'){L();}

    GeneratePiece();
}

char Game::GetNext(){
    return nextPiece;
}

void Game::changeLevel(int i)
{
    std::cout << "hi im changeLevel, current level is " << i << std::endl;
    level = i;
}

void Game::GeneratePiece(){
    //level1

    if (level == 1){

        int RNG = rand()%12+1;
        if (RNG == 1) {nextPiece = 'S';}
        else if (RNG == 2){nextPiece = 'Z';}
        else if (RNG == 3 || RNG == 4){nextPiece = 'T';}
        else if (RNG == 5 || RNG == 6){nextPiece = 'I';}
        else if (RNG == 7 || RNG == 8){nextPiece = 'O';}
        else if (RNG == 9 || RNG == 10){nextPiece = 'L';}
        else if (RNG == 11 || RNG == 12){nextPiece = 'J';}
        //
    }
    if (level ==2){

        int RNG = rand()%7+1;
        if (RNG == 1){nextPiece = 'S';}
        else if (RNG == 2){nextPiece = 'Z';}
        else if (RNG == 3){ nextPiece = 'T';}
        else if (RNG == 4){nextPiece = 'I';}
        else if (RNG == 5){nextPiece = 'O';}
        else if (RNG == 6){nextPiece = 'L';}
        else if (RNG == 7){nextPiece = 'J';}
    }
    //
    if (level >=3){

        int RNG = rand()%9+1;
        if (RNG == 1 || RNG == 8){nextPiece = 'S';}
        else if (RNG == 2 || RNG == 9){nextPiece = 'Z';}
        else if (RNG == 3){nextPiece = 'T';}
        else if (RNG == 4){nextPiece = 'I';}
        else if (RNG == 5){nextPiece = 'O';}
        else if (RNG == 6){nextPiece = 'L';}
        else if (RNG == 7){nextPiece = 'J';}
    }

    if (level == 4)  // can fix when drop fixes
    {



        if (timer == 5)
        {
            block b;
            for (int i = 17; i >= 3; i--)
            {
                if (g->getBlock(i, 5) == 'e')
                {
                    g->setPiece(i, 5, '*');
                    timer = 1;
                    break;
                }
            }
        }
        ++timer;
        if (g->Check() != 0){
          timer = 1 ;

        }

    }
}

void Game::levelup(){
    if (level < 4){
        ++ level;
    }
}

void Game::leveldown(){

    if (level> 0){

        --level;
    }


}

bool Game::taken(){

vector <vector <block>> layout = CurrentPiece->getlayout();

for (auto &row : layout){

for (auto &col : row){

if( g->getBlock(col.getCol(),col.getRow()) != 'e'){
return true;

}
}
}
return false;
}

void Game::left(){

    vector <vector <block>> layout = CurrentPiece->getlayout();
    int topLefRow = layout[0][0].getRow();
    int topLefCol = layout[0][0].getCol();

    for (int i = 0; i < layout.size();i++)
    {
        for (int j = 0; j < layout[0].size();j++)
        {
            if (layout[i][j].getType() != 'e')
            {
                if ((g->getBlock(i+topLefRow, j+topLefCol-1) != 'e'))
                    return;
                else
                    break;
            }
        }
    }


    if (layout[0][0].getCol() > 0)
    {

        for (auto &row: CurrentPiece->getlayout())
        {
            for (auto &col : row)
            {
                if (col.getType() != 'e')
                    g->setPiece(col.getRow(),col.getCol(),'e');

            }
        }

        CurrentPiece -> move_left();

        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){

                if (col.getType() != 'e')
                    g->setPiece(col.getRow(),col.getCol(),col.getType());
            }
        }
    }
    if (level >= 3){

    down();


    }
}

void Game::right()
{
    vector <vector <block>> layout = CurrentPiece->getlayout();
    int colsize = (int)layout[0].size();

    int topLefRow = layout[0][0].getRow();
    int topLefCol = layout[0][0].getCol();

    for (int i = (int)layout.size()-1; i >= 0; i--)
    {
        for (int j = colsize-1; j >= 0; j--)
        {
            if (layout[i][j].getType() != 'e')
            {
                if (g->getBlock(i+topLefRow, j+topLefCol+1) != 'e')
                    return;
                else
                    break;
            }
        }
    }

    if (layout[0][colsize-1].getCol() < 10)
    {
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                if (col.getType() != 'e')
                    g->setPiece(col.getRow(),col.getCol(),'e');
            }
        }

        CurrentPiece->move_right();

        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){

                if (col.getType() != 'e')
                    g->setPiece(col.getRow(),col.getCol(),col.getType());
            }
        }
    }

    if (level >= 3){

    down();


    }
}
bool Game::down(){

    vector <vector <block>> layout = CurrentPiece->getlayout();
    int topLefRow = layout[0][0].getRow();
    int topLefCol = layout[0][0].getCol();

    for (int j = 0; j < layout[0].size(); j++)
    {
        for (int i = (int)layout.size()-1; i >= 0; i--)
        {
            if (layout[i][j].getType() != 'e')
            {
                if ((layout[i][j].getRow() == 17) /*|| (g->getBlock(i+topLefRow+1, j+topLefCol) != 'e')*/)
                    return false;
                if (g->getBlock(i+topLefRow+1, j+topLefCol) == 'e')
                    break;
                else
                    return false;
            }
        }
    }

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){
            if (col.getType() != 'e')
                g->setPiece(col.getRow(),col.getCol(),'e');
        }
    }

    CurrentPiece -> softdrop();

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){
            if (col.getType() != 'e'){
                g->setPiece(col.getRow(),col.getCol(),col.getType());
            }
        }
    }
    return true;

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
    if (game.GetNext() == 'I'){
        out << "IIII" << std::endl;
    }
    else if (game.GetNext() == 'T'){

        out << "TTT" << std::endl;
        out << " T " << std::endl;
    }
    else if (game.GetNext() == 'O'){

        out << "OO" << std::endl;
        out << "OO" << std::endl;
    }
    else if (game.GetNext() == 'Z'){

        out << "ZZ" << std::endl;
        out << " ZZ" << std::endl;
    }
    else if (game.GetNext() == 'S'){


        out << " SS" << std::endl;
        out << "SS" << std::endl;
    }
    else if (game.GetNext() == 'J'){


        out << "J" << std::endl;
        out << "JJJ" << std::endl;
    }
    else if (game.GetNext() == 'L'){


        out << "  L" << std::endl;
        out << "LLL" << std::endl;
    }

    return out;

}

void Game::Pickup(){

  for (auto &row: CurrentPiece->getlayout()){
      for (auto &col : row){
        if (col.getType() != 'e'){
          g->unfill(col.getRow(),col.getCol());
      }
    }
  }



}

void Game::Putdown()
{


  for (auto &row: CurrentPiece->getlayout()){
      for (auto &col : row){
          if (col.getCol() < 0 || col.getCol() > 10 || col.getRow() < 0 || col.getRow()  > 17){

            throw ("get seg fault kid");
          }
          if (col.getType() != 'e'){
          g->setPiece(col.getRow(),col.getCol(),col.getType());
      }
    }
  }
}



void Game::rotate_clock(){
Pickup();

CurrentPiece -> rotate_clock();

if (!taken()){


try{Putdown();}

catch(...){

//get seg fault kid
CurrentPiece -> rotate_counterclock();
Putdown();
}
}

else {CurrentPiece -> rotate_counterclock();
Putdown();

}

if (level >= 3){

down();


}
}

void Game::rotate_counterclock(){

  Pickup();

  CurrentPiece -> rotate_clock();

  if (!taken()){


  try{Putdown();}

  catch(...){

  //get seg fault kid
CurrentPiece ->   rotate_clock();
  Putdown();
  }
  }

  else {CurrentPiece ->  rotate_clock();
  Putdown();


}
if (level >= 3){

down();


}
}
void Game::drop(){
    bool wentDown = true;

    while (wentDown)
        wentDown = down();
    
    score += g->Check();
    CurrentPiece = new Opiece;
    NextPiece();
}

void Game::S(){
    if (CurrentPiece){
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                g->setPiece(col.getRow(),col.getCol(),'e');
            }
        }
    }

    CurrentPiece = new Spiece();

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){
            g->setPiece(col.getRow(),col.getCol(),col.getType());
        }
    }
}

void Game::T(){
    if (CurrentPiece){
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                g->setPiece(col.getRow(),col.getCol(),'e');
            }
        }
    }

    CurrentPiece = new Tpiece();

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){

            g->setPiece(col.getRow(),col.getCol(),col.getType());
        }
    }


}
void Game::I(){
    if (CurrentPiece){
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                g->setPiece(col.getRow(),col.getCol(),'e');
            }
        }
    }

    CurrentPiece = new Ipiece();

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){

            g->setPiece(col.getRow(),col.getCol(),col.getType());
        }
    }
}

void Game::L(){
    if (CurrentPiece){
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                g->setPiece(col.getRow(),col.getCol(),'e');
            }
        }
    }

    CurrentPiece = new Lpiece();

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){

            g->setPiece(col.getRow(),col.getCol(),col.getType());
        }
    }
}

void Game::J(){
    if (CurrentPiece){
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                g->setPiece(col.getRow(),col.getCol(),'e');
            }
        }
    }

    CurrentPiece = new Jpiece();

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){

            g->setPiece(col.getRow(),col.getCol(),col.getType());
        }
    }
}

void Game::O(){
    if (CurrentPiece){
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                g->setPiece(col.getRow(),col.getCol(),'e');
            }
        }
    }

    CurrentPiece = new Opiece();

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){
            g->setPiece(col.getRow(),col.getCol(),col.getType());
        }
    }
}


void Game::Z(){
    if (CurrentPiece){
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                g->setPiece(col.getRow(),col.getCol(),'e');
            }
        }
    }

    CurrentPiece = new Zpiece();

    for (auto &row: CurrentPiece->getlayout()){
        for (auto &col : row){
            g->setPiece(col.getRow(),col.getCol(),col.getType());
        }
    }
}

void Game::setNextPiece(char pieceType){
    nextPiece = pieceType;
}


void Game::Clear(){


    g->clear(17);


}
