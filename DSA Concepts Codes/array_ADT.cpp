#include "iostream"
using namespace std;

class Array {
    private:
        int total_size;
        int used_size;
        int *ptr;
    public:
        Array(int t_size, int u_size) {
            total_size = t_size;
            used_size = u_size;

            ptr = new int[total_size];
        }

        void setArray() {
            for (int i = 0; i < used_size; i++)
            {
                cout << "Enter value at index : " << i << ": ";
                cin >> ptr[i];
            }
        }

        int indInsertion(int element, int index) {
            if(used_size >= total_size) {
                return -1;
            }
            //1 2 4 5

            for(int i = used_size-1; i >= index; i--) {
                ptr[i+1] = ptr[i];
            }

            ptr[index] = element;
            used_size++;

            return 1;
        }

        int indDeletion(int index) {
            if(index >= total_size) {
                return -1;
            }

            for(int i = index; i < used_size - 1; i++) {
                ptr[i] = ptr[i+1];
            }

            used_size--;
            return 1;
        }
        
        void display() {
            cout << "Array: ";
            for (int i = 0; i < used_size; i++)
            {
                cout << "\t" << ptr[i];
            }
        }

};

int main() {
    Array marks(10, 5);

    marks.setArray();

    marks.display();

    int i = marks.indInsertion(0, 0);

    if(i == 1) cout << "\nInsertion is done successfully" << endl;
    else cout << "\nInsertion is not done successfully!" << endl;

    marks.display();

    int j = marks.indDeletion(0);

    if(j == 1) cout << "\nDeletion is done successfully" << endl;
    else cout << "\nDeletion is not possible" << endl;

    marks.display();
    return 0;
}