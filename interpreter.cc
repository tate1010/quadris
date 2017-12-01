#include "interpreter.h"
#include "game.h"
#include <iostream>
interpreter::interpreter(){

    Game *livegame = new Game();
    std::cout << *livegame;
    livegame->S();
    std::cout << *livegame;

    livegame->right();
    std::cout << *livegame;
}
void interpreter::call(std::string command){

    if( command == "left"){

    }
    else if( command == "right"){


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

}
