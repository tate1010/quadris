<<<<<<< HEAD
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
=======
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
    int initRow = 3;
    int initCol = 5; // should be grid.size/2
    int rowsize = 2;
    int colsize = 3;
    
public:
    Lpiece();
};

#endif /* Lpiece_h */
>>>>>>> b38bd281bd5854fa787228d1cd7c8ff609480f2a
