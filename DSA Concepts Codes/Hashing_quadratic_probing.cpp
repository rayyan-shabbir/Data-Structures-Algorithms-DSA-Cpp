#include "iostream"
#include "cmath"
using namespace std;

int reHash(int A[], int size, int hashCode, int val) {
    int re = hashCode;
    int i = 0;

    while(A[re] != 0 && i < size) {
        int r = pow(i, 2);
        re = (hashCode + r) % size;

        i++;
    }

    if(A[re] == 0) A[re] = val;
    
    return re;
}

int hashFunction(int A[], int size, int val) {
    return val % size;
}

void insert(int A[], int size, int val) {
    int i = 0;
    int code = hashFunction(A, size, val);

    if(A[code] != 0) reHash(A, size, code, val);

    if(A[code] == 0) A[code] = val;
}

void searching(int A[], int size, int val) {
    int index = (val % size);

    if(A[index] == val) cout << "Element exists" << endl;
    else cout << "Element does not exists" << endl;
}

int main() {
    int size = 10;
    int A[10] = {};

    insert(A, size, 3);
    insert(A, size, 2);
    insert(A, size, 9);
    insert(A, size, 6);
    insert(A, size, 11);
    insert(A, size, 13);
    insert(A, size, 7);
    insert(A, size, 12);

    cout << endl << "Array : ";
    for(int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }

    return 0;
}