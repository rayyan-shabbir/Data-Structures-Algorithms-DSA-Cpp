#include "iostream"
#include "stack"
#include "math.h"
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}


int main() {
    stack<int> st;
    string preFix = {" "};

    cout << "Enter preFix Expression: ";
    cin >> preFix;

    int i = (preFix.length()-1);

    while(i >= 0) {
        char c = preFix[i];
        while(!isOperator(c)) {
            int p = (c - '0');
            st.push(p);
            i--;
            c = preFix[i];
        }

        int top = 0, preTop = 0, result = 0;

        switch(c) {
            case '+':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = (top + preTop);
                st.push(result);
                break;
            case '-':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = (top - preTop);
                st.push(result);
                break;
            case '*':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = (top * preTop);
                st.push(result);
                break;
            case '/':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = (top / preTop);
                st.push(result);
                break;
            case '^':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result =(pow(top, preTop));
                st.push(result);
                break;
        }

        i--;
    }

    cout << "Stack Size: " << st.size() << endl;

    cout << "Result: " << st.top() << endl;
    return 0;
}