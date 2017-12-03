#include "interpreter.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <string>
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
    else if (command == "drop"){
        
        livegame->drop();
        std::cout << *livegame;
    }
    else if( command == "clockwise"){
        livegame->rotate_clock();
        std::cout << *livegame;
        
    }
    else if( command == "counterclockwise"){
        
        livegame->rotate_counterclock();
        std::cout << *livegame;
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
    else if( command == "sequence"){
        std::string sequenceFileName;
        std::cin >> sequenceFileName;
        //std::cout << "sequence file received: " << sequenceFileName << std::endl;
        std::string seqcommand;
        std::ifstream sequenceFile (sequenceFileName);
        //sequenceFile.is_open() ? std::cout << "yes" : std::cout <<  "no";
        if (sequenceFile.is_open()) {
            std::cout << "File opened?" << std::endl;
            std::cout << "command" <<  seqcommand << std::endl;
            while (sequenceFile >> seqcommand) {
                if (seqcommand == "left")
                    livegame->left();
                else if (seqcommand == "right")
                    livegame->right();
                else if (seqcommand == "down")
                    livegame->down();
                else if (seqcommand == "drop")
                    livegame->drop();
                else if (seqcommand == "levelup")
                    livegame->levelup();
                else if (seqcommand == "leveldown")
                    livegame->leveldown();
                else if (seqcommand == "clockwise")
                    livegame->rotate_clock();
                else if (seqcommand == "counterclockwise")
                    livegame->rotate_counterclock();
                /*else if (command == "norandom") {
                 std::string noRandomFile;
                 sequenceFile >> noRandomFile;
                 norandom(noRandomFile);
                 }*/
                /*else if (command == "sequence") {
                    std::string seqFileName;
                    sequenceFile >> seqFileName;
                    sequence(seqFileName);
                }*/
                else if (seqcommand == "I")
                    livegame->I();
                else if (seqcommand == "T")
                    livegame->T();
                else if (seqcommand == "O")
                    livegame->O();
                else if (seqcommand == "Z")
                    livegame->Z();
                else if (seqcommand == "S")
                    livegame->S();
                else if (seqcommand == "J")
                    livegame->J();
                else if (seqcommand == "L")
                    livegame->L();
                /*
                 else if (command == "restart")
                 restart();   // the restart function - rename if necesssary
                 else if (command == "hint") {
                 //code here
                 }
                 */
                std::cout << *livegame;
            }
        }
    }
            /*else if( command == "hint"){
             
             
            }
            else if( command == "random"){
             
             
            }
            else if (command == "norandom"){
             
             
            }*/
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
            else if (command == "clear"){
                livegame->Clear();
                std::cout << *livegame;
            }
}
