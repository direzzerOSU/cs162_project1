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

// using std::string;
// using std::cout;
// using std::cin;
// using std::endl;

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

      if(tolower(decision) == 'y'){
         cout << "Okay! The ant's starting position will be randomized..." << endl;
         cout << endl << "Please enter the program's parameters: " << endl;
         cout << "   Board's Number of Rows: ";
         int rows;
         // cin >> rows;
         cout << "   Board's Number of Columns: ";
         int columns;
         // cin >> columns;
         cout << "   Total Number of 'Steps': ";
         int steps;
         // cin >> steps;

         // for testing:
         rows = 5;
         columns = 5;
         steps = 5;
         cout << endl;

         // randomize starting position
         srand(time(0));
         // int rand_x = (rand() % (columns-2)) + 1;
         int rand_x = 3;
         cout << endl << "rand_x = " << rand_x << endl << endl;
         int rand_y = 3;
         // int rand_y = (rand() % (rows-2)) + 1;
         cout << "rand_y = " << rand_y << endl << endl;

         // run program
         Board board = Board(rows, columns);
         Ant ant = Ant(rand_x, rand_y, board);
         cout << endl << "Ant initialized..." << endl << endl;

         cout << "Updating location..." << endl;
         ant.updateLocation();

         cout << "Freeing memory..." << endl;
         board.freeMemory();
      }
   }
   else if(tolower(selection) == 'b'){
      // quit program
      cout << "Exiting program..." << endl;
   }
}

int main(){
   menu();

   return 0;
}
