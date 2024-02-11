#include "iostream"
using namespace std;

int countNonZeroValues(int A[][4], int rows, int cols) {
    int count = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(A[i][j] != 0) count++;
        }
    }

    return count;
}


void printValuesUsingTriplet(int** S, int rows, int cols) {
    int sr = S[0][2];

    cout << "\nValues: \n";
    for(int i = 1; i <= sr; i++)
        cout << S[i][2] << endl;
}


void printTripletRepresentation(int** S, int rows) {
    cout << "\nTriplet Representation\n";

    for(int i = 0; i < rows; i++) {
        cout << S[i][0] << " " << S[i][1] << " " << S[i][2] << endl;
    }
    cout << endl;
}


void copyingArray(int** A, int Arow, int** R, int Krow) {
    // cout << "Krow: " << Krow << endl;
    R[0][0] = A[0][0];
    R[0][1] = A[0][1];
    R[0][2] = Krow-1;

    int k = 1;
    for(int i = 1; i < Krow; i++) {
        R[i][0] = A[k][0];
        R[i][1] = A[k][1];
        R[i][2] = A[k][2];

        k++;
    }
}


void addSparseMatrices(int S1[][3], int S2[][3]) {
    if(S1[0][0] != S2[0][0] || S1[0][1] != S2[0][1]) {
        cout << "Order Does Not Match. So Addition is Impossible..." << endl;
        return;
    }

    int temp_rows = S1[0][2] + S2[0][2];
    int** A = new int*[temp_rows+1];

    for(int i = 0; i < (temp_rows+1); i++)
        A[i] = new int[3];
    
    A[0][0] = S1[0][0];
    A[0][1] = S1[0][1];
    A[0][2] = temp_rows;

    //cout << A[0][0] << " " << A[0][1] << " " << A[0][2] << endl;
    //cout << temp_rows;

    int i = 1, j = 1, k = 1;

    while(i <= S1[0][2] && j <= S2[0][2]) {
        if(S1[i][0] == S2[j][0] && S1[i][1] == S2[j][1]) {
            A[k][0] = S1[i][0];
            A[k][1] = S1[i][1];
            A[k][2] = S1[i][2] + S2[j][2];

            i++, j++, k++;
        } else if(S1[i][0] == S2[j][0] && S1[i][1] != S2[j][1]) {
            if(S1[i][1] < S2[j][1]) {
                A[k][0] = S1[i][0];
                A[k][1] = S1[i][1];
                A[k][2] = S1[i][2];

                i++, k++;
            } else {
                A[k][0] = S2[j][0];
                A[k][1] = S2[j][1];
                A[k][2] = S2[j][2];

                j++, k++;
            }
        } else if(S1[i][0] != S2[j][0]) {
            if(S1[i][0] < S2[j][0]) {
                A[k][0] = S1[i][0];
                A[k][1] = S1[i][1];
                A[k][2] = S1[i][2];

                i++, k++;
            } else {
                A[k][0] = S2[j][0];
                A[k][1] = S2[j][1];
                A[k][2] = S2[j][2];

                j++, k++;
            }
        }
    }

    while(i <= S1[0][2]) {
        A[k][0] = S1[i][0];
        A[k][1] = S1[i][1];
        A[k][2] = S1[i][2];

        i++, k++;
    }

    while(j <= S2[0][2]) {
        A[k][0] = S2[j][0];
        A[k][1] = S2[j][1];
        A[k][2] = S2[j][2];

        j++, k++;
    }

    int** R = new int*[k+1];
    for(int i = 0; i < (k+1); i++)
        R[i] = new int[3];

    // cout << "K: " << k << endl;

    copyingArray(A, temp_rows+1, R, k);
    
    printTripletRepresentation(R, k);
}


void printSparseUsingTriplet(int** S, int rows, int cols) {
    int sR = S[0][0];
    int sC = S[0][1];

    int k = 1;

    for(int i = 0; i < sR; i++) {
        for(int j = 0; j < sC; j++) {
            if(S[k][0] == i && S[k][1] == j) {
                cout << S[k][2] << " ";
                k++;
            } else 
                cout << "0 ";
        }
        cout << endl;
    }
}


void tripletRepresentation(int A[][4], int rows, int cols) {
    int r = countNonZeroValues(A, rows, cols);

    // cout << r;

    int m = (r+1);

    int** S = new int*[m];
    for(int i = 0; i < m; ++i) S[i] = new int[3];

    S[0][0] = rows;
    S[0][1] = cols;
    S[0][2] = r;

    int k = 1;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(A[i][j] != 0) {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = A[i][j];
                k++;
            }
        }
    }

    printTripletRepresentation(S, m);

    // printValuesUsingTriplet(S, 3, 3);

    printSparseUsingTriplet(S, m, 3);
}


void printSparseMatrix(int A[][4], int rows, int cols) {
    cout << "\nSparse Matrix: \n";

    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int A[5][6] = {{6, 0, 3, 0, 0, 0},
                   {0, 0, 0, 0, 9, 0},
                   {0, 7, 0, 0, 0, 4},
                   {0, 0, 0, 2, 0, 0},
                   {8, 0, 0, 0, 0, 0}};


    int B[3][4] = {{0, 2, 0, 0},
                   {5, 0, 3, 0},
                   {0, 7, 0, 4}};

    int C[3][4] = {{0, 3, 0, 0},
                   {4, 0, 0, 6},
                   {0, 2, 1, 5}};

    int S1[6][3] = {{3, 4, 5},
                    {0, 1, 2},
                    {1, 0, 5},
                    {1, 2, 3},
                    {2, 1, 7},
                    {2, 3, 4}};

    int S2[7][3] = {{3, 4, 6},
                    {0, 1, 3},
                    {1, 0, 4},
                    {1, 3, 6},
                    {2, 1, 2},
                    {2, 2, 1},
                    {2, 3, 5}};

    // printSparseMatrix(A, 5, 6);           
    // printSparseMatrix(B, 3, 4);           
    // printSparseMatrix(C, 3, 4);

    // tripletRepresentation(A, 5, 6);
    // tripletRepresentation(B, 3, 4);
    tripletRepresentation(C, 3, 4);

    // addSparseMatrices(S1, S2);

    
    return 0;
}