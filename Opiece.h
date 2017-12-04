//
//  squarepiece.hpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-27.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#ifndef Opiece_h
#define Opiece_h

#include "piece.h"

class Opiece : public piece
{
    int initRow = 3;
    int initCol = 0; // should be grid.size/2
    int rowsize = 2;
    int colsize = 2;
    
public:
    Opiece();
};

#endif /* squarepiece_h */
