#include<vector>
#include<iostream>
#include"TextDisplay.h"
using namespace std;



TextDisplay::TextDisplay(){
    theDisplay =  vector <vector <char>> (18,vector<char>(15, 'P'));
    
};

void TextDisplay::clearline(int line){
    // probably easier to do when the block are implemented
}

void TextDisplay::setRC(int r, int c , char colour){
    //DEBUG ONLY
    
    theDisplay[r+2][c] = colour;
    
}



std::ostream& operator<<(std::ostream &out, const TextDisplay&td){
    int dividerlength = 11;
    out << "Level" << std::endl;
    out << "Score" << std::endl;
    out << "Hi Score:" << std::endl;
    //divider here
    for(int divider= 1 ; divider <= dividerlength; ++divider){
        out << "-";
    }
    out << std::endl;
    //grid here
    for (int row = 3; row < 18; ++row){
        for (int col = 0; col < 11; ++ col){
            
            out << td.theDisplay[row][col];
            
        }
        out << endl;
    }
    
    //
    for(int divider= 1 ; divider <= dividerlength; ++divider){
        out << "-";
    }
    out << std::endl;
    //
    out << "Next:" << std::endl;
    
    
    return out;
}
