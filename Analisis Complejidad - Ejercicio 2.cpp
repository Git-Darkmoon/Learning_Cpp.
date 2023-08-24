#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	// n^2 + n + 4
	
	int N, i, j, **a;
	
	cout << "Enter the size of the array: ";
	cin >> N;
	
	a = new int *[N];
		
	int memoryLoad = sizeof(N) + sizeof(i) + sizeof(j) + sizeof(a);
	
	for(i=0; i<N; i++) 
	{
		a[i] = new int [N];
			
		memoryLoad += sizeof(*a);
		
		for(j=0; j<N; j++) 
			a[i][j] = j * i;
			
			memoryLoad += sizeof(**a);
	}
		
	for(i=0; i<N; i++) 
	{
		for (j=0; j<N; j++) 
			cout << a[i][j];
		delete a[i];

	}
	delete []a;	
	
	cout << "\nTotal sizeof: " << memoryLoad << endl;
	
	return 0;
}
