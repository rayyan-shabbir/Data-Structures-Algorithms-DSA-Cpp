#include "iostream"
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    friend class LinkedList;
};


class LinkedList {
    Node *head;

public:
    // CONSTRUCTOR
    LinkedList()
    {
        head = NULL;
    }

    // DESTRUCTOR
    ~LinkedList()
    {
        Node *cur = head;

        while (cur != NULL)
        {
            head = head->next;
            delete cur;
            cur = head;
        }

        head = NULL;
    }

    //IS EMPTY
    bool isEmpty() {
        return !head;
    }

    // INSERT AT START
    void insertAtStart(int data) {
        Node *newNode = new Node(data, NULL);

        newNode->next = head;
        head = newNode;
    }

    // INSERT AT LAST
    void insertAtLast(int data)
    {
        Node *newNode = new Node(data, NULL);

        if (head == NULL)
            head = newNode;
        else
        {
            Node *cur = head;
            while (cur->next != NULL)
                cur = cur->next;

            cur->next = newNode;
        }
    }
    // INSERT AFTER KEY
    void inserAfterKey(int data, int key)
    {
        if (head == NULL)
            cout << "Linklist is Empty..." << endl;
        else
        {
            Node *newNode = new Node(data, NULL);
            Node *cur = head;

            while (cur != NULL && cur->data != key)
                cur = cur->next;

            if (cur != NULL)
            {
                newNode->next = cur->next;
                cur->next = newNode;
            }
            else
            {
                cout << "Key Element Not exists" << endl;
            }
        }
    }
    
    // INSERT BEFORE KEY
    void insertBeforeKey(int data, int key)
    {
        if (head == NULL) cout << "LinkList is Empty..." << endl;
        else
        {
            Node *newNode = new Node(data, NULL);
            Node *prv = head;
            Node *cur = head->next;

            if (prv->data == key) {
                newNode->next = head;
                head = newNode;
            } else {
                while (cur != NULL && cur->data != key) {
                    prv = cur;
                    cur = cur->next;
                }

                if (cur != NULL) {
                    newNode->next = cur;
                    prv->next = newNode;
                } else
                    cout << "Key Element Not exists" << endl;
            }
        }
    }

    //INSERT AFTER NODE
    void insertAfterNode(int data, Node* prevNode) {
        if(prevNode == NULL) cout << "PrevNode cannot be Empty..." << endl;
        else {
            Node* newNode = new Node(data, NULL);
            
            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }
    }

    //INSERT BEFORE NODE
    void insertBeforeNode(int data, Node* curNode) {
        if(curNode == NULL) cout << "CurNode cannot be Empty..." << endl;
        else {
            Node* newNode = new Node(data, NULL);
            Node* temp = head;

            while(temp->next != curNode) {
                temp = temp->next;
            }

            newNode->next = curNode;
            temp->next = newNode;
        }
    }

    //INSERT AT INDEX
    void insertAtIndex(int data, int index) {
        Node *newNode = new Node(data, NULL);
        if(index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            int i = 0;
            Node* cur = head;

            while(i != index-1) {
                cur = cur->next;
                i++;
            }

            newNode->next = cur->next;
            cur->next = newNode;
        }
    }

    //DELETE FIRST NODE
    void deleteFirstNode() {
        if(head == NULL) cout << "List is Empty" << endl;
        else {
            Node* cur = head;

            head = head->next;
            delete cur;
            cur = NULL;
        }
    }

    //DELETE PARTICULAR NODE OF GIVEN KEY
    void deleteParticularKeyNode(int key) {
        if(head == NULL) cout << "Empty List" << endl;
        else {
            Node* cur = head;
            Node* prv = NULL;

            while(cur->data != key && cur != NULL) {
                prv = cur;
                cur = cur->next;
            }

            if(cur != NULL) {
                prv->next = cur->next;
                delete cur;
            } else {
                cout << "Key Not Found" << endl;
            }
        }
    }

    //DELETE PARTICULAR NODE
    void deleteParticularNode(Node* node) {
        if(head == NULL) cout << "Empty List" << endl;
        else if(node == NULL) cout << "Node cannot be NULL" << endl;
        else {
            if(head == node) {
                head = head->next;
                delete head;
                head = NULL;
            } else {
                Node* cur = head;
                while(cur->next != node) {
                    cur = cur->next;
                }

                cur->next = node->next;
                delete node;
            }
        }
    }

    //DELETE AFTER GIVEN NODE
    void deleteAfterNode(Node* prv) {
        if(prv == NULL) cout << "Node cannot be Empty" << endl;
        else {
            Node* cur = prv->next;

            prv->next = cur->next;
            delete cur;
        }
    }

    //DELETE BEFORE GIVEN NODE
    void deleteBeforeNode(Node* cur) {
        if(cur == NULL) cout << "Node cannot be NULL" << endl;
        else if(head == cur) cout << "There is Nothing before Given Node";
        else if(head->next == cur) {
            Node* temp = head;
            head = cur;

            delete temp;
        }
        else {
            Node* prv = head;
            Node* temp = head->next; 

            while(temp->next != cur) {
                prv = temp;
                temp = temp->next;
            }

            prv->next = cur;
            delete temp;
        }
    }

    //DELETE AT INDEX
    void deleteAtIndex(int index) {
        Node* cur = head;

        if(index == 0) {
            head = head->next;
            delete cur;
        } else {
            int i = 0;
            Node* prv = head;
            Node* cur = head->next;

            while(i != index-1) {
                prv = cur;
                cur = cur->next;
                i++;
            }

            prv->next = cur->next;
            delete cur;
            cur = NULL;
        }
    }

    //DELETE LAST NODE
    void deleteLastNode() {
        if(head == NULL) cout << "Empty List" << endl;
        else if(head->next == NULL) {
                delete head;
                head = NULL;
        } else {
            Node* prv = head;
            Node* cur = head->next;

            while(cur->next != NULL) {
                prv = cur;
                cur = cur->next;
            }

            prv->next = NULL;
            delete cur;
        }
    }

    //SEARCH KEY IN LINKLIST
    Node* search(int key) {
        if(head == NULL) cout << "Empty List" << endl;
        else {
            Node* cur = head;

            while(cur != NULL) {
                if(cur->data == key)
                    return cur;
                
                cur = cur->next;
            }
            return NULL;
        }
    }

    //UPDATE DATA OF NODE
    void update(int value, int key) {
        if(head == NULL) cout << "Empty List" << endl;
        else {
            Node* cur = head;

            while(cur != NULL) {
                if(cur->data == key)
                    cur->data = value;
                
                cur = cur->next;
            }
        }
    }

    //TO DISPLAY DATA OF LINKLIST
    void display() {
        if(head == NULL) cout << "LinkList is Empty" << endl;
        else {
            Node* curNode = head;

            cout << "List: ";
            while(curNode != NULL) {
                cout << "\t" << curNode->data;

                curNode = curNode->next;
            }
        }
    }

};

int main() {
    LinkedList l1;

    //cout << endl << l1.isEmpty() << endl;

    l1.insertAtStart(1);
    l1.insertAtIndex(2, 1);
    l1.insertAtIndex(3, 2);
    l1.insertAtIndex(4, 3);
    l1.insertAtIndex(5, 4);
    l1.insertAtIndex(6, 5);
    l1.insertAtIndex(7, 6);
    l1.insertAtIndex(8, 7);
    l1.insertAtLast(9);

    cout << "***LinkList before deletion***" << endl;
    l1.display();

    l1.deleteFirstNode();
    l1.deleteLastNode();
    l1.deleteParticularKeyNode(3);
    l1.deleteAtIndex(2);
    l1.deleteParticularKeyNode(7);

    cout << "\n***LinkList after deletion***" << endl;
    l1.display();

    // //cout << endl << l1.isEmpty() << endl;
    return 0;
}