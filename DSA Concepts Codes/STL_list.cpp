#include "iostream"
#include "list"
using namespace std;


int main() {
    list<int> li;

    cout << li.empty() << endl;

    li.emplace_front(1);
    li.emplace_back(3);
    li.emplace_back(4);

    cout << li.back() << endl;
    cout << li.empty() << endl;

    li.clear();

    cout << li.empty() << endl;

    return 0;
}