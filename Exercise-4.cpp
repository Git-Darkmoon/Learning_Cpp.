/*Find the min and max and average of 15 numbers that a user will input.
**The numbers range from 0 to 100. 
**We will do it now for practice and again later when we learn arrays and 
**functions. So you do not have to keep all fifteen numbers stored in memory.
**HINT: you will need to use scanf for input text.
*/

#include <iostream>
#include <stdexcept>

int main(){

		int max = 0;
		
	for(int i=0;i<=5; i++) {
		
		int current;
		
				
		std::cout << "Enter a number (0-100): ";
		std::cin >> current;
		
		if(current < 0 || current >100) {
			throw std::invalid_argument("Arguments must be in the range (0-100).");
		} 
		
		if (current > max) {
			max = current;
		}

	}
	
	std::cout << "The max number of the numbers entered is: " << max;
	
	
	return 0;
}
