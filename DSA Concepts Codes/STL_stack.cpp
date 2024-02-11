#include "iostream"
#include "stack"
using namespace std;


int main() {
    stack<int> st;

    // st.pop();   //Program will crash because stack is EMPTY and we are trying to POP ITS TOP.
    // st.top();   //Program will crash because stack is EMPTY and we are trying to GET ITS TOP.

    cout << "SIZE: " << st.size() << endl; //0

    cout << "CHECK EMPTY: " << st.empty() << endl; //1 --> TRUE

    st.push(5);
    cout << "SIZE: " << st.size() << endl; //1

    st.push(8);
    st.push(3);

    cout << "SIZE: " << st.size() << endl; //3

    st.pop();
    cout << "SIZE: " << st.size() << endl; //2

    cout << "TOP: " << st.top() << endl; //8

    cout << "CHECK EMPTY: " << st.empty() << endl; //0 --> FALSE

    cout << endl;
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}