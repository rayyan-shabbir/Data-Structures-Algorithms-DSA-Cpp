#include "iostream"
#include "fstream"
using namespace std;

class Student {
    int id;         // id of a student
    string name;    // name of a student
    float cgpa;     // cgpa of a student
    Student* next;  // adress of next available object

public:
    // CONSTRUCTOR
    Student(int id, string name, float cgpa, Student* next) {
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
        this->next = next;
    }

    //DISPLAYS STUDENT INFORMATION
    void studentDetails() {
        cout << "ID: " << this->id << endl;
        cout << "Name: " << this->name << endl;
        cout << "CGPA: " << this->cgpa << endl;
        cout << endl;
    }

    friend class StudentList;
};


class StudentList {
    Student* head;          // start of the list
    Student* cursor;        // current item of the list

    public:
        // CONSTRUCTOR
        StudentList() {
            head = NULL;
            cursor = NULL;
        }

        // DESTRUCTOR
        ~StudentList() {
            if(head != NULL) {
                Student* temp = head;

                while(temp != NULL) {
                    head = head->next;

                    delete temp;
                    temp = head;
                }

                delete head;
            }
        }


        // INSERT
        void insert(const Student& newStd) {
            Student* temp = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);

            if(head == NULL) {
                head = temp;
            } else {
                temp->next = cursor->next;
                cursor->next = temp;
            }

            cursor = temp;
        }

        void remove(int id) {
            if(head == NULL) cout << "Student List is already Empty" << endl;
            else if(head->next == NULL) {
                if(head->id == id) {
                    delete head;

                    head = NULL;
                    cursor = NULL;
                } else {
                    cout << "Id not found" << endl;
                }
            } else {
                Student* cur = head;
                if(head->id == id && head != cursor) {
                    head = head->next;

                    delete cur;
                } else {
                    Student* pre = NULL;


                    while(cur != NULL && cur->id != id) {
                        pre = cur;
                        cur = cur->next;
                    }

                    if(cur == NULL) {
                        cout << "ID not found" << endl << endl;
                    } else if(cur == head && cur != cursor) {
                        head = head->next;
                    }else if(cur == head && cur == cursor) {
                        head = head->next;
                        cursor = cursor->next;
                    } else if(cur == cursor && cursor->next != NULL) {
                        cursor = cursor->next;

                    } else if(cur == cursor && cursor->next == NULL) {
                        cursor = head;
                    }

                    if(cur != NULL) {
                        if(pre != NULL) pre->next = cur->next;
                        delete cur;
                    }
                }
            }
        }


        void search(float cgpa) const {
            if(head == NULL) {
                cout << "No record exist" << endl;
            } else {
                Student* temp = head;

                while(temp != NULL && temp->cgpa != cgpa) {
                    temp = temp->next;
                }

                if(temp != NULL) {
                    cout << "Student Id: " << temp->id << endl;
                    cout << "Student Name: " << temp->name << endl;
                    cout << "Student CGPA: " << temp->cgpa << endl;
                } else {
                    cout << "Student not exists with CGPA: " << cgpa << endl;
                }
            }
        }

        void replace (const Student& newStd) {
            if(head == NULL) {
                cout << "No Record Exists" << endl;
            } else {
                Student* pre = NULL;
                Student* temp = head;

                while(temp != NULL && temp->id != newStd.id) {
                    pre = temp; 

                    temp = temp->next;
                }

                if(temp == NULL) {
                    Student* newNode = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);

                    pre->next = newNode;
                    cursor = newNode;
                } else {
                    temp->name = newStd.name;
                    temp->cgpa = newStd.cgpa;

                    cursor = temp;
                }
            }
        }

        bool isEmpty() const {
            if(head == NULL) return true;

            return false;
        }

        void gotoBeginning() {
            if(head == NULL) cout << "No record exist" << endl;
            cursor = head;
        }

        void gotoEnd() {
            if(head == NULL) {
                cout << "No record exist" << endl;
            } else {
                Student* temp = head;

                while(temp->next != NULL) {
                    temp = temp->next;
                }

                cursor = temp;
            }
        }

        bool gotoNext() {
            if(head == NULL) {
                cout << "No record exist" << endl;
            } else {
                if(cursor->next != NULL) {
                    cursor = cursor->next;
                    return true;
                }

                return false;
            }
        }


        bool gotoPrior() {
            if(head == NULL) {
                cout << "No record exist" << endl;
            } else {
                if(cursor != head) {
                    Student* temp = head;

                    while(temp->next != cursor) {
                        temp = temp->next;
                    }

                    cursor = temp;
                    return true;
                }

                return false;
            }
        }

        Student getCursor() {
            // return *cursor;

            Student* temp = cursor;

            return *temp;
        }


        void showStructure() const{
            if(head == NULL) cout << "Empty List" << endl;
            else {
                Student* temp = head;

                while(temp != NULL) {
                    cout << "ID: " << temp->id << endl;
                    cout << "NAME: " << temp->name << endl;
                    cout << "CGPA: " << temp->cgpa << endl;

                    temp = temp->next;
                    cout << endl;
                }
            }
        }
};


int main() {
    StudentList list;
    Student rdx1(101, "Rayan Shabir", 10.1, NULL);
    // Student rdx2(102, "Ali ", 0.91, NULL);
    // Student rdx3(103, "Kashif Akmal", 11.91, NULL);
    // Student rdx4(104, "Abrar Ahmed", 22.70, NULL);

    Student rep(999, "Jalli Baba", 999.10, NULL);

    // list.insert(rdx1);
    // list.insert(rdx2);
    // list.insert(rdx3);
    // list.insert(rdx4);

    // list.replace(rep);

    // Student temp = (list.getCursor());
    // temp.studentDetails();

    // list.gotoBeginning();
    // list.gotoNext();

    // list.remove(101);
    // list.remove(102);
    // list.remove(103);
    // list.remove(104);
    // list.remove(99);

    // list.search(22.70);
    // list.search(10.12);

    // cout << list.isEmpty()<< endl;

    // list.gotoBeginning();
    // list.gotoEnd();
    // cout << list.gotoNext() << endl;
    // cout << list.gotoPrior() << endl;

    // Student temp = list.getCursor();
    // temp.studentDetails();


    // list.showStructure();
    
    ifstream inf("input.txt", ios::in);

    int id;
    string name;
    float cgpa;

    if(!inf) {
        cout << "File does not open" << endl;
        exit(0);
    }

    while(!inf.eof()) {
        inf >> id;

        inf.ignore();
        getline(inf, name);

        inf >> cgpa;
        inf.ignore();

        // cout << id << " " << name << " " << cgpa << endl;

        Student temp(id, name, cgpa, NULL);
        list.insert(temp);
    }

    // list.insert(rep);
    // list.gotoBeginning();

    // list.remove(1);

    // list.replace(rdx1);
    // list.search(10.1);

    // Student far = list.getCursor();
    // far.studentDetails();

    list.showStructure();

    return 0;
}