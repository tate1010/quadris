//
//  squarepiece.cpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-27.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#include "Opiece.h"
#include "grid.h"

Opiece::Opiece() : piece(rowsize = 2, colsize = 2)
{
    
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            layout[i][j].changeBlockRow(initRow + i);
            layout[i][j].changeBlockCol(initCol + j);
            layout[i][j].changeBlockType('O');
        }
        
        std::cout<<std::endl;
    }
    
}
