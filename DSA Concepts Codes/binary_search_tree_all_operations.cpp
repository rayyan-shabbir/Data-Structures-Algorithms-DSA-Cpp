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

        // Searching in BST
        bool search(int key) {
            if(isEmpty()) {
                cout << "Binary Search Tree is Empty" << endl;
                return -1;
            }

            Node* curNode = root;

            while(curNode != NULL) {
                if(curNode->data == key) {
                    cout << "Element exists in BST" << endl;
                    return true;
                } else if(key < curNode->data) {
                    curNode = curNode->left;
                } else {
                    curNode = curNode->right;
                }
            }

            cout << "Element not exists in BST" << endl;
            return false;
        }

        // Case - 1 for Node removal
        void nodeRemovalCase1(Node* curNode, Node* preNode) {
            if(preNode->left == curNode) preNode->left = NULL;
            else if(preNode->right == curNode) preNode->right = NULL;

            delete curNode;
        }

        // Case - 2 for Node removal
        void nodeRemovalCase2(Node* curNode, Node* preNode) {
            Node* temp = NULL;

            if(curNode->left != NULL) temp = curNode->left;
            else temp = curNode->right;

            if(preNode->left == curNode) preNode->left = temp;
            else if(preNode->right == curNode) preNode->right = temp;

            delete curNode;
        }

        // Node Removal General
        void nodeRemoval(int key) {
            if(isEmpty()) {
                cout << "Binary Search Tree is Empty" << endl;
                return ;
            }

            bool flag = false;
            Node* curNode = root;
            Node* preNode = NULL;

            while(curNode != NULL) {

                if(curNode->data == key) {
                    flag = true;
                    cout << "Node exists in BST" << endl;

                    if(curNode->left == NULL && curNode->right == NULL) 
                    {
                        cout << "Case 1" << endl;
                        nodeRemovalCase1(curNode, preNode);
                    } 
                    else if(curNode->left != NULL && curNode->right != NULL) 
                    {
                        cout << "Case 3" << endl;
                        Node* temp = curNode->right;
                        Node* tempParent = curNode;

                        while(temp->left != NULL) {
                            tempParent = temp;

                            temp = temp->left;
                        }

                        curNode->data = temp->data;

                        if(temp->left == NULL && temp->right == NULL) nodeRemovalCase1(temp, tempParent);
                        else nodeRemovalCase2(temp, tempParent);
                    } 
                    else if(curNode->left != NULL || curNode->right != NULL) 
                    {
                        cout << "Case 2" << endl;
                        nodeRemovalCase2(curNode, preNode);
                    }
                    break;
                }

                preNode = curNode;

                if (key < curNode->data)
                {
                    curNode = curNode->left;
                } 
                else 
                {
                    curNode = curNode->right;
                }
            }

            if(!flag) cout << "Node to remove does not exists in BST" << endl;
        }

        // public function use to initiate the In-Order-Traversal
        void inOrderTraversal() 
        {
            if(root == NULL) {
                cout << "Binary Search Tree is Empty" << endl;
            } else {
                inOrderTraversal(root);         // calling the working horse
            }
        }

        // public function use to initiate the Pre-Order-Traversal
        void preOrderTraversal() 
        {
            if(root == NULL) {
                cout << "Binary Search Tree is Empty" << endl;
            } else {
                preOrderTraversal(root);        // calling the working horse
            }
        }

        // public function use to initiate the Post-Order-Traversal
        void postOrderTraversal() 
        {
            if(root == NULL) {
                cout << "Binary Search Tree is Empty" << endl;
            } else {
                postOrderTraversal(root);       // calling the working horse
            }
        }
};

int main() {
    Tree obj;

    cout << obj.isEmpty() << endl;

    // obj.insert(6);
    // obj.insert(2);
    // obj.insert(1);
    // obj.insert(4);
    // obj.insert(3);
    // obj.insert(8);

    // CASE - 1
    // obj.insert(6);
    // obj.insert(2);
    // obj.insert(8);
    // obj.insert(0);
    // obj.insert(4);
    // obj.insert(7);
    // obj.insert(9);
    // obj.insert(3);
    // obj.insert(5);

    // CASE - 2
    // obj.insert(6);
    // obj.insert(1);
    // obj.insert(8);
    // obj.insert(7);
    // obj.insert(9);
    // obj.insert(3);
    // obj.insert(2);
    // obj.insert(4);

    // CASE - 3 (Using Case - 1)
    // obj.insert(4);
    // obj.insert(2);
    // obj.insert(6);
    // obj.insert(1);
    // obj.insert(3);
    // obj.insert(5);
    // obj.insert(8);
    // obj.insert(7);
    // obj.insert(9);

    // CASE - 3 (Using Case - 2)
    // obj.insert(3);
    // obj.insert(1);
    // obj.insert(5);
    // obj.insert(4);
    // obj.insert(8);
    // obj.insert(6);
    // obj.insert(9);
    // obj.insert(7);

    obj.insert(1);
    obj.insert(2);
    obj.insert(5);
    obj.insert(7);
    obj.insert(3);
    obj.insert(0);
    // obj.insert(9);
    // obj.insert(7);


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

    // Searching
    // cout << obj.search(10) << endl;

    // Node Removal Case - 1
    // obj.nodeRemoval(5);

    // Node Removal Case - 2
    // obj.nodeRemoval(1);

    // Node Removal Case - 3 (Using Case - 1)
    // obj.nodeRemoval(6);

    // Node Removal Case - 3 (Using Case - 2)
    obj.nodeRemoval(5);

    cout << "In Order Traversal: ";
    obj.inOrderTraversal();
    cout << endl;

    cout << "Pre Order Traversal: ";
    obj.preOrderTraversal();
    cout << endl;

    cout << "Post Order Traversal: ";
    obj.postOrderTraversal();
    cout << endl;

    // Case - 1 (After deleteing, checking if element exists)
    // cout << obj.search(5) << endl;

    // Case - 2 (After deleteing, checking if element exists)
    // cout << obj.search(1) << endl;

    // Case - 3 (--> Case - 1) (After deleteing, checking if element exists)
    // cout << obj.search(6) << endl;

    // Case - 3 (--> Case - 2) (After deleteing, checking if element exists)
    // cout << obj.search(5) << endl;
    return 0;
}

