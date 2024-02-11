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

int main() {
    int size = 10;
    int A[10] = {8, 5, 4, 9, 6, 1, 3, 0, 7, 2};

    maxHeapify(A, 1);

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}