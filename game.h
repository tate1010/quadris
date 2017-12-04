#ifndef Game_H
#define Game_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "grid.h"
#include "piece.h"

class Game{
    Grid *g;
    piece *CurrentPiece;
    char nextPiece;
    int level;
    int score;
    int hiscore;
    int timer = -1 ; //used in level 4 only
    long long seed = 0;
public:
    Game();

    void left();
    void right();
    void down();
    void drop();
    void GeneratePiece();
    void levelup();
    void leveldown();
    void NextPiece();
    void rotate_clock();
    void rotate_counterclock();
    void endGame();
     //replace current with next Piece
    //ToDO
    //void rotate_clock();
    //void rotate_counterclock();

    //void no random + sequence
    //void restart. maybe need to do outside
    //void Hint



    //for testing here
    char GetNext();
    void setNextPiece(char pieceType);
    void I();
    void T();
    void L();
    void Z();
    void S();
    void O();
    void J();
    void Clear();
    //
    friend  std::ostream& operator<<(std::ostream &out,  Game &game);

};
#endif
