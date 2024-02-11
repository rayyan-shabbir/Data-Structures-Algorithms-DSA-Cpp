#include "iostream"
using namespace std;


int binarySearch(int arr[], int size, int key, int count = 0) {
    int low = 0;
    int high = size-1;

    while(low <= high) {
        count++;
        int mid = low + ((high-low)/2);

        if(key == arr[mid]) 
            // return count;
            return mid;
        else if(key < arr[mid]) 
            high = mid-1;
        else if(key > arr[mid]) 
            low = mid+1;
    }

    cout << "count" << count << endl;
    return -1;
}

int main() {
    int arr[10] = {25, 26, 27, 28, 29, 30, 31, 32, 33, 34};
    //int arr[26] = {44, 122, 132, 203, 228, 311, 318, 323, 341, 412, 431, 496, 513, 520, 592, 767, 796, 800, 806, 835, 861, 865, 889, 919, 953, 996};

    int index = binarySearch(arr, 10, 21);
    cout << "Number presents at Index = " << index << endl;
    return 0;
}