#include "iostream"
using namespace std;

// void reverseSubArray(int A[], int start, int end) {
//     if(start != end) {
//         swap(A[start], A[end]);

//         reverseSubArray(A, start+1, end-1);
//     }

// }

void reverseSubArray(int A[], int start, int end) {
    swap(A[start], A[end]);

    if(start < end) reverseSubArray(A, start+1, end-1); 
}

int main() {
    int A[] = {1, 2, 3, 4, 5};

    reverseSubArray(A, 1, 3);

    for(int i = 0; i < 5; i++)
        cout << A[i] << " ";

    return 0;
}