#include "iostream"
using namespace std;
#define size 5

int first = -1;
int stack_arr[size];

int isEmpty() {
    if(first == -1) return 1;
    else            return 0;
    
}

int isFull() {
    if(first == size-1) return 1;
    else                return 0;
}

void push(int data) {
    if(isFull()) {
        cout << "Stack is overflow" << endl;
        return;
    }

    first++;
    for (int i = first; i > 0; i--)
    {
        stack_arr[i] = stack_arr[i-1];
    }

    stack_arr[0] = data;
}

int pop() {
    if(isEmpty()) {
        cout << "Stack is underflow" << endl;
        exit(1);
    }

    int val = stack_arr[0];

    for (int i = 0; i < first; i++)
    {
        stack_arr[i] = stack_arr[i+1];
    }
    first--;
    return val;
}

int peek() {
    if(isEmpty()) {
        cout << "Stack is underflow" << endl;
        exit(1);
    }

    return stack_arr[0];
}

void printStack() {
    if(isEmpty()) {
        cout << "Stack is underflow" << endl;
        exit(1);
    }

    cout << "Stack: ";
    for (int i = 0; i <= first; i++)
    {
        cout << "\t" << stack_arr[i];
    }
    
}

int main() {
    int val, choice;
    while(1) {
        cout << "\n***Menue***";
        cout << "\n1. Enter '1' for push an element.";
        cout << "\n2. Enter '2' for pop an element.";
        cout << "\n3. Enter '3' to print the top element.";
        cout << "\n4. Enter '4' to print the whole stack.";
        cout << "\n5. Enter '5' to exit.";
        cout << "\n\n~~Enter Your Choice~~\n";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nEnter Value you want to push: ";
                cin >> val;
                push(val);
                break;
            case 2:
                val = pop();
                cout << "\nThe deleted Element is: " << val;
                break;
            case 3:
                val = peek();
                cout << "\nThe Top element of stack is: " << val;
                break;
            case 4:
                printStack();
                break;
            case 5:
                exit(1);
                break;
            default:
                cout << "\nWrong Input....SORRY!" << endl;
                break;
        }
    }

    return 0;
}