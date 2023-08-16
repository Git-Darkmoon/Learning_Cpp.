#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	int i[5],iter , *p;
	float j, *q;
	
	for(iter = 0; iter <5;iter++)
		i[iter] = iter + 1;
	
	p = i;
	
	
//	 Los apuntadores ocupan 8 bytes.
	
	for(iter = 0;iter <5;iter++)
		cout << p[iter] << " ";
	
//	cout << sizeof(*p); // sizeof ---> tamanho de bytes.

	return 0;
}
