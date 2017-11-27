#include <iostream>
#include "TextDisplay.cc"



int main(){



TextDisplay *td = new TextDisplay();
td->setRC(10,10,'N');
std::cout << *td;

}
