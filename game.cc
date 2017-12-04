#include "game.h"
#include "Opiece.h"
#include "Ipiece.h"
#include "Tpiece.h"
#include "Lpiece.h"
#include "Zpiece.h"
#include "Spiece.h"
#include "Jpiece.h"
#include "rotateCCWCases.h"
#include <iostream>
Game::Game(){
    
    g = new Grid();
    level = 1; //set at 1 for testing. please reset when needed
    score = 0;
    hiscore = 0;
    CurrentPiece = nullptr;
    GeneratePiece();
    NextPiece();
  
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
    
    if (level == 4)
    {
        if (timer == 5)
        {
            block b;
            for (int i = 17; i >= 3; i--)
            {
                if (g->getBlock(i, 5) == ' ')
                {
                    g->setPiece(i, 5, '*');
                    timer = 0;
                    break;
                }
            }
            
        }
        ++timer;
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




void Game::left(){
    
    vector <vector <block>> layout = CurrentPiece->getlayout();
    int rowsize = (int) layout.size();
    int colsize = (int) layout[0].size();
    
    int colnum = layout[0][0].getCol();
    int rownum = layout[0][0].getRow();
    
    for (int j = 0; j < colsize; j++)
    {
        for (int i = 0; i < rowsize; i++)
        {
            
        }
    }
    
    if (layout[0][0].getCol() > 0)
    {
        
        for (auto &row: CurrentPiece->getlayout())
        {
            for (auto &col : row)
            {
                if (col.getType() != ' ' && col.getType() != 'e')
                    g->setPiece(col.getRow(),col.getCol(),' ');
                
            }
        }
        
        CurrentPiece -> move_left();
        
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                
                if (col.getType() != ' ' && col.getType() != 'e')
                    g->setPiece(col.getRow(),col.getCol(),col.getType());
            }
        }
    }
}

void Game::right()
{
    vector <vector <block>> layout = CurrentPiece->getlayout();
    int colsize = (int)layout[0].size();
    int rowsize = (int) layout.size();
    
    int lastColNum = layout[0][colsize-1].getCol();
    int rownum = layout[0][0].getRow();
    
    for (int i = 0; i < rowsize; i++)
    {
        if (g->getBlock(i+rownum, lastColNum + 1) != ' ' &&
            (g->getBlock(i+rownum, lastColNum) != 'e' && g->getBlock(i+rownum, lastColNum) != ' '))
        {
            return;
        }
    }
    
    if (layout[0][colsize-1].getCol() < 10)
    {
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                if (col.getType() != ' ' && col.getType() != 'e')
                    g->setPiece(col.getRow(),col.getCol(),' ');
            }
        }
        
        CurrentPiece->move_right();
        
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                
                if (col.getType() != ' ' && col.getType() != 'e')
                    g->setPiece(col.getRow(),col.getCol(),col.getType());
            }
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
            if (col.getType() != 'e'){
                g->setPiece(col.getRow(),col.getCol(),col.getType());
            }
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

void Game::rotate_clock(){
    vector <vector <block>> layout = CurrentPiece->getlayout();
    
    if (11-layout[0][0].getCol() > layout.size()-1)
    {
        
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                
                g->setPiece(col.getRow(),col.getCol(),' ');
            }
        }
        
        CurrentPiece -> rotate_clock();
        
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                
                g->setPiece(col.getRow(),col.getCol(),col.getType());
            }
        }
    }
    
    
}

void Game::rotate_counterclock(){
    
    vector <vector <block>> layout = CurrentPiece->getlayout();
    
    
    if (11-layout[0][0].getCol() > layout.size()-1)
    {
        
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                
                g->setPiece(col.getRow(),col.getCol(),' ');
            }
        }
        
        CurrentPiece -> rotate_counterclock();
        
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                
                g->setPiece(col.getRow(),col.getCol(),col.getType());
            }
        }
    }
    
}
void Game::drop(){
    int amount = 15 ;
    
    for (int col = 0; col < 11; ++col){
        for (auto &a : CurrentPiece->getlayout()){
            for (auto &b : a){
                if (b.getType() != 'e'|| b.getType() != ' '){
                    if( b.getCol() == col){
                        if(amount > g->Hitbox()[col]-b.getRow()){
                            amount= g->Hitbox()[col]-b.getRow();
                        }
                    }
                }
            }
        }
    }
    
    for(int times = amount; times > 0 ; --times ){
        down();
    }
    //calculate hitbox now
    
    for (auto &a : CurrentPiece->getlayout()){
        for (auto &b : a){
            
            if (b.getType() != 'e'){
                
                if ( g->Hitbox()[b.getCol()] > b.getRow()-1){
                    
                    g->Hitbox()[b.getCol()] = b.getRow()-1;
                    
                }
                
            }
        }
    }
    
    g->Check();
    
    //
    NextPiece();
}

void Game::S(){
    if (CurrentPiece){
        for (auto &row: CurrentPiece->getlayout()){
            for (auto &col : row){
                g->setPiece(col.getRow(),col.getCol(),' ');
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
                g->setPiece(col.getRow(),col.getCol(),' ');
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
                g->setPiece(col.getRow(),col.getCol(),' ');
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
                g->setPiece(col.getRow(),col.getCol(),' ');
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
                g->setPiece(col.getRow(),col.getCol(),' ');
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
                g->setPiece(col.getRow(),col.getCol(),' ');
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
                g->setPiece(col.getRow(),col.getCol(),' ');
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
