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

void Ant::updateOrientation(){
   if(orientation == 'n'){
      orientation = 'e';
   }
   else if(orientation == 'e'){
      orientation = 's';
   }
   else if(orientation == 's'){
      orientation = 'w';
   }
   else if(orientation == 'w'){
      orientation = 'n';
   }
   else{
      cout << "Uh oh! It looks like there's something wrong with the ant's orientation..." << endl;
   }
}

void Ant::updateLocation(){
   cout << endl << "xcoord = " << xcoord << " | ycoord = " << ycoord << endl << endl;
   if(orientation == 'n'){
      if(ycoord == 1){
         updateOrientation();
         xcoord += 1;
      }
      else{
         ycoord -= 1;
      }
   }
   else if(orientation == 'e'){
      if(xcoord == (board->getColumns() - 2)){
         updateOrientation();
         ycoord += 1;
      }
      else{
         xcoord += 1;
      }
   }
   else if(orientation == 's'){
      if(ycoord == (board->getRows() - 2)){
         updateOrientation();
         xcoord -= 1;
      }
      else{
         ycoord += 1;
      }
   }
   else if(orientation == 'w'){
      if(xcoord == 1){
         updateOrientation();
         ycoord -= 1;
      }
      else{
         xcoord -= 1;
      }
   }
   board->updateBoard(xcoord, ycoord);
}
