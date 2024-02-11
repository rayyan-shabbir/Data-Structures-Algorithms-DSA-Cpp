#include "iostream"
using namespace std;

class Node {
    int data;
    Node* previous;
    Node* next;

    public:
        //PARAMETRIZE CONSTRUCTOR
        Node(int data, Node* next, Node* previous) {
            this->data = data;
            this->previous = previous;
            this->next = next;
        }

        //LINKEDLIST CLASS BECOME PUBLIC TO NODE
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

            while(cur != NULL) {
                head = head->next;
                delete cur;
                cur = head;
            }

            delete head;
        }

        //IS EMPTY METHOD
        bool isEmpty() {
            return !head;
        }

        //INSERT AT START
        void insertAtStart(int data) {
            Node* newNode = new Node(data, NULL, NULL);

            if(head == NULL) head = newNode;
            else {
                newNode->next = head;
                head->previous = newNode;

                head = newNode;
            }
        }

        //INSERT AFTER NODE
        void insertAfterNode(int data, Node* cur) {
            if(cur == NULL) cout << "Node cannot be NULL" << endl;
            else {
                Node* newNode = new Node(data, NULL, NULL);
                
                newNode->next = cur->next;
                cur->next->previous = newNode;

                cur->next = newNode;
                newNode->previous = cur;
            }
        }

        //INSERT AT INDEX
        void insertAtIndex(int data, int index) {
            Node *newNode = new Node(data, NULL, NULL);

            if(index < 0) cout << "InValid Index..." << endl;
            else if(index == 0) {
                newNode->next = head;
                head->previous = newNode;

                head = newNode;
            } else {
                Node *cur = head;

                int i = 0;
                while(i != index-1) {
                    cur = cur->next;
                    i++;
                }

                newNode->next = cur->next;
                cur->next->previous = newNode;

                cur->next = newNode;
                newNode->previous = cur;

            }
        }

        //INSERT AT END
        void insertAtEnd(int data) {
            Node* newNode = new Node(data, NULL, NULL);
            Node* cur = head;

            if(head == NULL) head = newNode;
            else {
                while(cur->next != NULL) cur = cur->next;

                cur->next = newNode;
                newNode->previous = cur;
            }
        }

        //DELETE FIRST NODE
        void deleteAtStart() {
            if(head == NULL) cout << "Doubly Link List is already Empty..." << endl;
            else {
                Node* cur = head;

                head = head->next;
                head->previous = NULL;

                delete cur;
            }
        }

        //DELETE PARTICULAR NODE
        void deleteParticularNode(Node* cur) {
            if(cur == NULL) cout << "Node cannot be NULL";
            else if(cur == head) {
                head = head->next;
                head->previous = NULL;

                delete cur;
            } else {
                cur->previous->next = cur->next;
                cur->next->previous = cur->previous;

                cur->next = cur->previous = NULL;
                delete cur;
            }
        }

        //DELETE PARTICULAR KEY NODE
        void deleteParticularKeyNode(int key) {
            Node* cur = head;

            if(head->data == key) {
                head = head->next;
                head->previous = NULL;

                delete cur;
            } else {
                while(cur->data != key) cur = cur->next;

                cur->previous->next = cur->next;
                cur->next->previous = cur->previous;

                cur->next = cur->previous = NULL;
                delete cur;
            }
        }

        //DELETE AT INDEX
        void deleteAtIndex(int index) {
            Node* cur = head;

            if(index < 0) cout << "Invalid Index..." << endl;
            else if(index == 0) {
                head = head->next;
                head->previous = NULL;

                delete cur;
            } else {
                int i = 0;

                while(i < index-1) {
                    cur = cur->next;
                    i++;
                }

                Node* temp = cur->next;

                cur->next = temp->next;

                if(temp->next != NULL) temp->next->previous = cur;

                delete temp;
            }
        }

        //DELETE LAST NODE
        void deleteAtEnd() {
            if(head == NULL) cout << "Doubly Link List is already Empty..." << endl;
            else if(head->next == NULL) {
                delete head;
                head = NULL;
            } else {
                Node* cur = head;

                while(cur->next != NULL) {
                    cur = cur->next;
                }

                cur->previous->next = NULL;
                
                delete cur;
            }
        }

        //DISPLAY FORWARD
        void displayForward() {
            if(head == NULL) cout << "Doubly Link List is Empty..." << endl;
            else {
                Node* cur = head;

                cout << "\nDoubly LinkList:: ";
                while(cur != NULL) {
                    cout << "\t" << cur->data;
                    cur = cur->next;
                }
            }
        }

        //DISPLAY BACKWARD
        void displayBackward() {
            if(head == NULL) cout << "Doubly Link List is Empty..." << endl;
            else {
                Node* cur = head;

                while(cur->next != NULL) cur = cur->next;

                cout << "\nDoubly LinkList:: ";

                while(cur != NULL) {
                    cout << "\t" << cur->data;
                    cur = cur->previous;
                }
            }
        }
};


int main() {
    LinkedList l1;

    cout << l1.isEmpty() << endl;

    l1.insertAtStart(2);
    l1.insertAtEnd(6);
    l1.insertAtIndex(3, 1);
    l1.insertAtEnd(7);
    l1.insertAtStart(1);
    l1.insertAtIndex(4, 3);
    l1.insertAtIndex(5, 4);

    cout << "\tBefore Deletion\n\n";

    cout << "Forward Display";
    l1.displayForward();

    cout << "\n\nBackward Display";
    l1.displayBackward();

    l1.deleteAtStart();
    l1.deleteAtEnd();
    l1.deleteParticularKeyNode(3);
    l1.deleteAtIndex(3);

    cout << "\n\tAfter Deletion\n\n";

    cout << "Forward Display";
    l1.displayForward();

    cout << "\n\nBackward Display";
    l1.displayBackward();

    return 0;
}