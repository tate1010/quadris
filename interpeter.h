#ifndef interpeter_H
#define interpeter_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "TextDisplay.h"

class Interpeter{
  std::vector<std::vector<Cell>> theGrid;
  TextDisplay *td = nullptr;
  bool textonlydisplay = true;
  //to  do
  //GraphicDisplay
public:
   left();
   right();
   down();
   clockwise();
   counterclockwise();
   drop();
   levelup();
   leveldown();
   norandom();
   sequence(file file);
   restart();
   Hint();
};
#endif
