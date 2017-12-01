//
//  block.cpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-29.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#include "block.h"
#include "grid.h"

block::block() {}

block::block(int blockRow, int blockCol) : blockRow(blockRow), blockCol (blockCol){};

void block::moveBlockLeft()
{
    blockCol--;
}

void block::moveBlockRight()
{
    blockCol++;
}

void block::moveBlockDown()
{
    blockRow++;
}

int block::getRow()
{
    return blockRow;
}

int block::getCol()
{
    return blockCol;
}

char block::getType()
{
    return blockType;
}

void block::changeBlockType(char c)
{
    blockType = c;
}

void block::changeBlockRow(int a)
{
    blockRow = a;
}
void block::changeBlockCol(int a)
{
    blockCol = a;
}
