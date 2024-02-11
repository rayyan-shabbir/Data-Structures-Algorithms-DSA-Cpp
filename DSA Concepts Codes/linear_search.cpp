#include "iostream"
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int arr[8] = {1, 3, 2, 9, 4, 0, 7, 5};

    int index = linearSearch(arr, 8, 9);

    cout << "Number presents at Index = " << index << endl;
    return 0;
}