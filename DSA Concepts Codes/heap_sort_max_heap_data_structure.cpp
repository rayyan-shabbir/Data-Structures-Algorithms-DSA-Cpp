#include "iostream"
using namespace std;

static int curSize = 10;

// left child of index
int leftChild(int index) {
    return (2 * index + 1);
}

// right child of index
int rightChild(int index) {
    return (2 * index + 2);
}

// parent of index
int parent(int index) {
    return (index - 1)/2;
}

// Max Heapify
void maxHeapify(int* A, int index) {
    // left child of index
    int leftChild = (2 * index + 1);

    // right child of index
    int rightChild = (2 * index + 2);

    // Declaring index as largest
    int largest = index;

    // Comparing with the left child of index
    if(leftChild < curSize && A[largest] < A[leftChild])
        largest = leftChild;


    // Comparing with the right child of index
    if(rightChild < curSize && A[largest] < A[rightChild])
        largest = rightChild;
    
    // swapping the root
    if(largest != index) {
        swap(A[largest], A[index]);

        // recursive call to ensure the heap for the bottom does not disturbed
        maxHeapify(A, largest);
    }
}

// Building Max Heap for array A Using Heapify Procedure
void buildingMaxHeap(int* A) {
    for(int i = (curSize/2 - 1); i >= 0; i--) {
        maxHeapify(A, i);
    }
}

// Heap Sort
void heapSort(int* A) {
    for(int i = (curSize - 1); i >= 0; i--) {
        swap(A[i], A[0]);

        curSize--;

        maxHeapify(A, 0);
    }
}

int main() {
    int size = 10;
    int A[10] = {2, 4, 3, 7, 6, 1, 5, 0, 9, 8};

    buildingMaxHeap(A);

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";

    cout << endl;

    heapSort(A);

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}