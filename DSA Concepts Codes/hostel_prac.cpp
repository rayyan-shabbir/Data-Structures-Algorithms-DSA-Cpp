#include "iostream"
using namespace std;


// Node (element) of Tree
class Node {
    int data;       // holds data
    Node* left;     // holds reference of left sub-tree
    Node* right;    // holds reference of right sub-tree

    public:
        // Constructor
        Node(int data, Node* left, Node* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }

        friend class Tree;      // Members of Node becomes public to Tree class 
};

// Binary Search Tree (BST)
class Tree {
    Node* root;     // holds the reference to root of tree

    // Working host to perform inOrder traversal of a tree
    void inOrderTraversal(Node* root) {
        // left - root - right

        if (root != NULL)                       // until all nodes are traversed
        {
            inOrderTraversal(root->left);       // traverse left-sub tree
            cout << root->data << " ";          // visit the node and perform the desrie task
            inOrderTraversal(root->right);      // traverse right sub-tree
        }
    }

    // Working host to perform preOrder traversal of a tree
    void preOrderTraversal(Node* root) {
        // root - left - right

        if(root != NULL)                        // until all nodes are traversed
        {
            cout << root->data << " ";          // visit the node and perform the desrie task
            preOrderTraversal(root->left);      // traverse left-sub tree
            preOrderTraversal(root->right);     // traverse right sub-tree
        }
    }

    // Working host to perform postOrder traversal of a tree
    void postOrderTraversal(Node* root) {
        // left - right - root

        if(root != NULL)                        // until all nodes are traversed
        {
            postOrderTraversal(root->left);     // traverse left-sub tree
            postOrderTraversal(root->right);    // traverse right sub-tree
            cout << root->data << " ";          // visit the node and perform the desrie task
        }
    }

    public:
        // Constructor
        Tree() {
            root = NULL;
        }

        // isEmpty Method
        bool isEmpty() {
            return !root;
        }

        // Insert data / Building BST
        void insert(int data) {
            // Create a new tree Node
            Node* newNode = new Node(data, NULL, NULL);

            Node* curNode = root;       // curNode points to root 
            Node* preNode = NULL;       // There is no predecessor of root

            while(curNode != NULL) {    // iterate till NULL
                preNode = curNode;

                if(data < curNode->data) {      // new Node is less than from curNode
                    curNode = curNode->left;    // move towards left sub-tree
                } else {
                    curNode = curNode->right;   // move towards right sub-tree
                }
            }

            if(preNode == NULL) {                       // first Node
                root = newNode;
            } else if (preNode->data > data) {          // new Node is less than from its predecessor
                preNode->left = newNode;
            } else {
                preNode->right = newNode;               // new Node is greater than from its predecessor
            }
        }

        

        // public function use to initiate the In-Order-Traversal
        void inOrderTraversal() 
        {
            inOrderTraversal(root);         // calling the working horse
        }

        // public function use to initiate the Pre-Order-Traversal
        void preOrderTraversal() 
        {
            preOrderTraversal(root);        // calling the working horse
        }

        // public function use to initiate the Post-Order-Traversal
        void postOrderTraversal() 
        {
            postOrderTraversal(root);       // calling the working horse
        }
};

int main() {
    Tree obj;

    cout << obj.isEmpty() << endl;

    obj.insert(6);
    obj.insert(2);
    obj.insert(1);
    obj.insert(4);
    obj.insert(3);
    obj.insert(8);

    cout << obj.isEmpty() << endl;

    cout << "In Order Traversal: ";
    obj.inOrderTraversal();
    cout << endl;

    cout << "Pre Order Traversal: ";
    obj.preOrderTraversal();
    cout << endl;

    cout << "Post Order Traversal: ";
    obj.postOrderTraversal();
    cout << endl;

    return 0;
}

