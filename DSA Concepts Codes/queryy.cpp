#include "iostream"
using namespace std;


int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr << endl;
    cout << &arr[0] << endl;
    cout << &arr << endl;

    int *ptr = &arr[0];
    cout << *ptr << endl;
    cout << ptr << endl;
    cout << &ptr << endl;
    return 0;
}