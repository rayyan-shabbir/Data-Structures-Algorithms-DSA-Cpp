#include "iostream"
#include "fstream"
using namespace std;


int main() {
    int arr[11], h1, h2;

    ifstream inf("input.txt", ios::in);
    ofstream outf("output.txt", ios::out);

    for (int i = 0; i < 20; i++) {
        for (int i = 0; i < 11; i++)
            inf >> arr[i];
        
        h1 = arr[1];
        h2 = arr[1];

        cout << h1 << endl << h2 << endl;

        for (int i = 2; i < 11; i++)
            if(h1 < arr[i]) h1 = arr[i];
        
        for(int i = 2; i < 11; i++)
            if(h2 < arr[i] && arr[i] != h1) h2 = arr[i];
        
        outf << arr[0] << " " << h1 << " " << h2 << endl;
    }

    outf.close();
    inf.close();
    return 0;
}