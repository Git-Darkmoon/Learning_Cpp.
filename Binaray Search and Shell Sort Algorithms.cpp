#include <iostream>

#include <stdio.h>
#include <time.h>

#include <fstream>
using namespace std;

// Metodo para llenar el array de menor a mayor.
void fillArrayAscending(int arr[], int size) {
	
	for (int i = 1; i <= size; i++) {
		arr[i - 1] = i;
	}
}

// Metodo para llenar el array de mayor a menor.
void fillArrayDescending(int arr[], int size) {
	
    int value = size;
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
        value--;
    }
}

// Metodo de Busqueda binaria
// Para este algoritmo, el array debe estar ordenado.
int binarySearch(int arr[], int size, int target) {
    int startIndex = 0;
    int endIndex = size - 1;

    while (startIndex <= endIndex) {
        int mid = startIndex + (endIndex - startIndex) / 2;

        if (arr[mid] == target) {
            return mid; // Elemento encontrado, retorna su índice
        } else if (arr[mid] < target) {
            startIndex = mid + 1; // Busca en la mitad derecha
        } else {
            endIndex = mid - 1; // Busca en la mitad izquierda
        }
    }

    return -1; // Elemento no encontrado
}

// Metodo de Orden Shell
void shellSort(int a[], int N) {
    int h, i, j, v;
    
    for (h = 1; h <= N / 9; h = 3 * h + 1)
        ;
    for (; h > 0; h /= 3) {
        for (i = h; i < N; i++) {
            v = a[i];
            j = i;
            while (j >= h && a[j - h] > v) {
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = v;
        }
    }
}

int main() {
	// Abre el archivo para escribir en el. (el nombre del archivo se cambia a gusto)
	// USUALMENTE, el archivo .csv va a crearse en el mismo path donde esta este archivo .cpp
    ofstream outFile("complex_times_worstCase.csv"); 

    if (!outFile.is_open()) {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    outFile << "Array Size,Time (nanos)" << endl; // CSV header

    for (int size = 50; size <= 10000; size += 50) {
        int arr[size];
        fillArrayDescending(arr, size);

        int target = 1;

        struct timespec start, end;

        clock_gettime(CLOCK_MONOTONIC, &start);

//        int result = binarySearch(arr, size, target);
		shellSort(arr,size);

        clock_gettime(CLOCK_MONOTONIC, &end);

        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;
        long total_nanoseconds = seconds * 1000000000 + nanoseconds;

        outFile << size << "," << total_nanoseconds << endl;
    }

    outFile.close();

    return 0;
}

