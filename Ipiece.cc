//
//  Ipiece.cpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-30.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#include "Ipiece.h"

Ipiece::Ipiece() : piece(rowsize = 1, colsize = 4)
{
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            layout[i][j].changeBlockRow(initRow + i);
            layout[i][j].changeBlockCol(initCol + j);
            layout[i][j].changeBlockType('I');
        }
    }
}
