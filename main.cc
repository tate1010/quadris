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

struct prefix_node{
    prefix_node* children[26];
    int count = 0;

};



string trie_search(prefix_node* root , std::string word){


    if (word == "") {

        if (root -> count == 0 )return "";


        else if (root->count == 1){

            for (int i = 0;   i < 26; ++i){

                if(root->children[i]){

                    return char('a'+ i) + trie_search(root->children[i],"");
                }

            }
        }



    }
    int letter = word[0] - 'a';
    string newString(word.begin()+1, word.end());

    if(!root) return "";


    else if (!root -> children[letter]) return "";


    else {

        return (word[0] + trie_search(root -> children[letter],newString));
    }
}

void trie_insert(prefix_node* root, string word){
    if (word != ""){
        char letter = word[0] - 'a';
        string newString(word.begin()+1,word.end());
        if (root -> children[letter]){

            trie_insert(root->children[letter],newString);

        }
        else {
            root->count ++;
            prefix_node* newnode = new prefix_node;
            root->children[letter] = newnode;
            trie_insert(root->children[letter],newString);

        }
    }

}






int main(){
    interpreter run;
    prefix_node *root = new prefix_node;

    trie_insert(root,"left");
    trie_insert(root,"right");
    trie_insert(root,"clockwise");
    trie_insert(root,"counterclockwise");
    trie_insert(root,"down");
    trie_insert(root,"leveldown");
    trie_insert(root,"levelup");
    trie_insert(root,"drop");
    trie_insert(root,"norandom");
    trie_insert(root,"random");
    trie_insert(root,"sequence");
    trie_insert(root,"restart");
    trie_insert(root,"hint");
    trie_insert(root,"S");
    ////

//why?

    ///

    //cout << trie_search(root, "lef");
    string command;
    while (cin >> command){
        int letter = 0;
        while (isdigit(command[letter])){
            ++letter;
        }

        string mul(command.begin(), command.begin()+letter);
        string interp(command.begin()+letter,command.end());

        interp = trie_search(root,interp);

        if (interp == "restart" || interp == "hint" || interp == "norandom" || interp == "random"){
            run.call(interp);
        }
        else if(mul == ""){
            run.call(interp);


        }
        else{
            for (int i = 0 ; i < stoi(mul) ; ++i){
                //do more shit
                run.call(interp);

            }
        }
    }

}
