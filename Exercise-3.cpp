// First Pointers exercise:

/*For this program print for each variable
**print the value of the variable, 
**then print the address where it is stored. 
*/
#include<iostream>
#include<string>



int main()
{
    int givenInt = 1;
    int * intPointer = &givenInt;
       
    float givenFloat = .3;
    float * floatPointer = &givenFloat;
	
	double givenDouble = 22.3;
	double * doublePointer = &givenDouble;
	
//    std::string givenString = 'world';
    char givenChar = 'F';

    
   std::cout << "The ADDRESS of this variable is: " << intPointer << '\n';
   std::cout << "The value stored for this variable is: " << * intPointer  << '\n\n';
   
      std::cout << "The ADDRESS of this variable is: " << floatPointer << '\n';
   std::cout << "The value stored for this variable is: " << * floatPointer  << '\n\n';
   
      std::cout << "The ADDRESS of this variable is: " << doublePointer << '\n';
   std::cout << "The value stored for this variable is: " << * doublePointer  << '\n\n';
    
    return 0;
}
