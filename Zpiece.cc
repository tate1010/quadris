//
//  Zpiece.cpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-30.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#include "Zpiece.h"
#include "grid.h"

Zpiece::Zpiece() : piece(rowsize = 2, colsize = 3)
{
    
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            layout[i][j].changeBlockRow(initRow + i);
            layout[i][j].changeBlockCol(initCol + j);
            if ((i == 0 && j == 2) || (i == 1 && j == 0))
                layout[i][j].changeBlockType('e');
            else
                layout[i][j].changeBlockType('Z');
        }
    }
}

