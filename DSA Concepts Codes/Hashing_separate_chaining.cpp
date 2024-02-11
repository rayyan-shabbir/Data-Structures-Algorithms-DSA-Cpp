#include "iostream"
using namespace std;

class Node {
    int data;
    Node* next;

    public:
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }

        friend class LinkList;
};


class LinkList {
     public:
    Node* head;
    
        LinkList() {
            head = NULL;
        }

        void insertAtEnd(int data) {
            Node* newNode = new Node(data, NULL);

            if(head == NULL) {
                head = newNode;
            } else {
                Node* curNode = head;  

                while(curNode->next != NULL) curNode = curNode->next;

                curNode->next = newNode;
            }
        }

        void print() {
            Node* curNode = head;

            cout << "Data: ";
            while(curNode != NULL) {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            cout << endl;
        }
};

int hashFunction(int size, int val) {
    return val % size;
}

void insert(LinkList* Arr[], int size, int val) {
    int code = hashFunction(size, val);

    if(code == 0) Arr[0]->insertAtEnd(val);
    else if(code == 1) Arr[1]->insertAtEnd(val);
    else if(code == 2) Arr[2]->insertAtEnd(val);
    else if(code == 3) Arr[3]->insertAtEnd(val);
    else if(code == 4) Arr[4]->insertAtEnd(val);
}


int main() {
    LinkList obj1, obj2, obj3, obj4, obj5;
    LinkList* Arr[5] = {&obj1, &obj2, &obj3, &obj4, &obj5};

    insert(Arr, 5, 37);
    insert(Arr, 5, 12);
    insert(Arr, 5, 19);
    insert(Arr, 5, 41);
    insert(Arr, 5, 23);
    insert(Arr, 5, 99);
    insert(Arr, 5, 52);
    insert(Arr, 5, 63);
    insert(Arr, 5, 277);
    insert(Arr, 5, 10);
    insert(Arr, 5, 40);

    // obj1.print();
    // obj2.print();
    // obj3.print();

    for(int i = 0; i < 5; i++)
        Arr[i]->print();
}