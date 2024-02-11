#include "iostream"
using namespace std;

void insertionSort(int arr[], int size) {
    for(int i = 0; i < size-1; i++) {
        int j = i+1;
        while(j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            
            j--;
        }
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    //int A[] = {7, 3, 8, 12, 42, 19, 1, 18, 22, 2, 4, 6};
    
    insertionSort(arr, 10);

    for(int i = 0; i < 10; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}