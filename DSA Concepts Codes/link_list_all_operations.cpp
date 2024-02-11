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

        friend class List;
};

class List {
    private:
        Node *head;
    public:
        List() {
            head = NULL;
        }

        ~List() {
            Node *ptr = head;

            while(ptr != NULL) {
                head = ptr->next;
                delete ptr;
                ptr = head;
            }

            head = NULL;
        }

        bool isEmpty() {
            return !head;
        }

        void insertAtStart(int data) {
            Node *newNode = new Node(data, NULL);

            newNode->next = head;
            head = newNode;
        }

        void insertAfterNode(int data, Node *prevNode) {
            if(prevNode == NULL) {
                cout << "Previous node can not be NULL" << endl;
                return;
            }

            Node *newNode = new Node(data, NULL);

            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }

        void insertAtIndex(int data, int index) {
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

        void insertAtEnd(int data) {
            Node *newNode = new Node(data, NULL);

            if(head == NULL) {
                head = newNode;
            } else {
                Node *curNode = head;

                while(curNode->next != NULL) {
                    curNode = curNode->next;
                }

                curNode->next = newNode;
            }
        }

        void deleteFirstNode() {
            Node *ptr = head;

            head = head->next;
            delete ptr;
            ptr = NULL;
        }

        void deleteParticularNode(int key) {
            Node *prevNode = head;
            Node *curNode = head->next;

            while(curNode->data != key && curNode->next != NULL) {
                prevNode = prevNode->next;
                curNode = curNode->next;
            }

            if(curNode->data == key) {
                prevNode->next = curNode->next;
                delete curNode;
                curNode = NULL;
            } else {
                cout << "Key not found" << endl;
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

        void deleteAtEnd() {
            if(head == NULL) {
                cout << "Linklist is empty" << endl;
            } else {
                if(head->next == NULL) {
                    delete head;
                    head = NULL;
                } else {
                    Node *preNode = head;
                    Node *curNode = head->next;

                    while(curNode->next != NULL) {
                        preNode = preNode->next;
                        curNode = curNode->next;
                    }

                    delete curNode;
                    curNode = NULL;
                    preNode->next = NULL;
                }
            }
        }
        
        void display() {
            if(head == NULL) {
                cout << "LinkList is empty" << endl;
            } else {
                Node *curNode = head;

                cout << "List: ";
                while(curNode != NULL) {
                    cout << "\t" << curNode->data;

                    curNode = curNode->next;
                }

                // OR

                // do {
                //     cout << "\t" << curNode->data;

                //     curNode = curNode->next;
                // } while(curNode != NULL); 
            }
        }
};

int main() {
    List l1;

    //cout << endl << l1.isEmpty() << endl;

    l1.insertAtStart(1);
    l1.insertAtIndex(2, 1);
    l1.insertAtIndex(3, 2);
    l1.insertAtIndex(4, 3);
    l1.insertAtIndex(5, 4);
    l1.insertAtIndex(6, 5);
    l1.insertAtIndex(7, 6);
    l1.insertAtIndex(8, 7);
    l1.insertAtEnd(9);

    cout << "***LinkList before deletion***" << endl;
    l1.display();

    l1.deleteFirstNode();
    l1.deleteAtEnd();
    l1.deleteParticularNode(3);
    l1.deleteAtIndex(2);
    l1.deleteParticularNode(7);

    cout << "\n***LinkList after deletion***" << endl;
    l1.display();

    //cout << endl << l1.isEmpty() << endl;
    return 0;
}