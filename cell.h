#ifndef CELL_H
#define CELL_H

#include <cstddef>


class Cell{
    const size_t r, c;
    int level = 0;
    char block;
    bool filled = false;
    // Add other private members if necessary

public:
    Cell(size_t r, size_t c);
    int getLevel();
    void setPiece(char block);    // Place a piece of given colour here.
    void setPiece(char block, int level);
    char getBlock();
    bool Filled();
    void unfill();
    //  void notify(Subject<Info, State> &whoFrom) override;// My neighbours will call this
    // when they've changed state
    //Info getInfo() const override;
};
#endif
