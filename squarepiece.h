//
//  squarepiece.hpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-27.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#ifndef squarepiece_h
#define squarepiece_h

#include "piece.h"

class squarepiece : public piece
{
    int rowsize = 2;
    int colsize = 2;
    
public:
    squarepiece();
};

#endif /* squarepiece_h */
