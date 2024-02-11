#include "iostream"
#include "stack"
#include "fstream"
using namespace std;


bool delimetersOk(const string &expression) {
    stack<char> st;

    for(int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if(c == '(' || c == '[') st.push(c);
        else if(c == ']' || c == ')') {
            if(st.empty()) return false;

            if(c == ')' && st.top() != '(') return false;
            else if(c == ']' && st.top() != '[') return false;

            st.pop();
        }
    }

    if(!st.empty()) return false;

    return true;
}

int main() {
    string str = {" "};
    ifstream inf("input5.txt", ios::in);

    if(!inf) {
        cout << "File not opened" << endl;
        exit(0);
    }

    while(!inf.eof()) {
        inf >> str;

        if(delimetersOk(str)) cout << "Valid"  << endl;
        else cout << "InValid" << endl;
    }

    return 0;
}