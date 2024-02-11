#include "iostream"
using namespace std;

class Node {
    private:
        int data;
        Node *next;
    public:
        Node(int data, Node *next) {
            this->data = data;
            this->next = next;
        }

        friend class CircularList;
};

class CircularList {
    private:
        Node *head;
    public:
        // CONSTRUCTOR
        CircularList() {
            head = NULL;
        }

        // DESTRUCTOR
        ~CircularList() {
            if(head != NULL) {
                Node* temp = head;
                while(temp->next != head) {
                    temp = temp->next;
                }

                Node* cur = head;
                 while(cur->next != head) {
                    head = head->next;
                    temp->next = head;

                    delete cur;
                    cur = head;
                }

                delete head;
                head = NULL;
            }
        }

        bool isEmpty() {
            return !head;
        }

        void insertAtStart(int data) {
            Node *newNode = new Node(data, NULL);

            if(head == NULL) {
                head = newNode;
                head->next = head;
            } else {
                Node *curNode = head;
                
                while(curNode->next != head) {
                    curNode = curNode->next;
                }
                curNode->next = newNode;

                newNode->next = head;
                head = newNode;
            }
        }

        void insertAfterNode(int data, Node *prevNode) {
            if(prevNode == NULL) {
                cout << "Previous Node cannot be NULL" << endl;
            } else {
                Node *newNode = new Node(data, NULL);
                
                newNode->next = prevNode->next;
                prevNode->next = newNode;
            }
        }

        void insertAtIndex(int data, int index) {
            if(index < 0) {
                cout << "Index is Invalid" << endl;
            } else {
                Node *newNode = new Node(data, NULL);
                Node *ptr = head;

                int i = 0;
                while(i != index-1) {
                    ptr = ptr->next;
                    i++;
                }

                newNode->next = ptr->next;
                ptr->next = newNode;
            }
        }

        void insertAtEnd(int data) {
            Node *newNode = new Node(data, NULL);

            if(head == NULL) {
                head = newNode;
                head->next = head;
            } else {
                Node *curNode = head;

                while(curNode->next != head) {
                    curNode = curNode->next;
                }

                curNode->next = newNode;
                newNode->next = head;
            }
        }

        void deleteFirstNode() {
            if(head == NULL) {
                cout << "Circular Link List is already empty" << endl;
            } else {
                if(head->next == head) {
                    delete head;
                    head = NULL;
                } else {
                    Node *ptr = head;
                    Node *curNode = head->next;

                    while(curNode->next != head) {
                        curNode = curNode->next;
                    }

                    curNode->next = head->next;
                    head = head->next;
                    delete ptr;
                    ptr = NULL;
                }
            }
        }

        void deleteAtIndex(int index) {
            Node *prevNode = head;
            Node *curNode = head->next;

            int i = 0;
            while(i < index-1) {
                prevNode = prevNode->next;
                curNode = curNode->next;
                i++;
            }

            prevNode->next = curNode->next;
            delete curNode;
            curNode = NULL;
        }

        void deleteParticularNode(int key) {
            Node *prevNode = head;
            Node *curNode = head->next;

            while(curNode->data != key && curNode->next != head) {
                prevNode = prevNode->next;
                curNode = curNode->next;
            }

            if(curNode->data == key) {
                prevNode->next = curNode->next;
                delete curNode;
                curNode = NULL;
            } else {
                cout << "Key not Found" << endl;
            }
        }

        void deleteLastNode() {
            if(head == NULL) {
                cout << "Circular LinkList is already empty" << endl;
            } else {
                if(head->next == head) {
                    delete head;
                    head = NULL;
                } else {
                    Node *prevNode = head;
                    Node *curNode = head->next;

                    while(curNode->next != head) {
                        curNode = curNode->next;
                        prevNode = prevNode->next;
                    }

                    prevNode->next = head;
                    delete curNode;
                    curNode = NULL;
                }
            }
        }

        void display() {
            if(head == NULL) {
                cout << "\nCircular LinkList is empty" << endl;
            } else {
                Node *curNode = head;
                
                cout << "\nCircular List: ";
                do {
                    cout << "\t" << curNode->data;
                    curNode = curNode->next;
                } while(curNode != head);
            }
        }
};



int main() {
    CircularList l1;

    //cout << l1.isEmpty() << endl;

    l1.display();

    l1.insertAtStart(1);
    l1.insertAtEnd(5);
    l1.insertAtEnd(6);
    l1.insertAtEnd(7);
    l1.insertAtIndex(2, 1);
    l1.insertAtIndex(3, 2);
    l1.insertAtIndex(4, 3);

    l1.display();
    
    l1.deleteFirstNode();
    l1.deleteLastNode();
    l1.deleteParticularNode(3);
    l1.deleteAtIndex(2);

    l1.display();

    //cout << endl << l1.isEmpty() << endl;
    return 0;
}