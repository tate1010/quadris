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


protected:
    std::vector <std::vector <block>> layout;
    piece(size_t pieceNumRow, size_t pieceNumCol) ;

public:
    piece();
    void harddrop();
    void softdrop();
    void move_left();
    void move_right();
    void rotate_counterclock();
    void rotate_clock();
    int getleftcol();
    int getrightcol();
    int getBottom();
    std::vector <std::vector <block>> getlayout();
    friend std::ostream &operator<<(std::ostream &out,  piece &p);
};

#endif /* piece_hpp */
