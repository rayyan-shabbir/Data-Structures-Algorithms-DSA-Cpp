#include "iostream"
using namespace std;

class Node {
    private:
        int data;
        Node *prev;
        Node *next;
    public:
        Node(int data, Node *prev, Node *next) {
            this->data = data;
            this->prev = prev;
            this->next = next;
        }

        friend class DoublyList;
};

class DoublyList {
    private:
        Node *head;
    public:
        // CONSTRUCTOR
        DoublyList() {
            head = NULL;
        }

        bool isEmpty() {
            return !head;
        }

        // DESTRUCTOR
        ~DoublyList() {
            if(head != NULL) {
                Node* cur = head;

                while(cur != NULL) {
                    head = head->next;

                    delete cur;
                    cur = head;
                }

                delete head;
            }
        }

        // INSERT AT START
        void insertAtStart(int data) {
            Node *newNode = new Node(data, NULL, NULL);

            if(head == NULL) {
                head = newNode;
                head->next = NULL;
                head->prev = NULL;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void insertAfterNode(int data, Node *prevNode) {
            if(prevNode == NULL) {
                cout << "Previous Node cannot be NULL" << endl;
            } else {
                Node *newNode = new Node(data, NULL, NULL);

                newNode->next = prevNode->next;
                prevNode->next->prev = newNode;

                prevNode->next = newNode;
                newNode->prev = prevNode;
            }
        }

        void insertAtIndex(int data, int index) {
            if(index < 0) {
                cout << "Index is invalid" << endl;
            } else {
                Node *newNode = new Node(data, NULL, NULL);
                Node *ptr = head;

                int i = 0;
                while(i != index-1) {
                    ptr = ptr->next;
                    i++;
                }

                newNode->next = ptr->next;
                ptr->next->prev = newNode;

                ptr->next = newNode;
                newNode->prev = ptr;

            }
        }

        void insertAtEnd(int data) {
            Node *newNode = new Node(data, NULL, NULL);
            if(head == NULL) {
                head = newNode;
            } else {
                Node *curNode = head;

                while(curNode->next != NULL) {
                    curNode = curNode->next;
                }

                curNode->next = newNode;
                newNode->prev = curNode;
            }
        }

        void deleteFirstNode() {
            if(head == NULL) {
                cout << "Doubly List is already Empty" << endl;
            } else {
                Node *curNode = head;

                head = head->next;
                head->prev = NULL;
                delete curNode;
                curNode = NULL;
            }
        }

        void deleteAtIndex(int index) {
            if(index < 0) {
                cout << "Invalid index" << endl;
            } else if (index == 0) {
                Node* cur = head;

                head = head->next;
                head->prev = NULL;
                delete cur;
            } else {
                Node *ptr = head;

                int i = 0;
                while(i < index-1) {
                    ptr = ptr->next;
                    i++;
                }

                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                delete ptr;
                ptr = NULL;
            }
        }

        void deleteParticularNode(int key) {
            Node *ptr = head;

            while(ptr->data != key && ptr->next != NULL) {
                ptr = ptr->next;
            } 

            if(ptr->data == key) {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                delete ptr;
                ptr = NULL;
            } else {
                cout << "Key not found" << endl;
            }
        }

        void deleteLastNode() {
            if(head == NULL) {
                cout << "Doubly List is already Empty" << endl;
            } else {
                if(head->next == NULL) {
                    delete head;
                    head = NULL;
                } else {
                    Node *curNode = head->next;

                    while(curNode->next != NULL) {
                        curNode = curNode->next;
                    }

                    curNode->prev->next = NULL;
                    delete curNode;
                    curNode = NULL;
                }
            }
        }

        void displayForward() {
            if(head == NULL) {
                cout << "\nDoubly List is empty (F)." << endl;
            } else {
                Node *ptr = head;

                cout << "\nDoubly List Forward: ";
                while(ptr != NULL) {
                    cout << "\t" << ptr->data;
                    ptr = ptr->next;
                }
            }
        }

        void displayBackward() {
            if(head == NULL) {
                cout << "\nDoubly List is empty (B)." << endl;
            } else {
                Node *ptr = head;
                while(ptr->next != NULL) {
                    ptr = ptr->next;
                }

                cout << "\nDoubly List Backward";
                while(ptr != NULL) {
                    cout << "\t" << ptr->data;
                    ptr = ptr->prev;
                }
            }
        }
};

int main() {
    DoublyList l1;

    //cout << l1.isEmpty() << endl;

    //l1.displayForward();
    //l1.displayBackward();

    l1.insertAtStart(2);
    l1.insertAtEnd(6);
    l1.insertAtIndex(3, 1);
    l1.insertAtEnd(7);
    l1.insertAtStart(1);
    l1.insertAtIndex(4, 3);
    l1.insertAtIndex(5, 4);

    l1.displayForward();
    l1.displayBackward();

    l1.deleteFirstNode();
    l1.deleteLastNode();
    l1.deleteParticularNode(3);
    l1.deleteAtIndex(3);

    l1.displayForward();
    l1.displayBackward();
    return 0;
}