#include "interpreter.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
                    call("sequence");
                }
                else if (currentCommand == "I" || currentCommand == "T" || currentCommand == "O" || currentCommand == "Z" || currentCommand == "S" || currentCommand == "J" || currentCommand == "L" )
                    livegame->setNextPiece(currentCommand[0]);
                
                //std::cout << *livegame; // for individual step
            }
            std::cout << *livegame;
        }
        // need other commands here
        
        
        /*
         else if (command == "norandom") {
         std::string noRandomFile;
         sequenceFile >> noRandomFile;
         norandom(noRandomFile);
         }
         */
        /*
         else if (command == "sequence") {
         std::string seqFileName;
         sequenceFile >> seqFileName;
         sequence(seqFileName);
         }*/
        
        /*
         else if (seqcommand == "I")
         livegame->setNextPiece('I');
         else if (seqcommand == "T")
         livegame->setNextPiece('T');
         else if (seqcommand == "O")
         livegame->setNextPiece('O')
         else if (seqcommand == "Z")
         livegame->setNextPiece('Z')
         else if (seqcommand == "S")
         livegame->S();
         else if (seqcommand == "J")
         livegame->J();
         else if (seqcommand == "L")
         livegame->L();
         */
        
        /*
         else if (command == "restart")
         restart();   // the restart function - rename if necesssary
         else if (command == "hint") {
         //code here
         }
         */
        
        
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
