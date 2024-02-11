#include "iostream"
using namespace std;

int findKthSmallest (int A[], int n, int k) {
    for(int i = 0; i < n-1; i++) {
        int j = i+1;

        while(j > 0 && A[j] < A[j-1]) {
            swap(A[j], A[j-1]);
            j--;
        }
    }

    if(k >= 1 && k <= n) {
        return A[k-1];
    } else {
        cout << "The kth element does not exist in the array..." << endl;
        exit(0);
    }
}

int main() {
    int A[] = {7, 3, 8, 12, 42, 19, 1, 18, 22, 2, 4, 6};

    int kSmall = findKthSmallest(A, 12, 7);

    for(int i = 0; i < 12; i++) {
        cout << "arr[" << i << "] = " << A[i] << endl;
    }

    cout << "\nThe kth smallest Element is:: " << kSmall << endl;
    return 0;
}