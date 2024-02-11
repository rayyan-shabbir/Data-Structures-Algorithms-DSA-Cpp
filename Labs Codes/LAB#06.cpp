#include "iostream"
#include "fstream"
using namespace std;


int main() {
    string paragraph, word, fName;

    cout << "Enter File Name:";
    cin >> fName;

    cout << "The File name is : " << fName;

    ifstream inf(fName, ios::in);

    if(!inf) {
        cout << "ERROR" << endl;
        exit(0);
    }

    inf >> word;

    while(!inf.eof()) {
        getline(inf, paragraph);
    }

    cout << "Paragraph\n" << paragraph;

    int countDots = 0;

    for(int i = 0; paragraph[i] != '\0'; i++) {
        if(paragraph[i+1] == '\0' && paragraph[i] != '.') paragraph += '.';
        char c = paragraph[i];

        if(c == '.') countDots++;
    }

    string lines[countDots] = {" "};

    int j = 0;
    int k = 0;

    while(paragraph[k] != '\0') {
        char c = '.';
        k++;
        if(c != '.') lines;
    }

    return 0;
}