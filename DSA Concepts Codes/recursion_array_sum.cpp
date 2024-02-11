#include "iostream"
using namespace std;

int rSum(int A[], int n) {
    if(n == 0) return A[n];

    return rSum(A, n-1) + A[n];
}

int arraySum(int A[], int size) {
    if(size <= 0) exit(0);

    int sum = rSum(A, size-1);

    return sum;
}


int main() {
    int A[] = {6, 3, 8, 1, 4};

    int sum = arraySum(A, 5);

    cout << "Sum of array: "  << sum << endl;
    return 0;
}