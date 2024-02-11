#include "iostream"
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size-1;
    while (low <= high) {
        int mid = low + ((high-low)/2);
        if(arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            high = mid-1;
        } else if(key > arr[mid]) {
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {25, 26, 27, 28, 29, 30, 31, 32, 33, 34};

    int index = binarySearch(arr, 10, 26);
    cout << "Number presents at Index = " << index << endl;
    return 0;
}