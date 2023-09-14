#include <iostream>

#include <stdio.h>
#include <time.h>

#include <fstream>
using namespace std;

// Metodo para llenar el array.
void fillArray(int arr[], int size) {
	
    int value = size;
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
        value--;
    }
}

// Metodo de intercambio de valores (usado en quickSort):
void intercambio(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Algoritmo quickSort
void quickSort(int a[], int izq, int der) {
    int i, j;
    int v;
    
    if (der > izq) {
        v = a[der];
        i = izq - 1;
        j = der;
        
        for (;;) {
            while (a[++i] < v);
            while (a[--j] > v);
            if (i >= j) break;
            intercambio(a, i, j);
        }
        
        intercambio(a, i, der);
        quickSort(a, izq, i - 1);
        quickSort(a, i + 1, der);
    }
}

// Metodo para obtener el valor del bit en una posición específica (usado en cambio de residuos).
bool obtenerBit(int num, int posicion) {
    return (num >> posicion) & 1;
}


// Función para realizar el cambio de residuos
void cambioDeResiduos(int a[], int izq, int der, int b) {
    int i, j, t;
    if (der > izq && b > 0) {
        i = izq;
        j = der;
        while (j != i) {
            while (!obtenerBit(a[i], b) && i < j) {
                i++;
            }
            while (obtenerBit(a[j], b) && j > i) {
                j--;
            }
            swap(a[i], a[j]);
        }
        if (!obtenerBit(a[i], b)) {
            j++;
        }
        cambioDeResiduos(a, izq, j - 1, b - 1);
        cambioDeResiduos(a, j, der, b - 1);
    }
}

int main() {
    // Abre el archivo para escribir en el. (el nombre del archivo se cambia a gusto)
    // USUALMENTE, el archivo .csv va a crearse en el mismo path donde esta este archivo .cpp
    ofstream outFile("complex_times_cambioResiduos.csv");

    if (!outFile.is_open()) {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    outFile << "Array Size,Time (nanos)" << endl; // CSV header

    for (int size = 50; size <= 1000; size += 50) {
        int arr[size];
        fillArray(arr, size);

        int target = 1;

        struct timespec start, end;

        clock_gettime(CLOCK_MONOTONIC, &start);

//        quickSort(arr, 0, size - 1);
        cambioDeResiduos(arr, 0, size - 1, 31); // Se toma 31 para indicar que se tendran en cuenta los 32 bits del entero.

        clock_gettime(CLOCK_MONOTONIC, &end);

        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;
        long total_nanoseconds = seconds * 1000000000 + nanoseconds;

        outFile << size << "," << total_nanoseconds << endl;
    }

    outFile.close();
    

    return 0;
}


