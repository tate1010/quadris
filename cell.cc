
#include <iostream>
#include "cell.h"
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "info.h"

Cell::Cell(size_t r, size_t c):r(r),c(c){}


void Cell::setPiece(Colour ncolour){
if( Colour != None)
{

    throw true;
}

State thecopy ;
thecopy.type = StateType::NewPiece;
thecopy.colour = ncolour;

setState(thecopy);

colour = ncolour;
//r is row
//c is col

//observers is every fucking thing around it

}

Direction whereufrom(size_t r,size_t c, size_t originR, size_t originC){
    Direction dir;

if (r > originR){
    //higher row? E, NE,SE

    if (c== originC){
    dir = Direction::S;

    }
    else if (c > originC){
    dir = Direction::SE;


    }
    else dir = Direction::SW;

}
else if (r < originR){
    //higher row? E, NE,SE
     if (c== originC){
    dir = Direction::N;

    }
    else if (c > originC){
    dir = Direction:: NE;


    }
    else dir = Direction::NW;

}
else{


 if (c > originC){
    dir = Direction::E;


    }
    else dir = Direction::W;


}

return dir;
}

void Cell::toggle(){

if( colour == Colour::Black){

    colour = Colour::White;

}
else if (colour == Colour::White) {

    colour =Colour::Black;

}

}


void Cell::notify(Subject<Info, State> &whoFrom){

if (colour != Colour::None){
if (whoFrom.getState().type == StateType::NewPiece){
//Relay
//DO NOTHING IF SAME COLOUR


if(colour != whoFrom.getState().colour){
size_t originR = whoFrom.getInfo().row;
size_t originC = whoFrom.getInfo().col;


Direction dir = whereufrom(r,c, originR,originC);
//W


      //LET PPL KNOW DIFERENT COLOUR MY BOIS

State thecopy = whoFrom.getState();
thecopy.type = StateType::Relay;
thecopy.direction = dir;
setState(thecopy);


notifyObservers();


//Relay
}}
//else stop


else if (whoFrom.getState().type == StateType::Relay){

//go foward

//HEY IM RELAYING;
//ONLY TO THOSE IN MY DIRECITON THO

Direction origindir = whoFrom.getState().direction;
size_t originR = whoFrom.getInfo().row;
size_t originC = whoFrom.getInfo().col;
Direction dir = whereufrom(r,c, originR,originC);
//LINE CHECK

//

if (dir != origindir){
//u not in my line, go away;
//do nothing??
}
else {
//ok u in my line, r u same colour as the VERY origin??

if (colour == whoFrom.getState().colour){
        //YOYOYO GO BACK!!

State thecopy = whoFrom.getState();
thecopy.type = StateType::Reply;
//thecopy.colour = whoFrom.getState().colour;

//SWITCH DIR GOGO
if (dir == Direction::N){
    dir = Direction::S;

}
else if (dir == Direction::S){
    dir =Direction::N;

}
else if (dir == Direction::E){

    dir = Direction::W;

}
else if (dir == Direction::W){

    dir = Direction::E;

}
else if (dir == Direction::NE){
    dir = Direction::SW;

}
else if (dir == Direction::NW){
    dir =Direction::SE;

}
else if (dir == Direction::SE){
    dir = Direction::NW;

}
else if (dir == Direction::SW){
    dir = Direction::NE;

}
thecopy.direction = dir;
setState(thecopy);
notifyObservers();


}

else{
    //YOYOYO KEEP GOING
    /*
State thecopy = getState();
thecopy.type = StateType::Relay;
thecopy.colour = whoFrom.getState().colour;
thecopy.direction = dir;



setState(thecopy);
*/

setState(whoFrom.getState());
notifyObservers();

}
}
}
else if (whoFrom.getState().type == StateType::Reply){

//go back

Direction origindir = whoFrom.getState().direction;

size_t originR = whoFrom.getInfo().row;
size_t originC = whoFrom.getInfo().col;
//LINE CHECK
Direction dir = whereufrom(r,c, originR,originC);





if (dir == origindir){

 if (colour != whoFrom.getState().colour){
        //FLIPPERINO
toggle();
//need to notify textdisplay here

//

//GOGOGO RINO JECKSON
setState(whoFrom.getState());
notifyObservers();


 }
 //else STOP LUL;
}


}

}
}




Info Cell::getInfo()const{

Info information;

information.colour= colour;

information.row = r;
information.col = c;
return information;
}
