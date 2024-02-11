#include "iostream"
using namespace std;

int rFactorial(int n) {
    if(n <= 0) return 1;

    return rFactorial(n-1) * n;
}


int main() {
    int num = 0;
    cout << "Enter Number: ";
    cin >> num;

    int fact = rFactorial(num);

    cout << "Factorial: " << fact << endl;

    return 0;
}