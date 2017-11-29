#ifndef interpreter_H
#define interpreter_H
#include <iostream>
#include <vector>
#include <cstddef>

class interpreter{

  //to  do
  //GraphicDisplay
public:
   void left();
   void right();
   void down();
   void clockwise();
   void counterclockwise();
   void drop();
   void levelup();
   void leveldown();
   void norandom();
   void sequence(std::string file);
   void restart();
   void Hint();
   void call(std::string command);
};
#endif
