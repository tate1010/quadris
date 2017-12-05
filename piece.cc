//
//  piece.cpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-27.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#include "piece.h"

piece::piece(int pieceNumRow, int pieceNumCol): layout(pieceNumRow, vector<block>(pieceNumCol)), pieceNumRow(pieceNumRow), pieceNumCol(pieceNumCol) {}




void piece::softdrop()
{
    for (auto &row : layout){
        for (auto &col : row){
            col.moveBlockDown();
        }
    }
}

void piece::move_left()
{
    for (auto &row : layout){
        for (auto &col : row){
            col.moveBlockLeft();
        }
    }
}
void piece::move_right()
{
    for (auto &row : layout){
        for (auto &col : row){
            col.moveBlockRight();
        }
    }
}


std::vector <std::vector <block>> piece::getlayout(){
    
    return layout;
    
}

char piece::getTypePiece()
{
    for (int i = 0; i < pieceNumRow; i++)
        for (int j = 0; j < pieceNumCol; j++)
            if ((layout[i][j].getType() != 'e'))
                return layout[i][j].getType();
    
    return 'e';
    
}

void piece::rotate_counterclock()
{
    int newNumRow = pieceNumCol;
    int newNumCol = pieceNumRow;
    
    int topLeftRow = layout[0][0].getRow();
    int topLeftCol = layout[0][0].getCol();
    
    piece newLayout = piece (newNumRow, newNumCol);
    
    for (int i = 0; i < pieceNumRow; i++)
    {
        for (int j = 0; j < pieceNumCol; j++)
        {
            newLayout.layout[newNumRow-j-1][i].changeBlockRow(topLeftRow+pieceNumRow-1-j);
            newLayout.layout[newNumRow-j-1][i].changeBlockCol(topLeftCol+i);
        }
    }
    
    for (int i = 0; i < pieceNumCol; i++)
    {
        for (int j = 0; j < pieceNumRow; j++)
        {
            newLayout.layout[i][j].changeBlockType(layout[j][pieceNumCol-i-1].getType());
            
        }
    }
    
   *this = newLayout; 
}
void piece::rotate_clock()
{
    
    int newNumRow = pieceNumCol;
    
    int topLeftRow = layout[0][0].getRow();
    int topLeftCol = layout[0][0].getCol();
    
    piece newLayout = piece (pieceNumCol, pieceNumRow);
    
    for (int i = 0; i < pieceNumRow; i++)
    {
        for (int j = 0; j < pieceNumCol; j++)
        {
            newLayout.layout[newNumRow-j-1][i].changeBlockRow(topLeftRow+pieceNumRow-1-j);
            newLayout.layout[newNumRow-j-1][i].changeBlockCol(topLeftCol+i);
        }
    }
    
    for (int i = 0; i < pieceNumRow; i++)
        for (int j = 0; j < pieceNumCol; j++)
            newLayout.layout[j][pieceNumRow-i-1].changeBlockType(layout[i][j].getType());
    
   *this = newLayout; 
}

std::ostream &operator<<(std::ostream &out, piece &p)
{
    size_t numrow = p.layout.size();
    size_t numcol = p.layout[0].size();
    for (int i = 0; i < numrow; i++)
    {
        for (int j = 0; j < numcol; j++)
        {
            out << p.layout[i][j].getRow() << p.layout[i][j].getCol() <<p.layout[i][j].getType() << " ";
        }
        out << std::endl;
    }
    
    return out;
}

