//
//  Ipiece.hpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-30.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#ifndef Ipiece_h
#define Ipiece_h

#include "piece.h"
class Ipiece : public piece
{
    int initRow = 3;
    int initCol = 0; // should be grid.size/2
    int rowsize = 1;
    int colsize = 4;
    
public:
    Ipiece();
};

#endif /* Ipiece_hpp */
