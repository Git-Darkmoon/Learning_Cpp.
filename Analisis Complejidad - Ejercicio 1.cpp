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
	
	cout << "Tama�o de N: " << sizeof(N) << " bytes" << endl;
    cout << "Tama�o de i: " << sizeof(i) << " bytes" << endl;
    cout << "Tama�o de j: " << sizeof(j) << " bytes" << endl;
    cout << "Tama�o de int apuntado por a: " << sizeof(*a) << " bytes" << endl;
    cout << "Tama�o del puntero a: " << sizeof(a) << " bytes" << endl;
    
    cout << "\nMemoria usada: " << sizeof(N) + sizeof(i) + sizeof(j) + sizeof(*a) + sizeof(a) << " bytes.";
	
	return 0;
}


