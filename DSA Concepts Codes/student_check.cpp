#include "iostream"

using namespace std;
class Matrix
{
    int row;
    int col;
    int *p;

public:
    Matrix(int r, int cl)
    {

        row = r;
        col = cl;
        int size = row * col;
        p = new int[size];

        for (int i = 0; i < size; i++)
        {
            p[i] = 0;
        }
    }

    int get(int i, int j)
    {

        if (i >= 0 && i < row)
        {

            if (j >= 0 && j < col)
            {

                int index = (i * col) + j;
                return p[index];
            }
        }
    }

    void set(int i, int j, int v)
    {

        if (i >= 0 && i < row)
        {

            if (j >= 0 && j < col)
            {

                int index = ((i)*col) + j;

                p[index] = v;
            }
        }
    }
    void print(void)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int s = (i * col) + j;
                cout << p[s] << "";
            }
            cout << endl;
        }
    }
    void transpose(void)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int s = (j * col) + i;
                cout << p[s] << endl;
            }
        }
    }
    void makeEmpty(int n)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int s = (j * col) + i;
                p[s] = 0;
            }
        }
    }
    void printSubMatrix(int r1, int r2, int c1, int c2)
    {
        for (int i = r1; i < r2; i++)
        {
            for (int j = c1; j < c2; j++)
            {

                int s = (i * col) + j;
                cout << p[s] << endl;
            }
        }
    }

    void add(Matrix first, Matrix second)
    {
        if ((first.row == second.row) && (first.col == second.col))
        {
            delete[] p;

            this->row = first.row;
            this->col = first.col;

            p = new int[row * col];

            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    this->p[i * col + j] = first.p[i * col + j] + second.p[i * col + j];
        }
        else
        {
            cout << "the addtion cannot perfome due to difference in row and col" << endl;
        }
    }

    // void add(Matrix f, Matrix S)
    // {

    //     if (f.row == S.row && f.col == S.col)
    //     {
    //         delete[] p;

    //         this->row = f.row;
    //         this->col = f.col;

    //         p = new int[row * col];
    //         for (int i = 0; i < row; i++)
    //         {
    //             for (int j = 0; j < col; j++)
    //             {
    //                 int s = (i * col) + j;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         cout << "the addtion cannot perfome due to difference in row and col" << endl;
    //     }
    // }

    ~Matrix()
    {
        if (p == NULL)
            delete[] p;
    }
};

int main()
{

    Matrix obj(2, 2);

    obj.set(0, 1, 5);

    obj.print();
    cout << "after transpose" << endl;
    obj.transpose();
    // obj.printSubMatrix(0, 2, 0, 2);
    // obj.makeEmpty(2);
    // obj.print();
    // Matrix obj2(2,2);
    // Matrix obj3(2, 2);

    /*obj3.add(obj, obj2);
    obj3.print();*/
    return 0;
}