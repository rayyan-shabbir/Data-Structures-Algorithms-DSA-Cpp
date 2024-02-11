#include "iostream"
using namespace std;

class Node {
    int row;
    int column;
    int value;
    Node* next;

    public:
        //PARAMETRIZE CONSTRUCTOR
        Node(int row, int column, int value, Node* next) {
            this->row = row;
            this->column = column;
            this->value = value;
            this->next = next;
        }

        //NODE CLASS BECAMES PUBLIC TO SPARSE
        friend class Sparse; 
};

class Sparse {
    Node* head;

    public:
        //DEFAULT CONSTRUCTOR
        Sparse() {
            head = NULL;
        }

        //DESTRUCTOR
        ~Sparse() {
            Node* cur = head;

            while(cur != NULL) {
                head = head->next;
                delete cur;
                cur = head;
            }

            delete head;
        }

        //IS EMPTY
        bool isEmpty() {
            return !head;
        }
        
        //INSERTING NON ZERO VALUE OF SPARSE IN LINKED LIST
        void insertVal(int row, int col, int data) {
            Node* newNode = new Node(row, col, data, NULL);

            if(head == NULL) head = newNode;
            else {
                Node* cur = head;

                while(cur->next != NULL) cur = cur->next;

                cur->next = newNode;
            }
        }

        //PRINTING LINKED REPRESENTATION SPARSE
        void printLinkedSparse() {
            if(head == NULL) cout << "SPARSE MATRIX IS EMPTY" << endl;
            else {
                Node* cur = head;

                cout << "\nLinked List Sparse:\n";
                while(cur != NULL) {
                    cout << cur->row << " " << cur->column << " " << cur->value;
                    cout << endl;

                    cur = cur->next;
                }
            }
        }

        //PRINT VALUES USING LINKED SPARSE
        void printValuesUsingLinkedListSparse() {
           if(head == NULL) cout << "SPARSE MATRIX IS EMPTY" << endl;
            else {
                Node* cur = head->next;

                cout << "\nLinked List Sparse:\n";
                while(cur != NULL) {
                    cout << cur->value;
                    cout << endl;  

                    cur = cur->next;
                }
            }
        }

        //PRINT SPARSE MATRIX USING LINKED LIST
        void printSparseUsingLinkedList() {
            if(head == NULL) cout << "No Sparse Matrix Available..." << endl;
            else {
                Node* cur = head->next;

                int rows = head->row;
                int columns = head->column;

                cout << "\nrows: " << rows << " columns: " << columns << endl;

                for(int i = 0; i < rows; i++) {
                    for(int j = 0; j < columns; j++) {
                        if(cur->row == i && cur->column == j) {
                            cout << cur->value << " ";

                            if(cur->next != NULL)
                                cur = cur->next;
                        } else {
                            cout << "0 ";
                        }
                    }
                    cout << endl;
                }
            }
        }
};

//PRINTING SPARSE MATRIX
void printSparse(int A[][6], int rows, int cols) {
    cout << "\nSparse Matrix:\n";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    Sparse s1;
    int A[5][6] = {{6, 0, 3, 0, 0, 0},
                   {0, 0, 0, 0, 9, 0},
                   {0, 7, 0, 0, 0, 4},
                   {0, 0, 0, 2, 0, 0},
                   {8, 0, 0, 0, 0, 0}};

    printSparse(A, 5, 6);

    s1.insertVal(5, 6, 7);

    // s1.printLinkedSparse();

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 6; j++) {
            if(A[i][j] != 0) s1.insertVal(i, j, A[i][j]);
        }
    }

    s1.printSparseUsingLinkedList();

    s1.printLinkedSparse();

    // s1.printValuesUsingLinkedListSparse();


    return 0;
}