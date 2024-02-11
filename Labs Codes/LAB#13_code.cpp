#include "iostream"
#include "fstream"
using namespace std;

// Student Class
class Student {
    int stdId;          // student identifier (unique)
    string name;        // student name
    float fee;          // student fee
    Student* left;      // left subtree of a node
    Student* right;     // right subtree of a node

    public:
        // CONSTRUCTOR
        Student(int stdId, string name, float fee, Student* left, Student* right) {
            this->stdId = stdId;
            this->name = name;
            this->fee = fee;
            this->left = left;
            this->right = right;
        }
        
        friend class StudentBST;
};


// Student BST Class
class StudentBST{
    Student* root;          // root of the tree;    

    bool preOrderTraversal(Student* root, int stdId) {
        if(root != NULL) {
            if(root->stdId == stdId) return true;

            preOrderTraversal(root->left, stdId);
            preOrderTraversal(root->right, stdId);
        }

        return false;
    }

    // Working Horse :: Private InOrder Function
    void inOrder(Student* stree) {
        if(stree != NULL) {
            inOrder(stree->left);

            cout << "ID: " << stree->stdId << "\t, Name: " << stree->name << "\t, Fee: " << stree->fee << endl;

            inOrder(stree->right);
        }
    }

    // Working Horse :: Private PreOrder Function
    void preOrder(Student* stree) {
        if(stree != NULL) {            
            cout << "ID: " << stree->stdId << "\t, Name: " << stree->name << "\t, Fee: " << stree->fee << endl;

            preOrder(stree->left);


            preOrder(stree->right);
        }
    }

    // Working Horse :: Private PostOrder Function
    void postOrder(Student* stree) {
        if(stree != NULL) {

            postOrder(stree->left);


            postOrder(stree->right);

            cout << "ID: " << stree->stdId << "\t, Name: " << stree->name << "\t, Fee: " << stree->fee << endl;
        }
    }

    // Destroy Function
    void destroy(Student* stree) {
        if(root != NULL) {
            destroy(stree->left);
            destroy(stree->right);

            delete stree;
        }
    }

    public:
        // CONSTRUCTOR
        StudentBST() {
            root = NULL;
        }

        // DESTRUCTOR
        ~StudentBST() {
            if(root != NULL) {
                destroy(root);
            }
        }

        // Insert Function
        bool insert(int stdId, string name, float balance) {
            Student* newNode = new Student(stdId, name, balance, NULL, NULL);

            // cout << stdId << endl;
            bool result = search(stdId);

            // cout << result << endl;

            if(!result) {
                // cout << "Enter if" << endl;
                Student* cur = root;
                Student* pre = NULL;

                while(cur != NULL) {
                    pre = cur;

                    if(cur->stdId > stdId) cur = cur->left;
                    else cur = cur->right;
                }

                if(pre == NULL) {
                    root = newNode;
                } else if(pre->stdId > stdId) {
                    pre->left = newNode;
                } else {
                    pre->right = newNode;
                }
                return true;
            } else {
                cout << "Student ID already Exists" << endl << endl;
                return false;
            }
        }


        // Search Function
        bool search(int stdId) {
            Student* cur = root;

            while(cur != NULL) {

                if(cur->stdId == stdId) {
                    cout << "Existing Student Details" << endl;
                    cout << "ID: " << cur->stdId << endl;
                    cout << "Name: " << cur->name << endl;
                    cout << "Fee: " << cur->fee << endl;
                    cout << endl << endl;
                    return true;
                } else if(cur->stdId < stdId)   
                    cur = cur->right;
                  else
                    cur = cur->left;

            }

            return false;  
        }

        // InOrder Traversal
        void inOrder() {
            if(root != NULL) {
                cout << "*** Student Deatils (InOrder)***" << endl;
                inOrder(root);
                cout << endl;
            } else 
                cout << "Student BST is Empty" << endl;
        }

        // PreOrder Traversal
        void preOrder() {
            if(root != NULL) {
                cout << "*** Student Deatils (PreOrder)***" << endl;
                preOrder(root);
                cout << endl;
            } else 
                cout << "Student BST is Empty" << endl;
        }

        // PostOrder Traversal
        void postOrder() {
            if(root != NULL) {
                cout << "*** Student Deatils (PostOrder)***" << endl;
                postOrder(root);
                cout << endl;
            } else 
                cout << "Student BST is Empty" << endl;
        }
};


int main() {
    StudentBST student1;

    // student1.insert(1, "Rayan", 15.50);
    // student1.insert(2, "Ahmed", 399.82);
    // student1.insert(5, "Ashfaq", 0.231);
    // student1.insert(7, "Habeeb", 210.37);
    // student1.insert(3, "Habeeb", 67.90);
    // student1.insert(0, "Adyan", 777.98);

    // student.insert(5, "Danyal", 988.91);

    // student.inOrder();
    // student.preOrder();
    // student.postOrder();

    int id;
    string name;
    float fee;

    StudentBST student2;

    ifstream inf("input.txt", ios::in); 

    if(!inf) {
        cout << "Failed to open the file" << endl;
        exit(0);
    }

    while(!inf.eof()) {
        inf >> id >> name >> fee;

        // cout << id << " " << name << " " << price << endl;

        student2.insert(id, name, fee);
    }

    // student2.inOrder();
    // student2.preOrder();
    // student2.postOrder();



    return 0;
}