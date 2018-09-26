/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description:
*********************************************************************/

#ifndef ANT_H
#define ANT_H

#include "board.hpp"
#include<iostream>
using std::endl;
using std::cout;
using std::cin;
#include<string>
using std::string;

class Ant{
private:
   int xcoord = 0;
   int ycoord = 0;
   char orientation = 'n';
   Board* board;
public:
   Ant(int, int, Board);
   void updateLocation(int&, int&);
   void updateOrientation(char&);
   int x();
   int y();
};
#endif
