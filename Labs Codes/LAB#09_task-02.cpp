#include "iostream"
using namespace std;

int arraySum(int A[], int n) {
    if(n == 0) return A[n];

    return arraySum(A, n-1) + A[n];
}

int rArraySum(int A[], int size) {
    int sum = arraySum(A, size-1);

    return sum;
}


int main() {
    int A[] = {5, 5, 3, 2, 17};

    int sum = rArraySum(A, 5);

    cout << "Sum: "  << sum << endl;
    return 0;
}