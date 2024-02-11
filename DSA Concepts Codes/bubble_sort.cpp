#include "iostream"
using namespace std;

void bubbleSort(int arr[], int size) {
    int temp;
    bool flag = false;

    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                flag = true;
            }
        }
        if(!flag) break;
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    bubbleSort(arr, 10);

    for(int i = 0; i < 10; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    return 0;
}