#include "iostream"
using namespace std;

class Node {
    int data;
    Node* next;

    public:
        //PARAMETRIZE CONSTRUCTOR
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }

        friend class Stack; //Node class became public to Stack
};

class Stack {
    Node* top;

    public:
        //DEFAULT CONSTRUCTOR
        Stack() {
            top = NULL;
        }

        //DESTRUCTOR
        ~Stack() {
            Node* cur = top;

            while(cur != NULL) {
                top = top->next;
                delete cur;
                cur = top;
            }

            delete top;
        }

        //IS EMPTY FUNCTION
        bool isEmpty() {
            if(top == NULL)
                return true;
            
            return false;
        }

        //PUSH FUNCTION
        void push(int data) {
            Node* newNode = new Node(data, NULL);

            newNode->next = top;
            top = newNode;
        }

        //POP FUNCTION
        void pop() {
            if(top == NULL) cout << "\nStack Underflow..." << endl;
            else {
                Node* cur = top;

                top = top->next;
                delete cur;
            }
        }
        
        //GET TOP FUNCTION
        int getTop() {
            if(top == NULL) {
                cout << "\nStack Underflow..." << endl;
                return -1;
            } else return top->data;
        }

        //CLEAR FUNCTION
        void clear() {
            top == NULL;
        }

        //DISPLAY STACK DATA
        void showStructure() {
            Node* cur = top;
            if(cur == NULL) cout << "\nStack Underflow..." << endl;
            else {
                cout << "\nTOP ---> ";
                while(cur != NULL) {
                    cout << "\t" << cur->data;
                    cur = cur->next;
                }   
            }   
        }
};

int main() {
    Stack rdx1;

    rdx1.push(5);
    rdx1.push(6);
    rdx1.showStructure();

    rdx1.pop();
    rdx1.pop();

    int top = rdx1.getTop();

    cout << top;

    rdx1.push(-3);
    rdx1.push(-8);
    rdx1.showStructure();

    rdx1.pop();
    rdx1.pop();
    rdx1.showStructure();
    return 0;
}