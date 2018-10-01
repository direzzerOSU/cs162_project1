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

void Ant::updateOrientationRight(){
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

void Ant::updateOrientationLeft(){
   if(orientation == 'n'){
      orientation = 'w';
   }
   else if(orientation == 'e'){
      orientation = 'n';
   }
   else if(orientation == 's'){
      orientation = 'e';
   }
   else if(orientation == 'w'){
      orientation = 's';
   }
   else{
      cout << "Uh oh! It looks like there's something wrong with the ant's orientation..." << endl;
   }
}

void Ant::setOrientation(char direction){
   orientation = direction;
}

void Ant::tileUpdateOrientation(){
   if(board->getLastTileColor() == " "){
      updateOrientationRight();
   }
   else if(board->getLastTileColor() == "#"){
      updateOrientationLeft();
   }
}

void Ant::updateLocation(){
   if(orientation == 'n'){
      if(ycoord == 1){
         if(xcoord == (board->getColumns() - 2)){
            updateOrientationLeft();
            xcoord -= 1;
         }
         else{
            updateOrientationRight();
            xcoord += 1;
         }
      }
      else{
         ycoord -= 1;
      }
   }
   else if(orientation == 'e'){
      if(xcoord == (board->getColumns() - 2)){
         if(ycoord == (board->getRows() - 2)){
            updateOrientationLeft();
            ycoord -= 1;
         }
         else{
            updateOrientationRight();
            ycoord += 1;
         }
      }
      else{
         xcoord += 1;
      }
   }
   else if(orientation == 's'){
      if(ycoord == (board->getRows() - 2)){
         if(xcoord == 1){
            updateOrientationLeft();
            xcoord += 1;
         }
         else{
            updateOrientationRight();
            xcoord -= 1;
         }
      }
      else{
         ycoord += 1;
      }
   }
   else if(orientation == 'w'){
      if(xcoord == 1){
         if(ycoord == 1){
            updateOrientationLeft();
            ycoord += 1;
         }
         else{
            updateOrientationRight();
            ycoord -= 1;
         }
      }
      else{
         xcoord -= 1;
      }
   }
   board->updateBoard(xcoord, ycoord);
   tileUpdateOrientation();
}
