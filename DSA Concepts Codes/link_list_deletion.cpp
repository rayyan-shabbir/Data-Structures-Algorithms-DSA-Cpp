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

        // ~List() {
        //     Node *ptr = head;

        //     while(ptr != NULL) {
        //         head = ptr->next;
        //         delete ptr;
        //         ptr = head;
        //     }

        //     head = NULL;
        // }

        bool isEmpty() {
            return !head;
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
            }
        }
};

int main() {
    List l1;

    //cout << l1.isEmpty() << endl;

    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    l1.insertAtEnd(6);
    l1.insertAtEnd(7);
    

    l1.deleteFirstNode();   //1 del
    l1.deleteAtEnd();       //7 del

    l1.deleteAtIndex(3);    //5 del

    l1.deleteParticularNode(3);  //3 del

    l1.display();

    //cout << l1.isEmpty() << endl;
    return 0;
}