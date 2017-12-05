#include "interpreter.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

interpreter::interpreter(){
    
    livegame = new Game();
    
}

/*
 void interpreter::seed(int seed){
 srand(seed);
 }
 */

void interpreter::call(std::string command, std::string arg){
    if (command == "level"){
        //std::cout << "current level" << arg << std::endl;
        std::istringstream stringToInt {arg};
        int level;
        stringToInt >> level;
        livegame->changeLevel(level);
    }
    else if( command == "sequence"){
        std::string sequenceFileName;
        if (arg != "")
            sequenceFileName = arg;
        else
            std::cin >> sequenceFileName;
        //std::cout << "sequence file received: " << sequenceFileName << std::endl;
        std::ifstream sequenceFile (sequenceFileName);
        std::string currentCommand;
        //sequenceFile.is_open() ? std::cout << "yes" : std::cout <<  "no";
        if (sequenceFile.is_open()) {
            
            while (sequenceFile >> currentCommand) {
                
                if (currentCommand == "left")
                    livegame->left();
                else if (currentCommand == "right")
                    livegame->right();
                else if (currentCommand == "down")
                    livegame->down();
                else if (currentCommand == "drop")
                    livegame->drop();
                else if (currentCommand == "levelup")
                    livegame->levelup();
                else if (currentCommand == "leveldown")
                    livegame->leveldown();
                else if (currentCommand == "clockwise")
                    livegame->rotate_clock();
                else if (currentCommand == "counterclockwise")
                    livegame->rotate_counterclock();
                else if (currentCommand == "sequence"){
                    std::string fileName;
                    sequenceFile >> fileName;
                    call("sequence", fileName);
                }
                // the block cases
                else if (currentCommand == "I")
                    livegame->I();
                else if (currentCommand == "T")
                    livegame->T();
                else if (currentCommand == "O")
                    livegame->O();
                else if (currentCommand == "Z")
                    livegame->Z();
                else if (currentCommand == "S")
                    livegame->S();
                else if (currentCommand == "J")
                    livegame->J();
                else if (currentCommand == "L")
                    livegame->L();
                std:: cout << *livegame;
                livegame -> graphic();
            }
        }
    }
    //std::cout << *livegame;
    else if( command == "left"){
        livegame->left();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if( command == "right"){
        livegame->right();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if( command == "down"){
        livegame->down();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "drop"){
        
        livegame->drop();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if( command == "clockwise"){
        livegame->rotate_clock();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if( command == "counterclockwise"){
        
        livegame->rotate_counterclock();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if( command == "levelup"){
        livegame->levelup();
        
    }
    else if( command == "leveldown"){
        
        livegame->leveldown();
        
    }
    else if( command == "restart"){
        //todo
        
    }
    /*else if( command == "hint"){
     
     
     }
     else if( command == "random"){
     
     
     }
     */
    else if (command == "norandom"){
        call("sequence", "");
    }
    else if (command == "S"){
        livegame->S();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "T"){
        livegame->T();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "J"){
        livegame->J();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "L"){
        livegame->L();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "O"){
        livegame->O();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "I"){
        livegame->I();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "Z"){
        livegame->Z();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "clear"){
        livegame->Clear();
        std::cout << *livegame;
        livegame -> graphic();
    }
    else if (command == "print"){
        std::cout << *livegame;
        livegame -> graphic();
    }
}
