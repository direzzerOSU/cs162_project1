// include function header & prototype(s)
#include "menu.hpp"
#include "board.hpp"
#include "ant.hpp"
#include "inputValidation.hpp"

void menu(bool& status){
   // introduction
   string program_name = "Langton's Ant Simulation";
   cout << "Hello! Welcome to Ryan's " << program_name << " Program:" << endl;

   // bool status = true;

   while(status == true){
      // user input
      cout << "Please select an option from below:" << endl;
      cout << "   a. Start " << program_name << endl;
      cout << "   b. Quit" << endl << endl;
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

         if(tolower(decision) == 'y'){
            // randomize starting position
            srand(time(0));
            rand_x = (rand() % columns) + 1;
            // cout << endl << "rand_x = " << rand_x << endl << endl;
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

         // restart menu to replay the program
         cout << endl << "Restarting program..." << endl << endl;

         status = true;
      }
      else if(tolower(selection) == 'b'){
         // quit program
         cout << endl << "Exiting program..." << endl;
         status = false;
      }
   }
}
