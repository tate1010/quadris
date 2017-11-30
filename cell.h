#ifndef CELL_H
#define CELL_H

#include <cstddef>


class Cell{
  const size_t r, c;
  char block;
  bool filled = false;
  // Add other private members if necessary

 public:
  Cell(size_t r, size_t c);

  void setPiece(char block);    // Place a piece of given colour here.
  char getBlock();
  bool Filled();
//  void notify(Subject<Info, State> &whoFrom) override;// My neighbours will call this
                                                // when they've changed state
  //Info getInfo() const override;
};
#endif
