/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description:
*********************************************************************/

#include "ant.hpp"
// #include "ant.cpp"
#include "board.hpp"
// #include "board.cpp"
#include "menu.hpp"
// #include "board.cpp"

// TODO: verify the random coordinate values are correct
// TODO; reopen menu after program completes asking to 'play again' or quit

int main(){
   cout << endl;
   bool status = true;
   while(status != false){
      menu(status);
   }
   cout << endl;

   return 0;
}
