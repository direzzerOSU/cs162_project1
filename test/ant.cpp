/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description: Defines and implements the Ant class' functions,
   which are callable by objects/variables of type Ant. This file also
   defines the constructor, which places the ant on its applicable
   board in its proper position.
*********************************************************************/

// include the ant header, defining the Ant class for objects of type Ant
#include "ant.hpp"

// constructor, which places an ant on a particular board in a particular spot
Ant::Ant(int column, int row, Board& b){
   xcoord = column;
   ycoord = row;
   board = &b;
   board->updateBoard(xcoord, ycoord);
}

// retrieves the column that the ant is located at
int Ant::getX(){
   return xcoord;
}

// retrieves the row that the ant is located at
int Ant::getY(){
   return ycoord;
}

// turn the ant 90 degrees to the right (N -> E; E -> S; S -> W; W -> N)
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

// turn the ant 90 degrees to the left (N -> W; W -> S; S -> E; E -> N)
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

// sets/changes the ant's orientation
void Ant::setOrientation(char direction){
   orientation = direction;
}

// updates the ant's orientation based on the "tile" that it stepped on (based on "color")
void Ant::tileUpdateOrientation(){
   if(board->getLastTileColor() == " "){
      updateOrientationRight();
   }
   else if(board->getLastTileColor() == "#"){
      updateOrientationLeft();
   }
}

// move the ant by 1 space (on its board) in the direction (orientation) that the ant is facing
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
