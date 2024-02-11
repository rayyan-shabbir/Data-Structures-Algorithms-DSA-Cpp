#include "iostream"
#include "fstream"
using namespace std;


int main() {
    string fName, word, paragraph;

    cout << "Enter File Name that you wants to open:: ";
    cin >> fName;

    cout << "The Name:: " << fName << endl;

    ifstream inf(fName, ios::in);

    if(!inf) {
        cout << "ERROR!!! File Does not Open" << endl;
        exit(0);
    }

    inf >> word;
    cout << "\nWORD :: " << word << endl;

    while(!inf.eof()) {
        getline(inf, paragraph);
    }

    cout << "\n***PARAGRAPH*** \n" << paragraph << endl;

    int countDots = 0;

    for(int i = 0; paragraph[i] != '\0'; i++) {
        
        //Checking if it is the end of paragraph and it is not terminating on a '.' , So, we add '.' by ourself..
        if(paragraph[i+1] == '\0' && paragraph[i] != '.') paragraph += '.';

        char c = paragraph[i];

        if(c == '.') countDots++;
    }

    cout << "Total No. of Lines are:: " << countDots << endl;

    string lines[countDots] = {" "};
    int j = 0;       //Beginning of Paragraph
    int k = 0;      //No of Lines

    while(paragraph[k] != '\0') {
        char c = paragraph[k];
        k++;

        if(c != '.') lines[j] += c;
        else j++;
    }

    // cout << "\n***Printing Lines***" << endl;
    // for (int i = 0; i < countDots; i++)
    // {
    //     cout << lines[i] << endl;   
    // }

    cout << "The word \"" << word << "\" has following occurences" << endl;

    for(int i = 0; i < countDots; i++) {
        string L = lines[i];
        int countSpace = 0;
        
        for(int j = 0; L[j] != '\0'; j++) {
            char c = L[j];

            if(c == ' ') countSpace++;
        }

        string words[countSpace] = {" "};
        int k = 0;
        int l = 0;

        while(L[l] != '\0') {
            char c = L[l];
            l++;
            if(c != ' ') words[k] += c;
            else k++;
        }

        int countOcc = 0;
        for(int i = 0; i < countSpace; i++) {
            if(words[i] == word) countOcc++;
        }
        cout << "Line " << i+1 << ": " << countOcc << endl;
    }

    return 0;
}