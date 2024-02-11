#include "iostream"
using namespace std;

double power(double x, int n) {
    if(n <= 0) return 1;

    return power(x, n-1) * x;
}

int main() {
    double base;
    int pow;
    cout << "Enter Base: ";
    cin >> base;
    cout << "Enter Power: ";
    cin >> pow;

    double ans = power(base, pow);

    cout << base << "^" << pow << " = " << ans << endl;
    return 0;
}