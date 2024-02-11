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


// Min Heapify
void minHeapify(int* A, int index) {
    // left child of index
    int leftChild = (2 * index + 1);

    // right child of index
    int rightChild = (2 * index + 2);

    // Declaring index as largest
    int smallest = index;

    // Comparing with the left child of index
    if(leftChild < curSize && A[smallest] > A[leftChild])
        smallest = leftChild;


    // Comparing with the right child of index
    if(rightChild < curSize && A[smallest] > A[rightChild])
        smallest = rightChild;
    
    // swapping the root
    if(smallest != index) {
        swap(A[smallest], A[index]);

        // recursive call to ensure the heap for the bottom does not disturbed
        minHeapify(A, smallest);
    }
}

int main() {
    int size = 10;
    int A[10] = {0, 9, 1, 6, 7, 8, 3, -1, 5, 10};

    minHeapify(A, 1);

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";

    cout << endl;
    return 0;
}