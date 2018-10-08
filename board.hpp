/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description: Defines objects of type "Board", which is defined by
   the "Board" class in this header file, which includes various
   private members (i.e., attributes) and public members (i.e.,
   callable functions by objects of type "Board").
*********************************************************************/

// beginning of the include guard
#ifndef BOARD_H
#define BOARD_H

// include the required files to implement callable functions of Board objects
#include<string>
#include<iostream>
using std::cout;
using std::endl;

// the Board class, which is the area that the ant will be located
// the class defines private members, or attributes for all objects
// of type Board, and the class includes function prototypes for
// functions that are callable by Board objects
class Board{
// private members, which are not directly accessible - must be accessed
// through Board's callable functions (public members)
private:
   int rows;
   int columns;
   std::string** board;    // enables a 2D matrix for a board
   int lastx = 1;
   int lasty = 1;
   int turn = 0;
   int maxTurns = -35425;  // initialized value is to support debugging
   std::string lastTileColor;
// public members with function prototypes, which are for functions
// that Board objects can call
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
   std::string updateTile();
   std::string getLastTileColor();
};
#endif
