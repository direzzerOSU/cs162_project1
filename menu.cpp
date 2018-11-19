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
         // initialize board and ant attributes
         int rows;
         int columns;
         int steps;
         int doodlebugs;
         int ants;

         // collect program parameters from the user
         cout << endl << "Please enter the program's parameters: " << endl;

         // board's # of rows
         cout << "   Board's Number of Rows: ";
         cin >> rows;
         cout << endl;
         inputValidation(rows);

         cout << "   Board's Number of Columns: ";
         cin >> columns;
         cout << endl;
         inputValidation(columns);

         cout << "   Total Number of 'Steps': ";
         cin >> steps;
         cout << endl;
         inputValidation(steps);

         cout << "   Total Number of 'Ants': ";
         cin >> ants;
         cout << endl;
         inputValidation(ants);

         cout << "   Total Number of 'Doodlebugs': ";
         cin >> doodlebugs;
         cout << endl;
         inputValidation(doodlebugs);

         // run program

         // initialize the program's major elements (i.e., board, doodlebugs & ants)
         Board board = Board(rows, columns);
         board.setMaxTurns(steps);
         //Ant ant = Ant(rand_x, rand_y, board);

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
