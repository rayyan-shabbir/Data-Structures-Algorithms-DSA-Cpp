#include "iostream"
#include "fstream"
using namespace std;


int main() {
    int roll;
    string fName, lName;
    float marks;

    ifstream inf("student.txt", ios::in);

    if(!inf) {
        cout << "File Does not open" << endl;
        exit(0);
    }

    cout << "Roll No.   Name\t       Marks" << endl << endl;

    while(inf >> roll >> fName >> lName >> marks) {
        cout << roll << "\t" << fName << " " << lName << "\t" << marks << endl;
    } 

    cout << "Done" << endl;
    inf.close();
    return 0;
}