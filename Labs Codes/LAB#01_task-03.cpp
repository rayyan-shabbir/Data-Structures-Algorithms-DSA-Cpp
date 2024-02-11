#include "iostream"
#include "fstream"
using namespace std;


int main() {
    int arr[11], high;

    ifstream inf("input.txt", ios::in);

    if(!inf) {
        cout << "File Does not open" << endl;
        exit(0);
    }

    for (int i = 0; i < 20; i++) { while(inf.eof() == 0)
        for (int i = 0; i < 11; i++)
            inf >> arr[i];
        high = arr[1];

        for (int i = 2; i < 11; i++)
            if(high < arr[i]) high = arr[i];
        
        for (int i = 0; i < 11; i++)
            cout << arr[i] << " ";

        cout << high << endl;
    }

    inf.close();
    return 0;
}