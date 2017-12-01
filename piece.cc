<<<<<<< HEAD
//
//  piece.cpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-27.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#include "piece.h"

piece::piece(size_t pieceNumRow, size_t pieceNumCol): layout(pieceNumRow, vector<block>(pieceNumCol)) {}



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


void piece::rotate_counterclock()
{
    size_t numrow = layout.size();
    size_t numcol = layout[0].size();


    piece newLayout = piece (layout[0].size(), layout.size());


    for (int i = 0; i < numcol; i++)
    {
        for (int j = 0; j < numrow; j++)
        {
            newLayout.layout[i][j].changeBlockType(layout[j][numcol-i-1].getType());
            newLayout.layout[i][j].changeBlockCol(layout[j][numcol-i-1].getCol());
            newLayout.layout[i][j].changeBlockRow(layout[j][numcol-i-1].getRow());

        }
    }

    layout = newLayout.layout;

}
void piece::rotate_clock()
{
    size_t numrow = layout.size();
    size_t numcol = layout[0].size();

    piece newLayout = piece (numcol, numrow);

    for (int i = 0; i < numrow; i++)
        for (int j = 0; j < numcol; j++)
            newLayout.layout[j][numrow-i-1] = layout[i][j];

    layout = newLayout.layout;

}

int piece::getleftcol(){
int icol = 11;
  for (auto &row : layout){
      for (auto &col : row){
        if (col.getCol() < icol) icol = col.getCol();
      }
  }

return icol;
}
int piece::getrightcol(){
int icol = -1;
  for (auto &row : layout){
      for (auto &col : row){
        if (col.getCol() > icol) icol = col.getCol();
      }
  }

return icol;
}
int piece::getBottom(){
int irow = 0;
  for (auto &row : layout){
      for (auto &col : row){
        if (col.getRow() > irow) irow = col.getRow();
      }
  }

return irow;
}
std::vector <std::vector <block>> piece::getlayout(){

return layout;

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
=======
//
//  piece.cpp
//  a5_1
//
//  Created by Aurora Dai on 2017-11-27.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//
using namespace std;
#include "piece.h"

piece::piece(size_t pieceNumRow, size_t pieceNumCol): layout(pieceNumRow, vector<block>(pieceNumCol)) {}



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


void piece::rotate_counterclock()
{
    int numrow = (int)layout.size();
    int numcol = (int)layout[0].size();
    
    int newNumRow = numcol;
    int newNumCol = numrow;
    
    int topLeftRow = layout[0][0].getRow();
    int topLeftCol = layout[0][0].getCol();
    
    piece newLayout = piece (newNumRow, newNumCol);

    for (int i = 0; i < numrow; i++)
    {
        for (int j = 0; j < numcol; j++)
        {
            newLayout.layout[newNumRow-j-1][i].changeBlockRow(topLeftRow+numrow-1-j);
            newLayout.layout[newNumRow-j-1][i].changeBlockCol(topLeftCol+i);
        }
    }
    
    for (int i = 0; i < numcol; i++)
    {
        for (int j = 0; j < numrow; j++)
        {
            newLayout.layout[i][j].changeBlockType(layout[j][numcol-i-1].getType());
            
        }
    }
    
    layout = newLayout.layout;
    
}
void piece::rotate_clock()
{
    int numrow = (int)layout.size();
    int numcol = (int)layout[0].size();
    
    int newNumRow = numcol;
    int newNumCol = numrow;
    
    int topLeftRow = layout[0][0].getRow();
    int topLeftCol = layout[0][0].getCol();
    
    piece newLayout = piece (numcol, numrow);
    
    for (int i = 0; i < numrow; i++)
    {
        for (int j = 0; j < numcol; j++)
        {
            newLayout.layout[newNumRow-j-1][i].changeBlockRow(topLeftRow+numrow-1-j);
            newLayout.layout[newNumRow-j-1][i].changeBlockCol(topLeftCol+i);
        }
    }
    
    for (int i = 0; i < numrow; i++)
        for (int j = 0; j < numcol; j++)
            newLayout.layout[j][numrow-i-1].changeBlockType(layout[i][j].getType());
    
    layout = newLayout.layout;
    
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
>>>>>>> b38bd281bd5854fa787228d1cd7c8ff609480f2a
