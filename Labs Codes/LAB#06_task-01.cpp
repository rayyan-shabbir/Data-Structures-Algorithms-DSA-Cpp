#include "iostream"
using namespace std;

// int intersection1 (int A[], int B[], int C[], int n)
// {
//     for(int i = 0; i < n-1; i++) {
//         int j = i+1;
//         while(j > 0 && A[j] < A[j-1]) {
//             swap(A[j], A[j-1]);
//             j--;
//         }
//     }

//     for(int i = 0; i < n-1; i++) {
//         int min = i;
//         for(int j = i+1; j < n; j++) {
//             if(B[min] > B[j]) min = j;
//         }
//         swap(B[i], B[min]);
//     }

//     int k = 0;
//     int r = 0;
//     int count = 0;

//     while(k < n && r < n) {
//         if(A[k] == B[r]) {
//             C[count] = A[k];
//             count++;
//             k++;
//             r++;
//         } else if (A[k] < B[r]) k++;
//         else if (A[k] > B[r]) r++;
//     }

//     return count;
// }


int intersection1 (int A[], int B[], int C[], int n)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while(i < n && j < n) {
        if(A[i] == B[j]) {
            C[count] = A[i];
            count++;
            i++;
            j++;
        } else if(A[i] < B[j]) {
            i++;
        } else if(A[i] > B[j]) {
            j++;
        }
    }
    return count;
}


int main() {
//     int A[] = {0, 1, 2, 5, 6, 9, 11, 13};
//     int B[] = {0, 2, 3, 4, 7, 8, 9, 10};

    // int A[] = {7, 3, 8, 12, 100, 19, 1, 18, 22, 2, 4, 6};
    // int B[] = {-2, -1, 4, 12, 97, 11, -100, 18, 23, 5, -8, -6};
    int C[12];

    int c = intersection1(A, B, C, 12);

    // for(int i = 0; i < 12; i++) {
    //     cout << "arr[" << i << "] = " << A[i] << endl;
    // }

    //cout << endl << endl;

    // for(int i = 0; i < 12; i++) {
    //     cout << "arr[" << i << "] = " << B[i] << endl;
    // }

    cout << c << endl;
    return 0;
}