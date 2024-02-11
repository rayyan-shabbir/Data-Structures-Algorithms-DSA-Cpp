#include "iostream"
using namespace std;

class Collection {
    private:
        int *data;
        int size; 

    public:
        //CONSTRUCTOR
        Collection(int size) {
            if(size == -1) {
                this->size = -1;
                data = NULL;
            } else {
                this->size = size;
                data = new int[size];

                for (int i = 0; i < size; i++)
                    data[i] = 0;
            }
        }

        Collection(int array[], int size) {
            this->size = size;
            data = new int[size];

            for (int i = 0; i < size; i++)
                if(array[i] > 0) data[i] = array[i];
                else  data[i] = 0;
        }

        //COPY CONSTRUCTOR
        Collection(const Collection &obj) {
            this->size = obj.size;
            data = new int[size];

            for (int i = 0; i < size; i++)
                if(obj.data[i] > 0) data[i] = obj.data[i];
                else data[i] = 0;
        }

        //DESTRUCTOR
        ~Collection() {
            delete[] data;
        }


        //MEMBER FUNCTIONS
        int getSize() {
            return this->size;
        }

        void printCollection() {
            cout << "Data: ";

            for (int i = 0; i < size; i++)
                cout <<  data[i] << " ";
            cout << endl;
        }

        void getCollection() {
            int d = 0;

            for (int i = 0; i < size; i++)
            {
                cout << "Enter Data[" << i << "]: ";
                cin >> d;

                if(d > 0) data[i] = d;
                else data[i] = 0;
            }
        }

        void insertElement(int k, int i) {
            if(i < size && i >= 0) {
                if(k >= 0) data[i] = k;
                else cout << "***ERROR*** The passed integer is negative! So, it cannot be inserts." << endl;
            } else {
                cout << "***ERROR*** The passed index doesnot exist in array size!" << endl;
            }
        }

        bool findElement(int key) {
            for (int i = 0; i < size; i++)
                if(key == data[i]) return true;
            
            return false;
        }
        
        Collection operator=(const Collection &obj) {
            if(this != &obj) {
                if(size != obj.size) {
                    delete[] data;
                    size = obj.size;

                    data = new int[size];
                }
                for (int i = 0; i < size; i++) data[i] = obj.data[i];
            }

            return *this;
        }


        Collection operator+(const Collection &obj) const
        {
            Collection temp(size);

            if(obj.size == size) {
                for (int i = 0; i < size; i++)
                    temp.data[i] = obj.data[i] + data[i];
            } else {
                cout << "ERROR!!!...Sizes are not equal" << endl;
                temp.size = -1;
                temp.data = NULL;
            }

            return temp;
        }

        bool operator==(const Collection &obj) const
        {
            if(size != obj.size) return false;
            else {
                for (int i = 0; i < size; i++)
                    if(data[i] != obj.data[i]) return false;
            }

            return true;
        }

};


int main() {
    int arr[6] = {1, -2, -3, 4, 5, 6};
    Collection rdx1(5), rdx2(arr, 6), rdx3(rdx2), rdx4(5);

    //rdx1.getCollection();
    //rdx1.printCollection();
    //rdx3.insertElement(2, 1);
    //rdx3.insertElement(3, 2);
    //rdx3.printCollection();
    //cout << rdx3.findElement(4) << endl;
    //cout << rdx1.getSize();

    //cout << (rdx1 == rdx3);

    //rdx1 = rdx2;
    //rdx1.printCollection();

    Collection rdx5 = (rdx2 + rdx3);

    rdx5.printCollection();
    return 0;
}