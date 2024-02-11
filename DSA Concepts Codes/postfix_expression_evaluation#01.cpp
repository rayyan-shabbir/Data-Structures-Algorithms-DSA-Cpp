#include "iostream"
#include "math.h"
#include "stack"
#include<cctype>  //This library have built in function to check whether the character is digit or not
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

int main()
{
    int i = 0;
    stack<int> st;
    string postFix = {" "};

    cout << "Enter PostFix expression: ";
    cin >> postFix;

    while (i < postFix.length())
    {
        char c = postFix[i];
        while (!isOperator(c))
        {
            int p = c - '0';        // 0 has assci value 48 if we push 1 then it has assci value
			                        // 49 so it will do 49-48 and ans is 1 and it will push into stack.
            st.push(p);
            i++;
            c = postFix[i];
        }

        int top = 0, preTop = 0, result = 0;
        switch(c)
        {
            case '+':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = preTop + top;
                st.push(result);
                break;
            case '*':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = (preTop * top);
                st.push(result);
                break;
            case '/':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = (preTop / top);
                st.push(result);
                break;
            case '-':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = (preTop - top);
                st.push(result);
                break;
            case '^':
                top = st.top();
                st.pop();
                preTop = st.top();
                st.pop();

                result = (pow(preTop, top));
                st.push(result);
                break;
        }

        i++;
    }

    cout << "Stack size: " << st.size() << endl;

    cout << "Result: " << st.top() << endl;

    return 0;
}