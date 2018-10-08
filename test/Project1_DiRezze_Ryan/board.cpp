/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description: Implements all functions, which are callable by objects
   of type Board, including the constructor of objects of type Board.
*********************************************************************/

// include the Board header with its class defined and function prototypes
#include "board.hpp"

// constructor for creating a Board object
Board::Board(int r, int c){
   rows = r + 2;
   columns = c + 2;

   // initialize the board's available spaces
   board = new std::string*[rows];
   for(int a=0; a<rows; a++){
      board[a] = new std::string[columns];
      for(int b=0; b<columns; b++){
         board[a][b] = " ";
      }
   }

   // initialize the border's perimeter

   // top & bottom borders
   for(int a=0; a<columns; a++){
      board[0][a] = "-";
      board[(rows-1)][a] = "-";
   }
   // left & right borders
   for(int b=0; b<columns; b++){
      board[b][0] = "|";
      board[b][(columns-1)] = "|";
   }
}

// prints the Board with each tile (within the board) properly reflected with color and the ant's location
void Board::print(){
   for(int r=0; r<rows; r++){
      for(int c=0; c<columns; c++){
         // std::cout << "board[" << r << "][" << c << "] = " << board[r][c] << std::endl;
         std::cout << board[r][c];
      }
      std::cout << std::endl;
   }
}

// free the dynamically allocated memory of the Board object
void Board::freeMemory(){
   for(int r=0; r<rows; r++){
      delete[] board[r];
   }
   delete[] board;
}

// defines the max number of steps that an Ant object can take on the board per game
void Board::setMaxTurns(int numTurns){
   maxTurns = numTurns;
}

// keeps track of the number of steps taken by the Ant
void Board::addTurn(){
   turn += 1;
}

// returns the number of steps taken by the Ant object
int Board::getSteps(){
   return turn;
}

// returns the max number of steps the Ant can take within a particular game
int Board::getMaxSteps(){
   return maxTurns;
}

// updates a tile's color within the Board object
std::string Board::updateTile(){
   if(turn == 1){
      lastTileColor = "#";
   }
   else{
      if(lastTileColor == " "){
         lastTileColor = "#";
      }
      else if(lastTileColor == "#"){
         lastTileColor = " ";
      }
   }
   return lastTileColor;
}

// updates the Board object with the ant's location and the color of its tiles
void Board::updateBoard(int x, int y){
   cout << endl << "Turn # " << getSteps() << endl;
   cout << "xcoord = " << x << " | ycoord = " << y << endl;
   if(turn <= maxTurns){
      if(turn == 0){
         board[y][x] = "*";
         lasty = y;
         lastx = x;
         // lastTileColor = " ";
      }
      else{
         updateTile();
         board[lasty][lastx] = lastTileColor;
         lastTileColor = board[y][x];
         board[y][x] = "*";
         lasty = y;
         lastx = x;
      }
      print();
      addTurn();
   }
   else{
      cout << "Game over..." << endl;
   }
}

// returns the color of the tile that the Ant was last located
std::string Board::getLastTileColor(){
   return lastTileColor;
}

// return the number of columns on the Board
int Board::getColumns(){
   return columns;
}

// return the number of rows on the Board
int Board::getRows(){
   return rows;
}
