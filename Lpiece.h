//
//  Lpiece.hpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-30.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#ifndef Lpiece_h
#define Lpiece_h
#include "piece.h"

class Lpiece : public piece
{
    int rowsize = 2;
    int colsize = 3;
    
public:
    Lpiece();
};

#endif /* Lpiece_h */
