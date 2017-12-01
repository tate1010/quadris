<<<<<<< HEAD:squarepiece.h
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
=======
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

class Opiece : public piece
{
    int initRow = 3;
    int initCol = 5; // should be grid.size/2
    int rowsize = 2;
    int colsize = 2;
    
public:
    Opiece();
};

#endif /* squarepiece_h */
>>>>>>> b38bd281bd5854fa787228d1cd7c8ff609480f2a:Opiece.h
