#include "iostream"
using namespace std;

void subtractByPointer(double* ptrA, double* ptrB, double* ptrR) {
    int z1 = 7;
    double z = (*ptrA) - (*ptrB);
    ptrR = &z;

    cout << (*ptrR) << endl;
    // cout << z;
    
}

void arrayByPointer(float* ptrArray, int size) {
    for(int i = 0; i < size; i++) {
        cout << *(ptrArray+i) << endl;
        cout << "MEMORY ADRESS" << endl;
        cout << (ptrArray+i) << endl;
    }
}

void getMinMax(int* ptrArray, int size, int* ptrMin, int* ptrMax) {
    int min = *(ptrArray+0);
    int max = *(ptrArray+0);

    for (int i = 1; i < size; i++)
    {
        if(ptrArray[i] < min) min = ptrArray[i];
        if(ptrArray[i] > max) max = ptrArray[i];
    }
    

    *ptrMin = min;
    *ptrMax = max;

    cout << min << endl;
    cout << max << endl;
}


int main() {
    cout << "Rayan" << endl;

    int x = 2, y = 8;
    // double* ptrA = &x;
    // double* ptrB = &y;
    // double* ptrR = NULL;

    // subtractByPointer(ptrA, ptrB, ptrR);

    int arr[10] = {4, 9, 10, 7, 8, 2, 3, 1, 5, 6};

    // arrayByPointer(arr, 10);
    int* ptrS = &x;
    int* ptrL = &y;
    getMinMax(arr, 10, ptrS, ptrL);

    cout << *(ptrS) << endl;
    cout << *(ptrL) << endl;

    return 0;
}