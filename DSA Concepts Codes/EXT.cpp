#include "iostream"
using namespace std;

class Node{
	int data;
	Node* next;

	public:
		Node(int data, Node*next) {
			this->data = data;
			this->next = next;
		}

		friend class Queue;
};

class Queue{
	Node* front;
	Node* rear;
	Node* top;

	public:
		Queue() {
			front = NULL;
			rear = NULL;
		}

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

		bool isEmpty() {
			if(front == NULL) return true;
		}

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

		void deQueue() {
			if(front == NULL) {
				cout << "Queue is Empty";
			} else if(front->next == NULL) {
				delete front;
				front = rear = NULL;
			} else {
				Node* temp = front;

				front = front->next;
				delete temp;
			}
		}

		void clear() {
			front = NULL;
			rear = NULL;
		}

		int getFront() {
			if(front == NULL) {
				cout << "Queue is underflow";
				return -1;
			} else {
				return front->data;
			}
		}

		int getRear() {
			if(front == NULL) {
				cout << "Queue is underflow";
				return -1;
			} else {
				return rear->data;
			}
		}

		void showStructure() {
			if(front == NULL) cout << "Queue is underflow";
			else {
				Node* cur = front;
				while(cur != NULL) {
					cout << cur->data;
					cur = cur->next;
				}
			}
		}

		void push(int data) {
			Node* newNode = new Node(data, NULL);

			newNode->next = top;
			top = newNode;
		}

		void pop() {
			if(top == NULL) cout << "Stack underflow";
			else {
				Node* cur = top;

				top = top->next;
				delete cur;
			}
		}


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

		void deQueue() {
			if(front == NULL) cout << "Queue Undeflow";
			else {
				Node *cur = front;

				if(front->next == NULL) {
					front = NULL;
					rear = NULL;

					delete cur;
				} else {
					front = front->next;

					delete cur;
				}
			}
		}

};