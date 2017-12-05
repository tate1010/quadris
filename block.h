//
//  block.h
//  a5_1
//
//  Created by Aurora Dai on 2017-11-27.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#ifndef block_h
#define block_h

class block
{
    char blockType = 0;
    /* e for empty
     * I straight piece
     * L for L piece
     * J for backL piece
     * O for Square piece
     * Z for Z piece
     * S for backZ piece
     * T for T piece
     */
    
    int blockRow;
    int blockCol;
    
    int level;
    
    
public:
    block();
    block(int blockRow, int blockCol);
    
    int getRow();
    int getCol();
    char getType();
    
    void changeBlockType(char c);
    void changeBlockRow(int a);
    void changeBlockCol(int a);
    
    void moveBlockRight();
    void moveBlockLeft();
    void moveBlockDown();
    
};

#endif /* block_h */
