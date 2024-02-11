#include "iostream"
using namespace std;

int rLinearSearch(int A[], int n, int key) {
    if(n < 0) return -1;
    if(A[n] == key) return n;

    return rLinearSearch(A, n-1, key);
}

bool elmRet(int A[], int start, int end, int k) {
    if(start == end) return false;

    int diff = k - A[end];

    int index = rLinearSearch(A, end-1, diff);

    if(index != -1) return true;
    return elmRet(A, start, end-1, k);
}

int main() {
    int A[] = {8, 5, 4, 3, 9};

    if(elmRet(A, 0, 4, 14)) cout << "Exists" << endl;
    else  cout << "Not Exists" << endl;

    return 0;
}