#include "iostream"
using namespace std;

class Matrix {
    private:
        int *array;
        int rows;
        int columns;
    public: 
        //CONSTRUCTOR
        Matrix(int rows, int columns) {
            this->rows = rows;
            this->columns = columns;

            array = new int[rows*columns];

            for (int i = 0; i < rows; i++)
                for (int j = 0; j < columns; j++)
                    array[i*columns + j] = 0;
        }

        ~Matrix() {
            if(array == NULL)
                delete[] array;
        }

        //METHODS
        int get(int i, int j) {
            if((i >= 0 && i < rows) && (j >= 0 && j < columns)) {
                int ind = i*columns + j;
                return array[ind];
            }

            cout << "INDICES ARE OUT OF BOUND..." << endl;
            exit(0);
        }

        void set(int i, int j, int v) {
            if((i >= 0 && i < rows) && (j  >= 0 && j < columns)) {
                int ind = i*columns + j;

                array[ind] = v;
            } else {
                cout << "INDICES ARE OUT OF BOUND..." << endl;
            }
        }

        void print(void) {
            cout << "Array[" << rows << "][" << columns << "]" << endl;
            cout << "***Matrix***" << endl;

            for (int i = 0; i < rows; i++) {
                cout << "| ";
                for (int j = 0; j < columns; j++) {
                    cout << array[i*columns + j] << "  ";
                }
                cout << "|" << endl;
            }
        }

        void transpose(void) {
            int *trans;
            int r = columns;
            int c = rows;
            trans = new int[rows*columns];

            for (int i = 0; i < rows; i++)
                for (int j = 0; j < columns; j++) trans[j*rows + i] = array[i*columns + j];

            rows = r;
            columns = c;

            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++) array[i*c+j] = trans[i*c+j];

            delete[] trans;
        }

        void printSubMatrix(int r1, int r2, int c1, int c2) {
            if((r1 >= 0 && r2 < rows) && (c1 >= 0 && c2 < columns)) {
                for (int i = r1; i <= r2; i++) {
                    cout << "| ";
                    for (int j = c1; j <= c2; j++)
                            cout << array[(i * columns + j)] << "  ";
                    cout << "|" << endl;
                }
            }
        }


        // void printSubMatrix(int r1, int r2, int c1, int c2) {
        //     int k = 0;
        //     int ro = (r2-r1)+1;
        //     int co = (c2-c1)+1;

        //     int *subMat;
        //     subMat = new int[ro*co];

        //     for (int i = r1; i <= r2; i++)
        //         for (int j = c1; j <= c2; j++) {
        //             subMat[k] = array[i*columns+j];
        //             k++;
        //         }

        //     for (int i = 0; i < ro; i++) {
        //         cout << "| ";
        //         for (int j = 0; j < co; j++)
        //                 cout << subMat[i*co + j] << "  ";
        //         cout << "|" << endl;
        //     }
        // }

        void makeEmpty(int n) {
            if(n >=0 && n <= rows) {
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < columns; j++)
                        array[i*columns + j] = 0;
            } else {
                cout << "Passed 'N' rows does not exists in a matrix...";
            }
        }

        void add(Matrix first, Matrix second) {
            if((first.rows == second.rows) && (first.columns == second.columns)) {
                this->rows = first.rows;
                this->columns = first.columns;
                
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < columns; j++)
                        this->array[i*columns+j] = first.array[i*columns+j] + second.array[i*columns + j];

            } else {
                cout << "\nERROR *** Sizes of 'First' and 'Second' Matrices are not equal.\nSo, addition is not possible..." << endl << endl;
            }
        }
};


int main() {
    Matrix rdx1(4, 3), rdx2(2, 2), rdx3(2, 2);

    //rdx1.print();

    cout << "****Set Functions are calling for rdx1****" << endl;
    rdx1.set(0, 0, 1);
    rdx1.set(0, 1, 2);
    rdx1.set(0, 2, 3);
    rdx1.set(1, 0, 4);
    rdx1.set(1, 1, 5);
    rdx1.set(1, 2, 6);
    rdx1.set(2, 0, 7);
    rdx1.set(2, 1, 8);
    rdx1.set(2, 2, 9);
    rdx1.set(3, 0, 10);
    rdx1.set(3, 1, 11);
    rdx1.set(3, 2, 12);

    cout << "****Set Functions are calling for rdx2****" << endl;
    rdx2.set(0, 0, 9);
    rdx2.set(0, 1, 5);
    rdx2.set(1, 0, 7);
    rdx2.set(1, 1, 1);

    cout << "****Set Functions are calling for rdx3****" << endl;
    rdx3.set(0, 0, 2);
    rdx3.set(0, 1, 6);
    rdx3.set(1, 0, 3);
    rdx3.set(1, 1, 18);


    cout << "RDX1" << endl;
    rdx1.print();
    cout << "\nRDX2" << endl;
    rdx2.print();
    cout << "\nRDX3" << endl;
    rdx3.print();

    // cout << "\n****Get Function is calling****" << endl;
    // cout << rdx1.get(1, 2);

    cout << "\n****Transpose Function is calling****" << endl;
    rdx1.transpose();
    rdx1.print();


    // cout << "\n****SubMatrix is calling****" << endl;
    // rdx1.printSubMatrix(0, 3, 1, 2);

    // cout << "\n****MakeEmpty Function is calling****" << endl;
    // rdx1.makeEmpty(2);
    // rdx1.print();

    cout << "\n****ADD Function is calling for rdx1****" << endl;
    rdx1.add(rdx2, rdx3);
    rdx1.print();

    return 0;
}