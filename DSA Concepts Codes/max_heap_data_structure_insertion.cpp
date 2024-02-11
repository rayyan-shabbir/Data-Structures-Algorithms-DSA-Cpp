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

// Insertion in Max Heap
void insertionMaxHeap(int A[], int arrSize, int val) {
    // Bound Checking (if Array is full or not)
    if(curSize < arrSize) {
        // Inserting new item
        A[curSize] = val;

        // index of new item
        int newPos = curSize;

        // increment the curSize to keep count of values
        curSize++;

        // until index reaches to 0 and new child is smaller than from its parent
        while(newPos != 0 && A[(newPos - 1)/2] < A[newPos]) {
            // swap child with its parent. The child bubbled up
            swap(A[newPos], A[(newPos - 1)/2]);

            // Note the new index of bubbled up item
            newPos = (newPos - 1) / 2;
        }
    }
}

int main() {
    int arrSize = 10;
    int* A = new int[arrSize];

    insertionMaxHeap(A, arrSize, 6);
    insertionMaxHeap(A, arrSize, 8);
    insertionMaxHeap(A, arrSize, 1);
    insertionMaxHeap(A, arrSize, 4);
    insertionMaxHeap(A, arrSize, 7);
    insertionMaxHeap(A, arrSize, 3);
    insertionMaxHeap(A, arrSize, 5);
    insertionMaxHeap(A, arrSize, 0);
    insertionMaxHeap(A, arrSize, 9);
    insertionMaxHeap(A, arrSize, 2);

    cout << "Array: ";
    for(int i = 0; i < arrSize; i++)
        cout << A[i] << " ";
    
    cout << endl;

    return 0;
}