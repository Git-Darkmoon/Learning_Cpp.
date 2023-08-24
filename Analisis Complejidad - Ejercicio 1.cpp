#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	int N, i, j , *a;
	
	cout << "Enter the size: ";
	cin >> N;
	
	for (i=0; i < N; i++) {
		a = new int [N];
		
		for(j=0; j<N; j++) {
			a[j] = j*i;
			cout << a[j] << " ";
		}
		delete []a;
		cout << endl;
	}
	
	cout << "Tamaño de N: " << sizeof(N) << " bytes" << endl;
    cout << "Tamaño de i: " << sizeof(i) << " bytes" << endl;
    cout << "Tamaño de j: " << sizeof(j) << " bytes" << endl;
    cout << "Tamaño de int apuntado por a: " << sizeof(*a) << " bytes" << endl;
    cout << "Tamaño del puntero a: " << sizeof(a) << " bytes" << endl;
    
    cout << "\nMemoria usada: " << sizeof(N) + sizeof(i) + sizeof(j) + sizeof(*a) + sizeof(a) << " bytes.";
	
	return 0;
}


