#include "iostream"
#include "stack"
#include "queue"
using namespace std;

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') 
        return true;
    
    return false;
}

int operatorPrecedence(char op) {
    if(op == '+' || op == '-') return 1;
    else if(op == '*' || op == '/') return 2;
    else if(op == '(') return 0;
}

int main() {
    string infix;
    string postfix = {" "};

    stack<char> st;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if(!isOperator(c)) postfix += c;
        else {
            if(c == '(') st.push(c);
            else if(c == ')') {
                while(st.top() != '(') {
                    char poppedOperator = st.top();
                    st.pop();
                    postfix += poppedOperator;
                }

                st.pop();
            } else if(st.empty()) st.push(c);
            else {
                int outPriority = operatorPrecedence(c);

                char top = st.top();

                int inPriority = operatorPrecedence(top);

                while(outPriority <= inPriority) {
                    char poppedOperator = st.top();
                    st.pop();
                    postfix += poppedOperator;

                    if(!st.empty()) {
                        top = st.top();

                        if(top == '(') st.pop();

                        inPriority = operatorPrecedence(top);
                        else break;
                    } else break;
                }

                st.push(c);

                st.push(c);
            }
        }
    }

    

    return 0;
}