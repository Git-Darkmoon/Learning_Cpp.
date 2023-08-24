#include <cstdlib>
#include <iostream>

using namespace std;

struct nodo {int x,y;
             nodo *sig;};

int main(int argc, char** argv) {
	nodo **arr, *Aux;
	int N, tam, j, i;
	cout<<"Escriba el valor de N ";
	cin>>N;
	cout<<"Escriba el valor de tam ";
	cin>>tam;
	arr= new nodo *[N];
	for(i=0; i<N; i++)
		arr[i]=NULL;
		
		for(i=0; i<N; i++)
    {for(j=1; j<=tam; j++)
	 {Aux=new nodo;
	  Aux->x=j;
	  Aux->y=N+j*i;
	  Aux->sig = arr[i];
	  arr[i]= Aux; }	}
     for(i=0; i<N; i++)
	{Aux = arr[i];
	 cout<<"lista "<<i<<endl;
	 while(Aux!=NULL)
		{cout<<Aux->x<<" "<<Aux->y<<endl;
	 	 Aux=Aux->sig; }
	 for(Aux=arr[i]->sig; Aux!=NULL; Aux=Aux->sig) 
	     {delete arr[i];
		arr[i]=Aux; }
		
    cout << "Tamaño de N: " << sizeof(N) << " bytes" << endl;
    cout << "Tamaño de tam: " << sizeof(tam) << " bytes" << endl;
    cout << "Tamaño de i: " << sizeof(i) << " bytes" << endl;
    cout << "Tamaño de j: " << sizeof(j) << " bytes" << endl;
    cout << "Tamaño de Aux: " << sizeof(Aux) << " bytes" << endl;
    cout << "Tamaño del puntero arr: " << sizeof(arr) << " bytes" << endl;
    cout << "Tamaño de nodo: " << sizeof(nodo) << " bytes" << endl;
           
    cout << "\nMemoria usada: " << sizeof(N) + sizeof(tam) + sizeof(i) + sizeof(j) + sizeof(Aux) + sizeof(arr) + sizeof(nodo);
           	
		 delete arr[i];
		}
	delete []arr;
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

