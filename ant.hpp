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
   int xcoord;
   int ycoord;
   // create an enum(eration) for the orientation
   // enum direction { north, south, east, west };
   // direction orientation;
   char orientation = 'n';
   Board* board;
public:
   Ant(int, int, Board&);
   // void updateLocation(int&, int&);
   void updateLocation();
   // void updateOrientation(direction&);
   int getX();
   int getY();
   // void move();
};
#endif
