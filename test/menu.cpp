/*********************************************************************
** Program name: Langton's Ant Rule
** Author: Ryan DiRezze
** Date: October 7, 2018
** Description: Defines and implements the menu function, which is
   used to begin/exit the program and collect program attributes.
*********************************************************************/

// include function header & prototype(s)
#include "menu.hpp"
#include "board.hpp"
#include "ant.hpp"
#include "inputValidation.hpp"

// menu that guides the user through beginning the program (or quitting/exiting), then asks the user
// for all required inputs to begin the program (i.e., board attributes & ant's starting position)
void menu(bool& status){
   // introduction
   string program_name = "Langton's Ant Simulation";
   cout << "Hello! Welcome to Ryan's " << program_name << " Program:" << endl;

   // continue to repeatedly display the menu until the user chooses to exit the program;
   // menu will repeatedly display after completing each game
   while(status == true){
      // user input
      cout << "Please select an option from below:" << endl;
      cout << "   a. Start " << program_name << endl;
      cout << "   b. Quit" << endl << endl;

      // selection is used to determine whether the program is executed or the program exits
      char selection = ' ';
      cout << "Selection: ";
      cin >> selection;

      // input validation
      while(tolower(selection) != 'a' && tolower(selection) != 'b'){
         cout << endl << "Uh oh... That's not a valid option. Please try again." << endl << endl;
         cout << "Selection: ";
         cin >> selection;
      }

      // program selection
      if(tolower(selection) == 'a'){
         // initialize program inputs
         cout << endl << "Would you like the ant to start in a random location?" << endl << endl;
         cout << "Y/N: ";
         char decision;
         cin >> decision;

         // input validation
         while(tolower(decision) != 'y' && tolower(decision) != 'n'){
            cout << endl << "Uh oh... That's not a valid option. Please try again." << endl << endl;
            cout << "Selection: ";
            cin >> decision;
         }

         // start the ant in a random location
         if(tolower(decision) == 'y'){
            cout << endl << "Okay! The ant's starting position will be randomized..." << endl;
         }

         if(tolower(decision) == 'n'){
            cout << endl << "Okay! The ant's starting position will not be randomized..." << endl;
         }

         // initialize board and ant attributes
         int rand_x;
         int rand_y;
         int rows;
         int columns;
         int steps;

         // collect program parameters from the user
         cout << endl << "Please enter the program's parameters: " << endl;

         // board's # of rows
         cout << "   Board's Number of Rows: ";
         cin >> rows;
         cout << endl;
         inputValidation(rows);
         // cout << "rows = " << rows << endl;  // testing

         cout << "   Board's Number of Columns: ";
         cin >> columns;
         cout << endl;
         inputValidation(columns);
         // cout << "columns = " << columns << endl;  // testing

         cout << "   Total Number of 'Steps': ";
         cin >> steps;
         cout << endl;
         inputValidation(steps);
         // cout << "steps = " << steps << endl;   // testing

         // execute if the user chose to randomize the ant's starting location on the board
         if(tolower(decision) == 'y'){
            // update rand()'s seed to generate a new series of random numbers each time the program executes
            srand(time(0));
            rand_x = (rand() % columns) + 1;
            // cout << endl << "rand_x = " << rand_x << endl << endl;
            rand_y = (rand() % rows) + 1;
            // cout << "rand_y = " << rand_y << endl << endl;
         }
         // execute if the user chose to specify the ant's starting location on the board (not randomized)
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

         // restart menu to replay the program
         cout << endl << "Restarting program..." << endl << endl;

         status = true;
      }
      else if(tolower(selection) == 'b'){
         // quit program
         cout << endl << "Exiting program..." << endl;
         // allows the program to exit the loop by changing the value of status (exits the program)
         status = false;
      }
   }
}
