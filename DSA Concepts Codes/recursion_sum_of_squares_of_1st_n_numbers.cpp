#include "iostream"
using namespace std;

int sumSquare(int n) {
    if(n == 1) return 1;

    return sumSquare(n-1) + (n*n);
}

int main() {
    int num;
    cout << "Enter Number: ";
    cin >> num;

    int sq = sumSquare(num);

    cout << "Answer: " << sq << endl;

    return 0;
}