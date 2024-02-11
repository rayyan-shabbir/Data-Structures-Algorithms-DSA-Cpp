#include "iostream"
using namespace std;

int rSum(int n) {
    if(n == 1) return 1;

    return rSum(n-1) + n;
}


int main() {
    int num;
    cout << "Enter Number: ";
    cin >> num;

    int sum = rSum(num);

    cout << "Sum: " << sum << endl;

    return 0;
}