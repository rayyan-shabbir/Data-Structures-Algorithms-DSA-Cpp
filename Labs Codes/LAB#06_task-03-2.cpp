#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file;
    string str,  filename;
    string q;
    // filename of the file
    filename = "input3.txt";

  
    // opening file
    file.open(filename.c_str());
   
    q = "Merciful";
    int l = 0;
   
    int* lines = new int[500];
    for (int i = 0; i < 500; i++)
    {
        lines[i] = 0;
    }
    // extracting words from the file
    int c = 1;
    while (getline(file, str)) {
       // cout << word << "\n";

        int words = 0; 

        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == ' ') 
            {
                words++;
            }
        }
        lines[l] = words + 1;

        cout << "The number of words = " << lines[l] << endl;
        l++;
    
      //  return 0
       
        
    }
 /*   for (int i = 0; i < l ; i++)
    {
        cout << "Lines array" << lines[i] << endl;
    }*/
   // cout << "Lin" << lin << endl;
    file.close();
    file.open(filename.c_str());
    int count = 0;
    int i = 0;
  

    int k = 0;;
    while (file >> str)
    {
        str.erase(remove(str.begin(), str.end(), ','), str.end());
        str.erase(remove(str.begin(), str.end(), '.'), str.end());
       // cout << str << endl;
        if (q == str )
        {
          //  cout << str;
            count++;

        }
        i++;
            if (i == lines[k])
            {
                cout <<"Lines "<<k <<" :"<< count << endl;
                k++;
                i = 0;
                count = 0;

        }
     
    
    }
    delete[] lines;

    return 0;

}