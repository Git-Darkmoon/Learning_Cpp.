#include <iostream>
#include <chrono>       // for measure time.

using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void fillArrayBestCase(int arr[], int size) {
	
	for (int i = 1; i <= size; i++) {
		arr[i - 1] = i;
	}
	
}

void fillArrayWorstCase(int arr[], int size) {
	
    int value = size;
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
        value--;
    }
	
}

int main() {
    int arraySize; // Change this to the desired array size : N

	for (arraySize = 10; arraySize <= 1000; arraySize += 10) {
	
	    int myArray[arraySize];
	    
	    // fillArrayBestCase llena el array con el mejor caso y fillArrayWorstCase con el peor caso.
	    
		  fillArrayBestCase(myArray, arraySize);
//		fillArrayWorstCase(myArray,arraySize);	
	    
	    cout << " ---> arraySize:N = " << arraySize << endl;
	    
	    cout << "Original array: ";
	    for (int num : myArray) {
	        cout << num << " ";
	    }
	    
	    auto start = chrono::high_resolution_clock::now();
	    
	    insertionSort(myArray, arraySize);
	    
	    auto end = chrono::high_resolution_clock::now();
	    
	    
	    cout << "\n\nSorted array: ";
	    for (int element : myArray) {
	        cout << element << " ";
	    }
	    
         cout << "\t\t --> Time sorting the array: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;
	    
	    cout << "\n\n\n";
    
	}
    return 0;
}

