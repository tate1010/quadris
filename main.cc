  #include <iostream>
  #include "grid.h"
  using namespace std;

  int main(){



  Grid *g = new Grid();
  g->setPiece(10,10,'r');
  cout << *g;
  g->clear(10);
  cout << *g;
  }
