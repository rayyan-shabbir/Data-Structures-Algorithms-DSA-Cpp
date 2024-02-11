#include "iostream"
using namespace std;

class HashTable {
    string* table;
    int size;
    int curSize;

    public:
        HashTable(int size) {
            this->size = size;
            table = new string[size];
            curSize = 0;

            for(int i = 0; i < size; i++)
                table[i] = "EMPTY";
        }

        ~HashTable() {
            delete table;
        }

        bool isEmpty() {
            if(curSize == 0) return true;

            return false;
        }

        bool isFull() {
            if(size == curSize) return true;

            return false;
        }

        double loadFactor() {
            int lF = curSize / size;

            // cout << endl << size << endl << curSize << endl;


            return lF;
        }


        int value(string name) {
            int temp = 0;

            for(int i = 0; i < name.length(); i++) 
                temp = temp + name[i];

            return temp;
        }


        bool insert(string name) {
            int val = value(name);
            int hashCode = val % size;
            int orgHashCode = hashCode;


            if (table[hashCode] == "EMPTY") {
                table[hashCode] = name;
                curSize++;

                cout << "Successfully Inserted..." << endl;
                return true;
            } else {
                // int reHash = hashCode;
                int reHash = -1;

                do {
                    reHash = ((++hashCode) % size);

                    //reHash = ((++reHash) % size);

                } while ((table[reHash] != "EMPTY") && reHash != orgHashCode);

                if(reHash != orgHashCode) {
                    table[reHash] = name;
                    curSize++;

                    cout << "Successfully Inserted..." << endl;
                    return true;
                } else {

                    cout << "Failed to Insert..." << endl;
                    return false;
                }
            }
        }


        bool search(string name) {
            int val = value(name);
            int hashCode = val % size;
            int orgHashCode = hashCode;


            if (table[hashCode] == name) {
                cout << "Name Exists..." << endl;

                return true;

            } else {
                // int reHash = hashCode;
                int reHash = -1;

                do {
                    reHash = ((++hashCode) % size);

                    // reHash = ((++reHash) % size);

                } while ((table[reHash] != name) && reHash != orgHashCode);

                if(table[reHash] == name) {
                    cout << "Name Exists..." << endl;

                    return true;
                } else {

                    cout << "Name not Exists..." << endl;
                    return false;
                }
            }
        }


        bool remove(string name) {
            int val = value(name);
            int hashCode = val % size;
            int orgHashCode = hashCode;

            if(table[hashCode] == name) {
                table[hashCode] = "EMPTY";
                curSize--;

                cout << "Successfully Removed..." << endl;
                return true;
            } else {
                int reHash = -1;

                do {

                    reHash = ((++hashCode) % size);

                } while((table[reHash] != name) && reHash != orgHashCode);

                if(reHash != orgHashCode && table[reHash] == name) {
                    table[reHash] = "EMPTY";
                    curSize--;

                    cout << "Successfully Removed..." << endl;
                    return true;
                } else {
                    cout << "Failed to Remove..." << endl;
                    return false;
                }
            }
        }

        void display() {
            cout << endl << "--- Hash Table ---" << endl;
            for(int i = 0; i < size; i++) {
                cout << "Table[" << i << "] : " << table[i] << endl;
            }

            cout << endl;
        }

};


int main() {
    int choice = -1;
    int size = -1;
    cout << "Enter Size of Hash Table: ";
    cin >> size;

    HashTable rdx1(size);
    
    do {
        cout << "\n*** Menue ***" << endl;
        cout << "1. Insert a name" << endl;
        cout << "2. Search for a name" << endl;
        cout << "3. Remove a name" << endl;
        cout << "4. Display the table" << endl;
        cout << "5. Display the Load Factor of the table" << endl;
        cout << "6. Exit" << endl;

        cout << endl << "Enter your Choice: ";
        cin >> choice;
        cout << endl << endl;

        if(choice == 1) {
            string name = "";
            cout << "Enter name you wanted to Insert: ";
            cin >> name;

            rdx1.insert(name);
        } else if(choice == 2) {
            string name = "";
            cout << "Enter name you wanted to Search: ";
            cin >> name;

            rdx1.search(name);
        } else if(choice == 3) {
            string name = "";
            cout << "Enter name you wanted to Remove: ";
            cin >> name;

            rdx1.remove(name);
        } else if(choice == 4) {    
            rdx1.display();
            
        } else if(choice == 5) {
            double lF = rdx1.loadFactor();

            cout << "Load Factor = " << lF << endl;
        } else if(choice == 6) {
            cout << "Thankyou..." << endl;
            exit(0);
        }
    } while (choice != 6); 

    return 0;
}