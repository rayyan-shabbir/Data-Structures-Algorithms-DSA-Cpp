#include "iostream"
using namespace std;

class Node {
    int data;
    Node* next;

    public:
        //CONSTRUCTOR
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }

        //MAKING CLASS NODE PUBLIC TO LINKEDLIST
        friend class LinkedList;
};

class LinkedList {
    Node* head;

    public:
        //DEFAULT CONSTRUCTOR
        LinkedList() {
            head = NULL;
        }

        //DESTRUCTOR
        ~LinkedList() {
            Node* cur = head;

            while(cur->next != head) {
                head = head->next;
                delete cur;
                cur = head;
            }

            delete head;
            delete cur;
        }
        //IS EMPTY METHOD
        bool isEmpty() {
            return !head;
        }

        //INSERT AT START
        void insertAtStart(int data) {
            Node* newNode = new Node(data, NULL);

            if(head == NULL) {
                head = newNode;
                head->next = head;
            } else {
                Node* cur = head;

                while(cur->next != head) cur = cur->next;

                newNode->next = head;
                head = newNode;

                cur->next = newNode;
            }
        }

        //INSERT AFTER NODE
        void insertAfterNode(int data, Node* prev) {
            if(prev == NULL) cout << "Node cannot be NULL" << endl;
            else {
                Node* newNode = new Node(data, NULL);

                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
        
        //INSERT AT INDEX
        void insertAtIndex(int data, int index) {
            Node* newNode = new Node(data, NULL);
            if(index == 0) {
                Node* cur = head;
                
                while(cur->next != head) cur = cur->next;

                newNode->next = head;
                head = newNode;

                cur->next = head;
            } else {
                Node* cur = head;
                int i = 0;

                while(i < index-1) {
                    cur = cur->next;
                    i++;
                }

                newNode->next = cur->next;
                cur->next = newNode;
            }
        }

        //INSERT AT END
        void insertAtEnd(int data) {
            Node* newNode = new Node(data, NULL);
            if(head == NULL) {
                head = newNode;
                head->next = head;
            } else {
                Node* cur = head;

                newNode->next = head;

                while(cur->next != head) cur = cur->next;

                cur->next = newNode;
            }
        }

        //DELETE AT START
        void deleteAtStart() {
            if(head == NULL) cout << "Circular LinkList is Already Empty..." << endl;
            else if(head->next == head) {
                delete head;
                head = NULL;
            } else {
                Node* temp = head;
                Node* cur = head;

                while(cur->next != head) cur = cur->next;

                head = head->next;

                cur->next = head;

                delete temp;
            }
        }

        //DELETE AT INDEX
        void deleteAtIndex(int index) {
            Node* prev = head;
            Node* cur = head->next;

            if(head->next == head && index == 0) {
                delete head;
                head = NULL;
            } else if(index == 0) {
                while(cur->next != head) cur = cur->next;

                head = head->next;
                cur->next = head;

                delete prev;
            } else {
                int i = 0;
                while(i < index-1) {
                    prev = cur;
                    cur = cur->next;
                    i++;
                }

                prev->next = cur->next;
                delete cur;
            }
        }

        //DELETE PARTICULAR NODE
        void deleteParticularNode(int key) {
            Node* prev = head;
            Node* cur = head->next;

            if(head->next == head && head->data == key) {
                delete head;
                head = NULL;
            } else if(prev->data == key) {
                while(cur->next != head) cur =  cur->next;

                head = head->next;
                cur->next = head;
                delete prev;
            } else {
                while(cur->data != key && cur != head) {
                    prev = cur;
                    cur = cur->next;
                }

                prev->next = cur->next;
                delete cur; 
            }
        }

        //DELETE AT END
        void deleteAtEnd() {
            if(head == NULL) cout << "Circular LinkList is Already Empty..." << endl;
            else if(head->next == head) {
                delete head;
                head = NULL;
            } else {
                Node *prev = head;
                Node *cur = head->next;

                while(cur->next != head) {
                    prev = cur;
                    cur = cur->next;
                }

                prev->next = head;
                delete cur;
            } 
        }

        //DISPLAY CIRCULAR LINKED LIST DATA
        void display() {
            if(head == NULL) cout << "Circular LinkList is Empty..." << endl;
            else {
                Node* cur = head;

                cout << "\nCircular List: ";
                do {
                    cout << "\t" << cur->data;
                    cur = cur->next;
                } while(cur != head);
            }
        }
};

int main() {
    LinkedList l1;

    cout << l1.isEmpty() << endl;

    l1.insertAtStart(1);
    l1.insertAtEnd(5);
    l1.insertAtEnd(6);
    l1.insertAtEnd(7);
    l1.insertAtIndex(2, 1);
    l1.insertAtIndex(3, 2);
    l1.insertAtIndex(4, 3);

    l1.display();

    l1.deleteAtStart();
    l1.deleteAtEnd();
    l1.deleteParticularNode(3);
    l1.deleteAtIndex(2);

    l1.display();

    return 0;
}