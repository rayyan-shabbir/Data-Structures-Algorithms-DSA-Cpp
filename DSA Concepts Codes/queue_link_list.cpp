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

        //NODE CLASS BECAME PUBLIC TO QUEUE
        friend class Queue;
};

class Queue {
    Node* front;
    Node* rear;

    public:
        //DEFAULT CONSTRUCTOR
        Queue() {
            front = NULL;
            rear = NULL;
        }

        //DESTRUCTOR
        ~Queue() {
            if(front != NULL) {
				Node* cur = front;

				while(cur != NULL) {
					front = front->next;
					delete cur;
					cur = front;
				}
			}
        }

        //IS EMPTY FUNCTION
        bool isEmpty() {
            if(front == NULL) return true;

            return false;
        }

        //TO INSERT DATA (ENQUEUE)
        void enQueue(int data) {
            Node* newNode = new Node(data, NULL);

            if(front == NULL) {
                front = newNode;
                rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        //TO DELETE DATA (DEQUEUE)
        void deQueue() {
            if(front == NULL) cout << "Queue is Undeflow..." << endl;
            else {
                Node* cur = front;

                if(cur->next == NULL) {
                    delete cur;

                    front = NULL;
                    rear = NULL;
                } else {
                    front = front->next;

                    delete cur;
                }
            }
        }

        //CLEAR FUNCTION
        void clear() {
            front = NULL;
            rear = NULL;
            cout << "Queue is Cleared..." << endl;
        }


        //GET FRONT
        int getFront() {
            if(front == NULL) {
                cout << "Queue Underflow..." << endl;
                return -1;
            }

            return front->data;   
        }

        //GET FRONT
        int getRear() {
            if(rear == NULL) {
                cout << "Queue Underflow..." << endl;
                return -1;
            }

            return rear->data;   
        }


        //DISPLAY DATA OF QUEUE
        void showStructure() {
            if(front == NULL) cout << "Queue is Underflow..." << endl;
            else {
                Node* cur = front;

                cout << "\nQueue: ";
                while(cur != NULL) {
                    cout << "\t" << cur->data;
                    cur = cur->next;
                }
            }
        }
};

int main() {
    Queue rdx1;

    rdx1.enQueue(5);
    rdx1.enQueue(6);
    // rdx2.showStructure();

    rdx1.enQueue(-3);
    rdx1.enQueue(-8);
    // rdx2.showStructure();

    rdx1.deQueue();
    rdx1.deQueue();
    rdx1.showStructure();
    return 0;
}