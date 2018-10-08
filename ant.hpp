/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description: Defines the ant class and associates the ant to its
   board variable via a pointer. This header also defines various
   functions, which are object oriented functions and callable by
   variables of type Ant.
*********************************************************************/

// include guard
#ifndef ANT_H
#define ANT_H

// includes the files that are required by Ant
#include "board.hpp"
#include<iostream>
using std::endl;
using std::cout;
using std::cin;
#include<string>
using std::string;

// defines the Ant class, including the attributes
// for each object/variable and the "callable" functions of type "Ant"
class Ant{
// private members: cannot be accessed directly & define the attributes of each Ant object
private:
   int xcoord;
   int ycoord;
   char orientation = 'n';
   Board* board;
// public: callable functions by Ant objects, including ways to update Ant objects' private members
public:
   // constructor
   Ant(int, int, Board&);
   // update the ant's location by 1 space
   void updateLocation();
   // turn the ant 90 degrees to the right (N -> E; E -> S; S -> W; W -> N)
   void updateOrientationRight();
   // turn the ant 90 degrees to the left (N -> W; W -> S; S -> E; E -> N)
   void updateOrientationLeft();
   // based on the "color" of the "tile" that the ant steps on, update the ant's orientation
   void tileUpdateOrientation();
   // get the ant's column
   int getX();
   // get the ant's row
   int getY();
   // change the orientation of the ant (i.e., N, E, S, W - like a compass)
   void setOrientation(char);
};
#endif   // end of include guard
