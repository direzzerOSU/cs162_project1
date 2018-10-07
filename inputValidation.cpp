#include "inputValidation.hpp"

void inputValidation(int& value){
   while(cin.fail()){
      if(cin.fail()){
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // see the header file for a reference citation (1)
         cout << "You have entered the wrong type of input. \n   Please enter an integer: ";
         cin >> value;
         cout << endl;
      }
   }
}
