#include "iostream"
using namespace std;

template <class T>
class Queue {
    // Data Memebers
    T *data;        //array of items to be allocated dynamically as per MAX_SIZE
    int front;      //front index
    int rear;       //rear index
    const int MAX_SIZE;     //size of queue

    public:
        //CONSTRUCTOR
        Queue(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE) 
        {
            this->data = new T[this->MAX_SIZE];
            this->front = -1;
            this->rear = -1;

            for(int i = 0; i < MAX_SIZE; i++)
                this->data[i] = 0;
        }


        //DESTRUCTOR
        ~Queue() {
            delete[] data;
        }


        //QUEUE MANIPULATION OPERATIONS
        void enQueue(const T newItem)    //Add an element to the rear of queue
        {
            if(!isFull()) {
                rear = (rear+1) % MAX_SIZE;
                data[rear] = newItem;
                if(front == -1)
                    front = rear;
            } else 
                cerr << "Queue is Full!" << endl;
        }

        void deQueue()      //Delete element at the front of Queue
        {
            if(!isEmpty()) {
                if(front == rear) 
                    front = rear = -1;
                else 
                    front = (front+1) % MAX_SIZE;
            } else 
                cerr << "Queue is Empty!" << endl;
        }

        void clear()        //Clear the Queue
        {
            if(isEmpty()) cout << "Queue is Alraedy Cleared" << endl;
            else {
                this->front = -1;
                this->rear = -1;
                cout << "Queue is Cleared" << endl;
            }
        }


        //QUEUE ACCESSORS
        T getFront() const      //Return element at the front
        {
            if(isEmpty()) {
                cerr << "Queue is Empty!" << endl;
                return -1;
            } else 
                return data[this->front];
        }

        T getRear() const      //Return element at the rear
        {
            if(isEmpty()) {
                cerr << "Queue is Empty!" << endl;
                return -1;
            } else 
                return data[this->rear];
        }


        //QUEUE STATUS OPERATIONS
        bool isEmpty() const    //Is queue Empty?
        {
            if(this->front == -1 && this->rear == -1) return true;

            return false;
        }

        bool isFull() const     //Is queue Full?
        {
            if((this->rear + 1) % this->MAX_SIZE == this->front) return true;

            return false;
        }


        //OUTPUTS THE DATA IN QUEUE. IF THE QUEUE IS EMPTY, OUTPUTS “Empty Queue”.
        void showStructure() const
        {
            if(isEmpty()) cerr << "Empty Queue" << endl;
            else {
                cout << "Front --> ";
                for(int i = front; i < rear+1; i++) {
                    if(i != rear) {
                        cout << this->data[i] << endl;
                        cout << "         ";
                    } else {
                        cout << this->data[i] << "  <---rear";
                        cout << endl;
                    }
                }
            }
        }
};

int main() {
    Queue<int> rdx1;
    Queue<float> rdx2;

    rdx2.enQueue(5.0);
    rdx2.enQueue(6.5);
    // rdx2.showStructure();

    rdx2.enQueue(-3.0);
    rdx2.enQueue(-8.0);
    // rdx2.showStructure();

    rdx2.deQueue();
    rdx2.deQueue();
    rdx2.showStructure();

    return 0;
}