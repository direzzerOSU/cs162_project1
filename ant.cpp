/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description:
*********************************************************************/

#include "ant.hpp"

Ant::Ant(int column, int row, Board& b){
   xcoord = column;
   ycoord = row;
   board = &b;
   board->updateBoard(xcoord, ycoord);
}

int Ant::getX(){
   return xcoord;
}

int Ant::getY(){
   return ycoord;
}

void Ant::updateLocation(){
   cout << endl << "xcoord = " << xcoord << " | ycoord = " << ycoord << endl << endl;
   if(orientation == 'n'){
      ycoord -= 1;
   }
   else if(orientation == 'e'){
      xcoord += 1;
   }
   else if(orientation == 's'){
      ycoord += 1;
   }
   else if(orientation == 'w'){
      xcoord -= 1;
   }
   board->updateBoard(xcoord, ycoord);
}
