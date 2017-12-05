#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>

class Cell;

class TextDisplay {
    std::vector<std::vector<char>> theDisplay;
    
public:
    TextDisplay();
    void setRC(int r, int c , char colour);
    //debug only
    
    // void notify(Subject<Info, State> &whoNotified) override;
    void clearline(int line);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif

