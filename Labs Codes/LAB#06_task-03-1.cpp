#include "iostream"
#include "string"
#include "fstream"
using namespace std;

 

int main()
{
    string fName;
    string paragraph;
    string word;

    cout << "Enter File Name:: ";
    cin >> fName;

    cout << "The Name:: " << fName << endl;
    ifstream inf(fName, ios::in);

    if (!inf)
    {
        cout << "ERROR" << endl;
        exit(0);
    }

    inf >> word;
    // cout << word;

    while (!inf.eof())
    {
        // int count = 0;

        getline(inf, paragraph);
        cout << paragraph << endl;
    }

    // cout << endl << endl <<  paragraph << endl;

    int count_dots = 0;
    for (int i = 0; paragraph[i] != '\0'; i++)
    {
        //Checking if it is the end of paragraph and it is not terminating on a '.' , So, we add '.' by ourself..
        if(paragraph[i+1] == '\0' && paragraph[i] != '.') paragraph += '.';

        char x = paragraph[i];
        if (x == '.')
            count_dots++;
    }

    // cout << count_dots << endl;

    string line[count_dots] = {""};
    int j = 0;
    int k = 0;

    while (paragraph[k] != '\0')
    {
        char x = paragraph[k];
        k++;
        if (x != '.')
            line[j] += x;
        else
            j++;
    }

    cout << endl;


    cout << "\nThe word " << word << " has following occurrences" << endl;
    for (int i = 0; i < count_dots; i++)
    {
        
        string L = line[i];
        int count_space = 0;
        
        // cout << "\nLOOP 1" << endl;

        for (int j = 0; L[j] != '\0'; j++)
        {
            char x = L[j];
            
            if (x == ' ')
                count_space++;
        }

        string count_words[count_space] = {" "};
        int j = 0;
        int k = 0;

        // cout << "\nWhile LOOP" << endl;

        while (L[k] != '\0')
        {
            char x = L[k];
            k++;
            if (x != ' ')
                count_words[j] += x;
            else
                j++;
        }

        //cout << "\nCount F LOOP " << endl;
        int count_occ = 0;
        for (int i = 0; i < count_space; i++)
            if (count_words[i] == word)
                count_occ++;

        cout << "Line " << i+1 << " : " << count_occ << endl;
        

    }

    return 0;
}