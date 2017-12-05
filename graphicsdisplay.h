#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "grid.h"
#include "window.h"
#undef None
#include "info.h"
class Cell;

class GraphicsDisplay {
  const int gridSize, winSize;
  Xwindow xw;
 public:
  GraphicsDisplay(int gridSize, int winSize);
  void update(Grid *g);

};
#endif
