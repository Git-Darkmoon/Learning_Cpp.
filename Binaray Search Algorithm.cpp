#include <iostream>
using namespace std;

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

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]); // Calcula el tamanho del array
    int target = 9;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "The element " << target << " was found at index: " << result << endl;
    } else {
        cout << "The element " << target << " it's not in the array." << endl;
    }

    return 0;
}

