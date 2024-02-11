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
    string inf_exp, originalInfix;
    string post_exp = {" "};
    string pre_exp = {" "};

    std::cout << "Enter infix expression: ";
    cin >> inf_exp;

    originalInfix = inf_exp;

    //First Reversing Infix Expression...
    int j = (inf_exp.length()-1);
    for(int i = 0; i < (inf_exp.length()/2); i++) {
        if((inf_exp[i] != '(' && inf_exp[i] != '{') && (inf_exp[j] != ')' && inf_exp[j] != '}'))
            swap(inf_exp[i], inf_exp[j]);
        j--;
    }


    cout << "Reverse INFIX: " << inf_exp << endl;


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

                if ((out_priority >= in_priority) || (in_priority == out_priority && c == '^'))
                {
                    st.push(c);
                }
                else
                {
                    while ((!st.empty()) && operatorPrecedence(c) < operatorPrecedence(st.top()))
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

    std::cout << "POSTFIX EXPRESSION:: " << post_exp << endl;

    //Reversing PostFix Expression...
    int k = (post_exp.length()-1);
    for(int i = 0; i < (post_exp.length()/2); i++) {
        swap(post_exp[i], post_exp[k]);
        k--;
    }

    pre_exp = post_exp;

    std::cout << "\nINFIX EXPRESSION:: " << originalInfix << endl;
    std::cout << "PREFIX EXPRESSION:: " << pre_exp << endl;

    return 0;
}