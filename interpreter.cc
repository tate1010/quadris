#include "interpreter.h"
#include "game.h"
#include <iostream>
interpreter::interpreter(){

    livegame = new Game();
    std::cout << *livegame;



}
void interpreter::call(std::string command){

    if( command == "left"){
      livegame->left();
      std::cout << *livegame;
    }
    else if( command == "right"){
      livegame->right();
      std::cout << *livegame;

    }
    else if( command == "down"){
      livegame->down();
      std::cout << *livegame;

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
    else if (command == "t"){
      livegame->T();
      std::cout << *livegame;

    }
    else if (command == "j"){
      livegame->J();
      std::cout << *livegame;

    }
    else if (command == "l"){
      livegame->L();
      std::cout << *livegame;

    }
    else if (command == "o"){
      livegame->O();
      std::cout << *livegame;

    }
    else if (command == "i"){
      livegame->I();
      std::cout << *livegame;

    }
    else if (command == "z"){
      livegame->Z();
      std::cout << *livegame;

    }


}
