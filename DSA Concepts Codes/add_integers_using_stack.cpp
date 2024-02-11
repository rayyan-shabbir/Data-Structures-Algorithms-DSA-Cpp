#include "iostream"
#include "stack"
using namespace std;


int main() {
    int carry = 0;
    stack<int> op1;
    stack<int> op2;
    stack<int> res;

    string operand1 = {" "};
    string operand2 = {" "};

    cout << "Enter Operand # 01: ";
    cin >> operand1;

    cout << "Enter Operand # 02: ";
    cin >> operand2;

    cout << endl;

    for(int i = 0; i < operand1.length(); i++) {
        cout << operand1[i] << " ";
        int c = operand1[i] - '0';
        op1.push(c);
    }

    cout << endl << "    ";

    for(int i = 0; i < operand2.length(); i++) {
        cout << operand2[i] << " ";
        int c = operand2[i] - '0';
        op2.push(c);
    }

    cout << endl << "----------" << endl;

    while(!op1.empty() && !op2.empty()) {
        int get = op1.top() + op2.top() + carry;
        int result = get%10;

        res.push(result);

        carry = get/10;

        op1.pop(), op2.pop();
    }

    while(!op1.empty()) {
        int get = op1.top() + carry;
        int result = get%10;

        res.push(result);

        carry = get/10;

        op1.pop();
    }

    while(!op2.empty()) {
        int get = op2.top() + carry;
        int result = get%10;

        res.push(result);

        carry = get/10;

        op2.pop();
    }

    while (!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }

    // while(!op1.empty()) {
    //     cout << op1.top();
    //     op1.pop();
    // }



    return 0;
}