#include "iostream"
#include "fstream"
using namespace std;


int main() {
    int roll;
    string fName, lName;
    float marks;

    ofstream outf("student.txt", ios::out);

    if(!outf) {
        cout << "File Does not open" << endl;
        exit(0);
    }

    while(1) {
        cin >> roll;
        if(roll == -999) break;
        cin >> fName >> lName >> marks;

        outf << roll << "\t" << fName << " " << lName << "\t" << marks << endl << endl;
    }

    cout << "Done" << endl;
    outf.close();
    return 0;
}