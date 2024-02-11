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

        void insertAfterNode(int data, Node *prevNode) {
            if(prevNode == NULL) {
                cout << "Previous Node can not be NULL" << endl;
                return;
            }

            Node *newNode = new Node(data, NULL);

            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }

       void display(Node *head) {
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
    Node *third = new Node(3, NULL);
    Node *second = new Node(2, third);
    Node *head = new Node(1, second);

    head->insertAfterNode(76, second);

    head->display(head);
    // second->display(head);
    // third->display(head);
    return 0;
}