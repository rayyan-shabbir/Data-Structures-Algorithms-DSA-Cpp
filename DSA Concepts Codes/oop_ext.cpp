#include "iostream"
using namespace std;

void subtractByPointer(double* ptrA, double* ptrB, double* ptrR) {
    int z1 = 7;
    double z = (*ptrA) - (*ptrB);
    *ptrR = (*ptrA) - (*ptrB);

    cout << (*ptrR);
    cout << z1;
    
}


int main() {
    double x = 2, y = 8;
    double* ptrA = &x;
    double* ptrB = &y;
    double* ptrR = NULL;

    subtractByPointer(ptrA, ptrB, ptrR);

    return 0;
}