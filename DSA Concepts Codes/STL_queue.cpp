#include "iostream"
#include "queue"
using namespace std;


int main() {
    queue<int> qu;

    // qu.pop();   //Program will crash because queue is EMPTY and we are trying to POP FROM ITS FRONT.
    // qu.front();   //Program will crash because queue is EMPTY and we are trying to GET ITS FRONT.
    // qu.back();   //Program will crash because queue is EMPTY and we are trying to GET ITS BACK.

    qu.push(1);
    qu.push(2);
    qu.push(3);

    cout << "FRONT: " << qu.front() << endl;
    cout << "BACK: " << qu.back() << endl;

    qu.pop();

    cout << "FRONT: " << qu.front() << endl;
    cout << "BACK: " << qu.back() << endl;

    return 0;
}