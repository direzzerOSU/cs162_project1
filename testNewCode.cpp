#include<iostream>
#include<string>

int main(){
   // generate random ints
   srand(time(0));
   // boarder = 10x10 (w/ borders)
   for(int n=0; n<100; n++){
      std::cout << "rand() % 12 = " << (rand() % 10) + 1 << std::endl;
   }
}
