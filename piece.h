//
//  piece.hpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-27.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#ifndef piece_h
#define piece_h

#include "block.h"
#include <iostream>
#include <vector>

using std::vector;

class piece
{
    int pieceNumRow = 0;
    int pieceNumCol = 0;
    
protected:
    std::vector <std::vector <block>> layout;
    piece(int pieceNumRow, int pieceNumCol) ;
    
public:
    void harddrop();
    void softdrop();
    void move_left();
    void move_right();
    void rotate_counterclock();
    void rotate_clock();
    
    std::vector <std::vector <block>> getlayout();
    char getTypePiece();
    friend std::ostream &operator<<(std::ostream &out,  piece &p);
    
};

#endif /* piece_hpp */

