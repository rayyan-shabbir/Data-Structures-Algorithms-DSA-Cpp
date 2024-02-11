#include "iostream"
using namespace std;

class LowerTriangularMatrix
{
    int *M;
    int n;

    public:
        LowerTriangularMatrix() {
            this->n = 3;
            M = new int[3*(3+1)/2];

            for (int i = 0; i < n; i++)
                M[i] = 0; 
        }

        LowerTriangularMatrix(int n) {
            this->n = n;
            M = new int[n*(n+1)/2];

            for (int i = 0; i < n; i++)
                M[i] = 0;
        }

        ~LowerTriangularMatrix() {
            delete[] M;
        }

        int getDimenssions() {
            return n;
        }

        void set(int i, int j, int v) {
            if(i >= j) M[i*(i+1)/2 + j] = v;
        }

        int get(int i, int j) {
            if(i >= j) return M[i*(i+1)/2 + j];
        }

        void display() {
            cout << "***Matrix***\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    if(i >= j) cout << M[i*(i+1)/2 + j] << " ";
                    else cout << 0 << " ";
                cout << endl;
            }          
        }
};

int main() {
    int d, v;
    cout << "Enter Dimenssions:: ";
    cin >> d;

    LowerTriangularMatrix LM(d);

    cout << "Enter Elements:: " << endl;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> v;
            LM.set(i, j, v);
        }
    }
    
    LM.display();

    cout << endl << LM.get(2, 2);

    return 0;
}