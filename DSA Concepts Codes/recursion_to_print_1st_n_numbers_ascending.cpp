#include "iostream"
using namespace std;

void rPrint(int n) {
    if(n > 0) rPrint(n-1);

    cout << n << " ";
}


int main() {
    int num = 0;
    cout << "Enter Number: ";
    cin >> num;

    rPrint(num);
    return 0;
}