#include "iostream"
using namespace std;

int power(int x, int n) {
    if(n < 1) return 1;

    return power(x, n-1) * x;
}

int main() {
    int x, n;
    cout << "Enter Base: ";
    cin >> x;
    cout << "Enter Power: ";
    cin >> n;
    
    int result = power(x, n);

    cout << x << "^" << n << " = " << result << endl;
    return 0;
}