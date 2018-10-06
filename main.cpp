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

// TODO: verify the random coordinate values are correct
// TODO; reopen menu after program completes asking to 'play again' or quit

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

      // input validation
      while(tolower(decision) != 'y' && tolower(decision) != 'n'){
         cout << endl << "Uh oh... That's not a valid option. Please try again." << endl;
         cout << "Selection: ";
         cin >> decision;
      }

      // start the ant in a random location
      if(tolower(decision) == 'y'){
         cout << "Okay! The ant's starting position will be randomized..." << endl;
      }

      int rand_x;
      int rand_y;
      int rows;
      int columns;
      int steps;

      // collect program parameters from the user
      cout << endl << "Please enter the program's parameters: " << endl;
      cout << "   Board's Number of Rows: ";
      cin >> rows;
      cout << "   Board's Number of Columns: ";
      cin >> columns;
      cout << "   Total Number of 'Steps': ";
      cin >> steps;
      cout << endl;

      // // for testing:
      // rows = 5;
      // columns = 5;
      // steps = 5;

      if(tolower(decision) == 'y'){
         // randomize starting position
         srand(time(0));
         // rand_x = (rand() % (columns-2)) + 1;
         rand_x = (rand() % columns) + 1;
         // cout << endl << "rand_x = " << rand_x << endl << endl;
         // rand_y = (rand() % (rows-2)) + 1;
         rand_y = (rand() % rows) + 1;
         // cout << "rand_y = " << rand_y << endl << endl;
      }
      else if(tolower(decision) == 'n'){
         // user input starting position
         cout << "Please enter the ant's starting position..." << endl;
         cout << "What is the starting column?: ";
         cin >> rand_x;
         cout << "What is the starting row?: ";
         cin >> rand_y;
      }

      // run program

      // initialize the program's major elements (i.e., board & ant)
      Board board = Board(rows, columns);
      board.setMaxTurns(steps);
      Ant ant = Ant(rand_x, rand_y, board);

      // have the ant take a step until it has taken the (max) specified amount of steps
      while(board.getSteps() <= board.getMaxSteps()){
         ant.updateLocation();
      }

      // cout << "Freeing memory..." << endl;
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
   cout << endl;

   return 0;
}
