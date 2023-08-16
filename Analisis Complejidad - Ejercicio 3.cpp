#include <iostream>
using namespace std;

int main(int argc, char** argv) {

struct nodo { int x,y;
nodo *sig;
};

int N, i, j;
	nodo *cab = NULL, *Aux;

int memoryLoad = 0;
	
	cout << "Enter the N value: ";
	cin >> N;
	
	for(i=0; i<N; i++)
	{
	Aux = new nodo;
	Aux->x = i;
	Aux->y = N - i;
	Aux->sig = cab;
	cab = Aux;
	
	memoryLoad += sizeof(nodo) + sizeof(i) + sizeof(N);
	
	}
	
	

	Aux = cab;
	while (Aux != NULL)
	{
		cout << Aux->x<< Aux->y<<endl;
		Aux=Aux->sig;

	}
	
	for(Aux=cab->sig; Aux!=NULL; Aux=Aux->sig)
	{
		delete cab;
		cab = Aux;
		
		memoryLoad += sizeof(cab);
	}

cout << "Memory used: " << memoryLoad << " bytes.";

return 0;
}
