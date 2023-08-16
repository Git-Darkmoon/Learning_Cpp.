#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	int N, i, j, **a;
	
	cout << "Enter the size of the array: ";
	cin >> N;
	
	a = new int *[N];
	
	for(i=0; i<N; i++) 
	{
		a[i] = new int [N];
		
		for(j=0; j<N; j++) 
			a[i][j] = j * i;
		}
		
		for(i=0; i<N; i++) 
		{
			for (j=0; j<N; j++) 
				cout << a[i][j];
			delete a[i];

			}
	delete a[];	
	
	return 0;
}
