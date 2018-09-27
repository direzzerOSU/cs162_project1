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
   int lastx;
   int lasty;
   int turn = 0;
public:
   // default constructor
   Board(int r, int c);

   void print();
   void freeMemory();
   void updateBoard(int x, int y);
};
#endif