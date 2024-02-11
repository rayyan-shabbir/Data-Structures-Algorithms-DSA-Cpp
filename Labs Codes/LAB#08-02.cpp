#include "iostream"
#include "string"
#include "stack"
#include "fstream"
using namespace std;

bool delimetersOk(const string &expression) {
    stack<char> st;

    for(int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        st.push(c);

        if(c == ')' || c == ']') {
            if(st.empty()) return false;

            while(st.top() != '(' && st.top() != '[') {
                st.pop();
            }

            if(c == ')' && st.top() != '(') return false;
            else if(c == ']' && st.top() != '[') return false;

            st.pop();
        }
    }

    while(!st.empty()) {
        if(st.top() == '(' || st.top() == ')' || st.top() == '[' || st.top() == ']') return false;

        st.pop();
    }

    return true;
}


int main() {
    int size = 0;
    string str = {" "};
    ifstream inf("input5.txt", ios::in);

    if(!inf) {
        cout << "File not opened" << endl;
        exit(0);
    }

    inf >> size;


    while(!inf.eof()) {
        inf >> str;

        if(delimetersOk(str)) cout << "Valid" << endl;
        else cout << "InValid" << endl;
    }
    return 0;
}