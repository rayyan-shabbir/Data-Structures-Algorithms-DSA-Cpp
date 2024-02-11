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

    l1.insertAtStart(5);
    l1.insertAtStart(1);

    l1.insertAtEnd(9);
    l1.insertAtEnd(11);

    l1.insertAtIndex(3, 1);
    l1.insertAtIndex(7, 3);
    
   

    l1.display();

    //cout << l1.isEmpty() << endl;
    return 0;
}