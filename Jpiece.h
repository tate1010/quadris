//
//  Jpiece.hpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-30.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#ifndef Jpiece_h
#define Jpiece_h

#include "piece.h"
class Jpiece : public piece
{
    int initRow = 3;
    int initCol = 0; // should be grid.size/2
    int rowsize = 2;
    int colsize = 3;
    
public:
    Jpiece();
};

#endif /* Jpiece_hpp */
