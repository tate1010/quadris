#include "interpreter.h"
#include "game.h"
#include <iostream>
interpreter::interpreter(){

    livegame = new Game();
    std::cout << *livegame;



}
void interpreter::call(std::string command){

    if( command == "left"){

    }
    else if( command == "right"){
      livegame->right();
      std::cout << *livegame;

    }
    else if( command == "down"){


    }
    else if( command == "clockwise"){


    }
    else if( command == "counterclockwise"){


    }
    else if( command == "levelup"){


    }
    else if( command == "leveldown"){


    }
    else if( command == "restart"){


    }
    else if( command == "sequence"){


    }
    else if( command == "hint"){


    }
    else if( command == "random"){


    }
    else if (command == "norandom"){


    }
    else if (command == "s"){
      livegame->S();
      std::cout << *livegame;

    }

}
