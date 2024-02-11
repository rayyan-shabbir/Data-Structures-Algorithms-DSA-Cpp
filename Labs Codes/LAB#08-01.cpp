#include "iostream"
#include "fstream"
#include "stack"
#include "queue"
using namespace std;

bool delimetersOk(const string &expressions) {

    //cout << expressions << endl;

    stack<char> st;

    for(int i = 0; i < expressions.length(); i++) {
        char c = expressions[i];

        if(c == '(' || c == '[') st.push(c);
        else if(c == ')' || c == ']')
        {
            if(st.empty())
                return false;
            if(c == ')' && st.top() != '(') return false;
            else if(c == ']' && st.top() != '[') return false;

            st.pop();
        }

    }

    if(st.empty()) return true;

    return false;
}


int main() {
    int size;
    ifstream inf("input5.txt", ios::in);

    if(!inf) {
        cout << "File not opened" << endl;
        exit(0);
    }

    inf >> size;
    // cout << size;

        string str;
    for (int i = 0; i < size; i++)
    {

        //getline(inf, str);
        inf>>str;
        if(delimetersOk(str)) cout << "Valid" << endl;
        else cout << "InValid" << endl;
    }

    return 0;
}