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
if (isPrefix(word,search){
if (key == ""){
key = word;
}
else key = "ambigous";
}
}


return key;
}
