#include <iostream>
#include "graphicsdisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int gridSize, int winSize):
 gridSize{gridSize}, winSize{winSize}, xw{winSize, winSize} {
  xw.fillRectangle(0, 0, winSize, winSize, Xwindow::Blue);
}


void GraphicsDisplay::update(Grid*  g){

    std::vector <std:: vector <char>> display = g->layout();

int  r = 0;


for (auto &col : display){
int c = 0;

for (auto &row : col)
{

  int colour = 0;

  if (row == 'I'){colour = 1;}
  else if (row == 'T'){colour = 2;}
  else if (row == 'O'){colour = 3;}
  else if (row == 'Z'){colour = 4;}
  else if (row == 'S'){colour = 5;}
  else if (row == 'J'){colour = 6;}
  else if (row == 'L'){colour = 7;}

  xw.fillRectangle(c*gridSize,r*gridSize,gridSize,gridSize,colour);

++c;

}

++r;
}

}
  /*
void GraphicsDisplay::notify(Subject<Info, State> &whoNotified) {
  auto info = whoNotified.getInfo();
  int cellSize = winSize / gridSize;



  switch(info.colour) {
   case Colour::Black:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Black);
    break;
   case Colour::White:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::White);
    break;
   default:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Blue);
  }


*/
