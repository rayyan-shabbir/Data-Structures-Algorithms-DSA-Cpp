#include "iostream"
using namespace std;

// Declaring curSize of Array globally
static int curSize = 0;

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

// Insertion in Min Heap
void insertionMinHeap(int A[], int arrSize, int val) {
    // Bound Checking (if Array is full or not)
    if(curSize < arrSize) {
        // Inserting new item
        A[curSize] = val;

        // index of new item
        int newPos = curSize;

        // increment the curSize to keep count of values
        curSize++;

        // until index reaches to 0 and new child is greater than from its parent
        while(newPos != 0 && A[(newPos - 1)/2] > A[newPos]) {
            // swap child with its parent. The child bubbled up
            swap(A[newPos], A[(newPos - 1)/2]);

            // Note the new index of bubbled up item
            newPos = (newPos - 1) / 2;
        }
    }
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

// Building Min Heap for array A Using Heapify Procedure
void buildingMinHeap(int* A) {
    for(int i = (curSize/2 - 1); i >= 0; i--) {
        minHeapify(A, i);
    }
}

// Min Priority Queue (deletion of root value)
int getMin(int* A) {
    int min = A[0];

    A[0] = A[curSize - 1];

    curSize--;

    minHeapify(A, 0);

    return min;
}

// Heap Sort
void heapSort(int* A) {
    for(int i = (curSize - 1); i >= 0; i--) {
        swap(A[i], A[0]);

        curSize--;

        minHeapify(A, 0);
    }
}

int main() {
    int arrSize = 10;
    int* A = new int[arrSize];

    insertionMinHeap(A, arrSize, 6);
    insertionMinHeap(A, arrSize, 8);
    insertionMinHeap(A, arrSize, 1);
    insertionMinHeap(A, arrSize, 4);
    insertionMinHeap(A, arrSize, 7);
    insertionMinHeap(A, arrSize, 3);
    insertionMinHeap(A, arrSize, 5);
    insertionMinHeap(A, arrSize, 0);
    insertionMinHeap(A, arrSize, 9);
    insertionMinHeap(A, arrSize, 2);

    cout << "Array: ";
    for(int i = 0; i < arrSize; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
}