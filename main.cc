#include <iostream>

#include "grid.cc"


int main(){



Grid *g = new Grid();
g->setPiece(10,10,'r');
cout << *g;
g->clear(10);
cout << *g;
}
