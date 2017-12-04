#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include "interpreter.h"
#include "block.h"
#include "piece.h"
#include "Opiece.h"
#include "Lpiece.h"
#include "Tpiece.h"
#include "Zpiece.h"
#include "Spiece.h"
#include "Jpiece.h"
#include "Ipiece.h"


using namespace std;


vector <std::string> library;


bool isPrefix(std::string str, std::string pre) {
    
    // this function checks if pre is a prefix of str
    auto res = std::mismatch(pre.begin(), pre.end(), str.begin());
    return res.first == pre.end();
}

void insert(string word){
    library.push_back(word);
    
}

string search(string search){
    string key = "";
    for (auto &word : library)
    {
        if (isPrefix(word,search)){
            if (key == ""){
                key = word;
            }
            else key = "ambigous";
        }
    }
    
    
    return key;
    
}



int main(int argc, char *argv[]){
    interpreter run;
    
    for (int i=1; i<argc; i++){
        if (argv[i] == "-scriptfile"){
            run.call("sequence",argv[i+1]);
            i++;
        }
        else if (argv[i] == "-seed"){
            //pass ("seed",argv[i+1]);
            i++;
        }
        else if (argv[i] == "-startlevel"){
            cout<<"here"<<endl;
            run.call("level",argv[i+1]);
            i++;
        }
        //else if (strcmp(argv[i],"-text") == 0){
            //somethinghere
        //}
    }
    
    insert("left");
    insert("right");
    insert("clockwise");
    insert("counterclockwise");
    insert("down");
    insert("leveldown");
    insert("levelup");
    insert("drop");
    insert("norandom");
    insert("random");
    
    insert("sequence");
    insert("restart");
    insert("hint");
    insert("S");
    insert("Z");
    insert("L");
    insert("J");
    insert("I");
    insert("O");
    insert("T");
    insert("clear");
    //
    
    
    //cout << trie_search(root, "lef");
    string command;
    while (cin >> command){
        int letter = 0;
        while (isdigit(command[letter])){
            ++letter;
        }
        
        string mul(command.begin(), command.begin()+letter);
        string interp(command.begin()+letter,command.end());
        
        
        interp = search(interp);
        
        
        if (interp == "restart" || interp == "hint" || interp == "norandom" || interp == "random"){
            run.call(interp, "");
        }
        else if(mul == ""){
            run.call(interp, "");
            
            
        }
        else{
            for (int i = 0 ; i < stoi(mul) ; ++i){
                //do more shit
                run.call(interp, "");
                
            }
        }
    }
    
}
