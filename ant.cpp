/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description:
*********************************************************************/

#include "ant.hpp"

Ant::Ant(int column, int row, Board b){
   xcoord = column;
   ycoord = row;
   board = &b;
   // board->board[ycoord][xcoord] = "*";
   board->updateBoard(1, 1);
}

int Ant::x(){
   return xcoord;
}

int Ant::y(){
   return ycoord;
}

// void Ant::updateLocation
