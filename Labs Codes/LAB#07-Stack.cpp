#include "iostream"
using namespace std;

template <class T>
class Stack {
    // DATA MEMBERS
    T *data;    //array of items to be allocated dynamically as per MAX_SIZE
    int top;    //top of the stack
    const int MAX_SIZE;      //maximum capacity of the stack

    public:
        //CONSTRUCTOR
        Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
        {   
            this->data = new T[this->MAX_SIZE];
            this->top = -1;

            // for(int i = 0; i < MAX_SIZE; i++)
            //     data[i] = 0;
        }


        //DESTRUCTOR
        ~Stack() {
            delete[] data;
        }


        //STACK MANIPULATION OPERATIONS
        void push(const T newItem)  // Push an Item
        {    
            if(top != MAX_SIZE-1) {
                data[++top] = newItem;
            } else {
                cerr << "Stack Overflow" << endl;
            }
        }

        void pop()  // Pop an Item
        {
            if(this->top == -1) {
                cerr << "Stack Underflow" << endl;
            } else {
                this->top--;
            }
        }

        void clear()    //Clear the Stack
        {
            if(top == -1) {
                cout << "Stack is already empty" << endl;
            } else {
                this->top = -1;
                cout << "Stack is cleared" << endl;
            }
        }


        //STACK ACCESSOR
        T getTop() const    //Return item at the top
        {
            if(top != -1) {
                return data[top];
            }

            cerr << "Stack Underflow" << endl;

            int ret = -1;

            T i = static_cast<T>(ret);
            return i;

            //return -1;
        }


        //STACK STATUS OPERATIONS
        bool isEmpty() const    //Is stack empty?
        {
            if(this->top == -1) return true;

            return false;
        }

        bool isFull() const     //Is stack full?
        {
            if(this->top == this->MAX_SIZE-1) return true;

            return false;
        }


        //OUTPUTS THE DATA IN STACK. IF THE STACK IS EMPTY, OUTPUTS “Empty Stack”.
        void showStructure() const
        {
            if(top == -1) cerr << "Empty Stack" << endl;
            else {
                cout << "TOP ---> ";
                for(int i = top; i > -1; i--) {
                    cout << data[i] << endl;
                    cout << "          ";
                }
            }
        }
};

int main() {
    Stack<int> rdx1;
    Stack<float> rdx2;

    // cout << top;

    rdx2.push(5.0);
    rdx2.push(6.5);
    rdx2.showStructure();

    // rdx2.pop();
    // rdx2.pop();

    // float top = rdx2.getTop();

    // // cout << top;

    // rdx2.push(-3.0);
    // rdx2.push(-8.0);
    // // rdx2.showStructure();

    // rdx2.pop();
    // rdx2.pop();
    // rdx2.showStructure();

    return 0;
}