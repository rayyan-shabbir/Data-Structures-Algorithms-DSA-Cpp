#include "iostream"
#include "stack"
#include "queue"
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^')
        return true;
    else
        return false;
}

int operatorPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else if (op == '(' || op == ')')
        return 0;
    else
        return -1;
}

int main()
{
    stack<char> st;
    string inf_exp;
    string post_exp = {" "};

    std::cout << "Enter infix expression: ";
    cin >> inf_exp;

    for (int i = 0; i < inf_exp.length(); i++)
    {
        char c = inf_exp[i];
        if (!isOperator(c))
            post_exp += c;
        else if(isOperator(c))
        {
            if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while ((st.top() != '(') && (!st.empty()))
                {
                    char poppedOperator = st.top();
                    st.pop();
                    post_exp += poppedOperator;
                    // cout << poppedOperator;
                }

                st.pop();
            }
            else if (st.empty())
                st.push(c);
            else
            {
                int out_priority = operatorPrecedence(c);

                char top = st.top();

                int in_priority = operatorPrecedence(top);

                if ((out_priority > in_priority) || (in_priority == out_priority && c == '^'))
                {
                    st.push(c);
                }
                else
                {
                    while ((!st.empty()) && operatorPrecedence(c) <= operatorPrecedence(st.top()))
                    {
                        char poppedOperator = st.top();
                        st.pop();
                        post_exp += poppedOperator;
                        // cout << poppedOperator;

                        if (!st.empty())
                        {
                            top = st.top();
                            if (top == '(')
                                break;
                            int in_priority = operatorPrecedence(top);
                        }
                        else
                            break;
                    }

                    st.push(c);
                }
            }
        }
    }

    while (!st.empty())
    {
        char c = st.top();
        st.pop();
        post_exp += c;
        // cout << c;
    }

    std::cout << "INFIX EXPRESSION:: " << inf_exp << endl;
    std::cout << "POSTFIX EXPRESSION:: " << post_exp << endl;

    return 0;
}