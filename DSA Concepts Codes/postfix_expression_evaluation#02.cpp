#include<iostream>
#include<stack>
#include<math.h>
#include<string>
#include<cctype>  // have built in function to check whether the character is digit or not

using namespace std;


int postfixEvalution(string Postfix);
bool isOperator(char Postfix);
int main()
{
	string Postfix;
	cout << "Enter the Postfix Expression" << endl;
	cin >> Postfix;

	int ans= postfixEvalution(Postfix);
	cout << "Ans is : " << ans << endl;

	return 0;
}


bool isOperator(char Postfix)
{
	if (Postfix == '+' || Postfix == '-' || Postfix == '*' || Postfix == '/' || Postfix == '^')
	{
		return true;
	}
	else
		return false;
}

int postfixEvalution(string Postfix)
{
	int value;
	int operand1;
	int operand2;
	stack <int> s;
	for (int i = 0; i < Postfix.length(); i++)
	{
		if (isdigit(Postfix[i]))
		{
			s.push(Postfix[i]-'0'); // 0 has assci value 48 if we push 1 then it has assci value
			                        // 49 so it will do 49-48 and ans is 1 and it will push into stack.
		}
		else if (isOperator(Postfix[i]))
		{
			
				char c = Postfix[i];
				switch (c)
				{
				case '+':
;					operand1 = s.top();
					s.pop();
					operand2 = s.top();
					s.pop();
					s.push(operand2 + operand1);
					break;

				case '-':
					 operand1 = s.top();
					s.pop();
					 operand2 = s.top();
					s.pop();
					s.push(operand2 - operand1);
					break;

				case '*':
					 operand1 = s.top();
					s.pop();
					 operand2 = s.top();
					s.pop();
					s.push(operand2 * operand1);
					break;
				case '/':

					operand1 = s.top();
					s.pop();
					operand2 = s.top();
					s.pop();
					s.push(operand2 / operand1);
					break;

				case '^':
					operand1 = s.top();
					s.pop();
					operand2 = s.top();
					s.pop();
					s.push(pow(operand2, operand1));
					break;
				}	
		}

	}
	value = s.top();
	return value;
}
