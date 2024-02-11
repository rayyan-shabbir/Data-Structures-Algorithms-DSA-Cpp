#include "iostream"
using namespace std;

int fib(int n) {
    if(n < 2) return n;

    return fib(n-1) + fib(n-2);
}


int main() {
    int num = 0;
    cout << "Enter Num: ";
    cin >> num;

    int fb = fib(num);

    cout << "Fibnaccoi: " << fb << endl;

    return 0;
}