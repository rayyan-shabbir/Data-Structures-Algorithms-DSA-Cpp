#include "iostream"
using namespace std;

int isPrime(int n) {
    if(n == 1) {
        return 0;   //'1' is not a prime number 
    }

    for(int i = 2; i*i < n; i++) {
        if(n % i == 0) return 0;
    }

    return 1;
}


int main() {
    int i = isPrime(1);
    cout << i;
    return 0;
}