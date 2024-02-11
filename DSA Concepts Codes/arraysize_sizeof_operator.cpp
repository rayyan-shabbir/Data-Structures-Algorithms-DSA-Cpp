#include "iostream"
using namespace std;


int main() {
    int ar[] = {1, 2, 34, 6, 7, 5, 8, 3, 33, 6, 33, 33, 66, 336, 24, 2, 22, 332, 34, 567, 44, 4, 12, 1};

    int size1 = (sizeof(ar) / sizeof(ar[0]));
    // OR
    int size2 = (sizeof(ar) / sizeof(int));

    cout << "Array size = " << size1 << endl;
    cout << "Array size = " << size2 << endl;
    return 0;
}