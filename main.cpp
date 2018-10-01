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

// funtion protoype(s)
void menu();

void menu(){
   // introduction
   string program_name = "Langton's Ant Simulation";
   cout << "Hello! Welcome to Ryan's " << program_name << " program:" << endl;

   // user input
   cout << "Please select an option from below:" << endl;
   cout << "   a. Start " << program_name << endl;
   cout << "   b. Quit" << endl << endl;
   char selection = ' ';
   cout << "Selection: ";
   cin >> selection;

   // input validation
   while(tolower(selection) != 'a' && tolower(selection) != 'b'){
      cout << endl << "Uh oh... That's not a valid option. Please try again." << endl;
      cout << "Selection: ";
      cin >> selection;
   }

   // program selection
   if(tolower(selection) == 'a'){
      // initialize program inputs
      cout << "Would you like the ant to start in a random location?" << endl;
      cout << "Y/N: ";
      char decision;
      cin >> decision;
      int rand_x;
      int rand_y;
      int rows;
      int columns;
      int steps;

      // for testing:
      rows = 5;
      columns = 5;
      steps = 100;

      if(tolower(decision) == 'y'){
         cout << "Okay! The ant's starting position will be randomized..." << endl;
         cout << endl << "Please enter the program's parameters: " << endl;
         cout << "   Board's Number of Rows: ";
         // cin >> rows;
         cout << "   Board's Number of Columns: ";
         // cin >> columns;
         cout << "   Total Number of 'Steps': ";
         // cin >> steps;

         cout << endl;

         // randomize starting position
         srand(time(0));
         rand_x = (rand() % (columns-2)) + 1;
         // int rand_x;
         cout << endl << "rand_x = " << rand_x << endl << endl;
         // int rand_y;
         rand_y = (rand() % (rows-2)) + 1;
         cout << "rand_y = " << rand_y << endl << endl;
      }
      else if(tolower(decision) == 'n'){
         // user input starting position
         cout << "Please enter the ant's starting position..." << endl;
         cout << "What is the x coordinate?: ";
         cin >> rand_x;
         cout << "What is the y coordinate?: ";
         cin >> rand_y;
         cout << endl << "rand_x = " << rand_x << endl << endl;
         cout << "rand_y = " << rand_y << endl << endl;
      }
      // run program
      Board board = Board(rows, columns);
      board.setMaxTurns(steps);
      Ant ant = Ant(rand_x, rand_y, board);
      cout << endl << "Ant initialized..." << endl << endl;

      cout << "Updating location..." << endl;
      while(board.getSteps() < board.getMaxSteps()){
         ant.updateLocation();
         // cout << "step # from main() = " << board.getSteps() << endl;
      }
      cout << "Freeing memory..." << endl;
      board.freeMemory();
   }
   else if(tolower(selection) == 'b'){
      // quit program
      cout << "Exiting program..." << endl;
   }
}

int main(){
   cout << endl;
   menu();

   return 0;
}
