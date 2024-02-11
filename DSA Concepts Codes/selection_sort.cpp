#include "iostream"
using namespace std;

void selectionSort(int arr[], int size) {
    int temp;

    for(int i = 0; i < size-1; i++) {
        int min = i;
        for(int j = i+1; j < size; j++) {
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    selectionSort(arr, 10);

    for(int i = 0; i < 10; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}