/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description:
*********************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include<string>
#include<iostream>
using std::cout;
using std::endl;

class Board{
private:
   int rows;
   int columns;
   std::string** board;
   int lastx = 1;
   int lasty = 1;
   int turn = 0;
   int maxTurns = -35425;  // initialized value is to support debugging
public:
   // default constructor
   Board(int r, int c);

   int getSteps();
   int getMaxSteps();
   void print();
   void freeMemory();
   void updateBoard(int x, int y);
   void setMaxTurns(int numTurns);
   void addTurn();
   int getColumns();
   int getRows();
};
#endif
