#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "TextDisplay.h"

class Grid{
  std::vector<std::vector<char>> theGrid;
  TextDisplay *td = nullptr;
  bool textonlydisplay = true;
  //to  do
  //GraphicDisplay
public:
   Grid();

   void display();

};
#endif
