#include "iostream"
#include "fstream"
using namespace std;

// BOOK CLASS
class Book {
    int id;         // id of a book
    string title;   // name of a book
    float price;    // price of a book
    Book *next;     // adress of the next available object.
    Book *pre;      // adress of the previous available object.

    public:
        // PARAMETRIZE CONSTRUCTOR
        Book (int id, string title, float price, Book* next, Book* pre) {
            this->id = id;
            this->title = title;
            this->price = price;
            this->next = next;
            this->pre = pre;
        }

        // DISPLAYS THE BOOK INFORMATION
        void bookDetails() {
            cout << "***Book Details***" << endl;
            cout << "ID: " << this->id << endl;
            cout << "Title: " << this->title << endl;
            cout << "Price: " << this->price << endl;
        }

        friend class BookList;
};

// BOOKLIST CLASS
class BookList {
    Book* head;         // start of the list
    Book* cursor;       // current item of the list
    Book* last;         // last item of the list

    public: 
        // CONSTRUCTOR
        BookList() {
            head = cursor = last = NULL;
        }

        // DESTRUCTOR
        ~BookList() {
            if(head != NULL) {
                Book* cur = head;

                while(cur != NULL) {
                    head = head->next;
                    delete cur;
                    cur = head;
                }

                head = cursor = last = NULL;
            }
        }

        // INSERT
        void insert(const Book &newItem) {
            Book* newNode = new Book(newItem.id, newItem.title, newItem.price, NULL, NULL);

            if(head == NULL) {
                head = newNode;
                last = newNode;
            } else {
                newNode->next = cursor->next;
                if(cursor->next != NULL) {
                    cursor->next->pre = newNode;
                }
                cursor->next = newNode;
                newNode->pre = cursor;

                Book* cur = last;
                while(cur->next != NULL) cur = cur->next;

                if(cur->next == NULL) last = cur;
            }

            cursor = newNode;
        }

        // REMOVE
        void remove() {
            if(head == NULL) cout << "Book List is already Empty" << endl;
            else {
                Book* temp = cursor;

                if(cursor->next != NULL) {
                    if(cursor == head) head = head->next;
                    cursor = cursor->next;

                    if(temp->pre != NULL) temp->pre->next = cursor;

                    cursor->pre = temp->pre;
                } else if(cursor->next == NULL && cursor != head) {
                    cursor = head;

                    last = temp->pre;
                    temp->pre->next = NULL;
                } else {
                    cursor = head = last = NULL;
                }

                delete temp;
            }
        }

        // SEARCH
        void search(string title) {
            if(head == NULL) cout << "Book List is Empty" << endl;
            else {
                bool flag = false;
                Book* cur = head;

                while(cur != NULL) 
                {
                    if(cur->title == title) {
                        cur->bookDetails();
                        flag = true;
                    }

                    cur = cur->next;
                }

                if(!flag) cout << endl << "Book with Title: \"" << title << "\", Not exists" << endl;
            }
        }

        // REPLACE
        void replace(const Book &newItem) {
            if(cursor != NULL) {
                Book* cur = new Book(newItem.id, newItem.title, newItem.price, NULL, NULL);

                cursor->id = cur->id;
                cursor->title = cur->title;
                cursor->price = cur->price;
            } else cout << "No item exists" << endl;
        }

        // ISEMPTY
        bool isEmpty() {
            return !head;
        }

        // GOTOBEGINNING
        void gotoBeginning() {
            cursor = head;
        }

        // GOTOEND
        void gotoEnd() {
            cursor = last;
        }

        // GOTONEXT
        bool gotoNext() {
            if(head == NULL) cout << "Book List is Empty" << endl;
            else if(cursor->next != NULL) {
                cursor = cursor->next;
                return true;
            }

            return false;
        }

        // GOTOPRIOR
        bool gotoPrior() {
            if(head == NULL) cout << "Book List is Empty" << endl;
            else if(cursor != head) {
                cursor = cursor->pre;
                return true;
            }

            return false;
        }

        // GETCURSOR
        Book getCursor() {
            return *cursor;
        }

        // SHOW STRUCTURE FORWARD
        void showStructureForward() const
        {
            if(head == NULL) cout << "Empty List" << endl;
            else {
                Book* cur = head;

                cout << "***Book List (Forward)***" << endl;
                while(cur != NULL) {
                    cout << "ID: " << cur->id << endl;
                    cout << "Title: " << cur->title << endl;
                    cout << "Price: " << cur->price << endl;
                    cout << endl;

                    cur = cur->next;
                }
            }
        }

        // SHOW STRUCTURE REVERSE
        void showStructureReverse() const
        {
            if(head == NULL) cout << "Empty List" << endl;
            else {
                Book* cur = last;

                cout << "***Book List (Reverse)***" << endl;
                while(cur != NULL) {
                    cout << "ID: " << cur->id << endl;
                    cout << "Title: " << cur->title << endl;
                    cout << "Price: " << cur->price << endl;
                    cout << endl;

                    cur = cur->pre;
                }
            }
        }

};

int main() {
    BookList list;
    Book rdx1(101, "Tajliat Nabuwat", 50.783, NULL, NULL);
    Book rdx2(102, "The Silent Patient", 100.53, NULL, NULL);
    Book rdx3(103, "The Hungary Man", 30.129, NULL, NULL);
    Book rdx4(104, "Psychology", 80.02, NULL, NULL);

    Book rep(999, "UnKnown", 9999.01, NULL, NULL);

    // list.insert(rdx1);
    // list.insert(rdx2);
    // list.insert(rdx3);
    // list.insert(rdx4);

    // list.replace(rep);

    // Book temp1 = (list.getCursor());
    // temp1.bookDetails();

    // list.gotoBeginning();
    // list.gotoNext();

    // Book temp2 = (list.getCursor());
    // temp2.bookDetails();

    // list.remove();
    // list.remove();
    // list.remove();
    // list.remove();

    // list.search("The Silent Patient");
    // list.search("The Silent");

    // cout << list.isEmpty() << endl;

    // list.gotoBeginning();
    // list.gotoEnd();
    // cout << list.gotoNext() << endl;
    // cout << list.gotoPrior();


    // list.showStructureForward();
    // list.showStructureReverse();

    int id;
    string title;
    float price;

    ifstream inf("input.txt", ios::in);

    if(!inf) {
        cout << "File Open Failed" << endl;
        exit(0);
    }


    while(!inf.eof()) {
        inf >> id;

        inf.ignore();
        getline(inf, title);

        inf >> price;
        inf.ignore();

        Book item(id, title, price, NULL, NULL);

        // item.bookDetails();

        list.insert(item);
    }

    // list.insert(rep);
    // list.gotoBeginning();
    // list.gotoEnd();

    // list.gotoPrior();
    // list.gotoPrior();
    // list.gotoNext();

    // list.remove();
    // list.replace(rep);
    // list.search("Visual C#");

    // Book ext = (list.getCursor());
    // ext.bookDetails();

    list.showStructureForward();
    // list.showStructureReverse();


    return 0;
}