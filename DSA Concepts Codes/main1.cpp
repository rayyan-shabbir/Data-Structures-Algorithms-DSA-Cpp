#include "iostream"
using namespace std;
#define size 5

int stack_arr[size];
int first = -1;

int isEmpty() {
    if(first == -1) return 1;
    else    return 0;
}

int isFull() {
    if(first == size-1) return 1;
    else    return 0;
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

void print() {
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
        cout << "\nEnter '1' for push an element";
        cout << "\nEnter '2' for pop an element";
        cout << "\nEnter '3' to print the top element";
        cout << "\nEnter '4' to print the whole stack";
        cout << "\nEnter 5 to exit";

        cout << "\n~~~ENTER YOUR CHOICE~~~\n";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value you want to push: ";
                cin >> val;
                push(val);
                break;
            case 2:
                val = pop();
                cout << "The deleted Element is: " << val << endl;
                break;
            case 3:
                val = peek();
                cout << "The top element is: " << peek() << endl;
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
                break;
            default:
                cout << "Wrong Input" << endl;
                break;
        }
    }

    return 0;
}