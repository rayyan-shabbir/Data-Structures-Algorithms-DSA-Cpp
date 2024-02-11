#include "iostream"
using namespace std;

// Student class
class Student {
    private: 
        double cgpa;            // Student's CGPA
        int rollNo;             // Student's Roll No

    public:
        // Default Constructor
        Student() {
            this->rollNo = 0;
            this->cgpa = 0;
        }

        // Constructor
        Student(double cgpa, int rollNo) {
            this->cgpa = cgpa;
            this->rollNo = rollNo;
        }

        friend class StudentMaxHeap;
};

// Student Max Heap class
class StudentMaxHeap {
    Student* arr;               // Array of students which, arranged like a Max Heap
    int curSize;                // Current number of students present in the heap
    int maxSize;                // Maximum number of students that can be present in the heap


    // PrintLevelOrder
    // void printLevelOrder(int index, int level) {
    //     if(index < 0) {

    //     } else if (level == 1) {
    //         cout << " CGPA: " << arr[index].cgpa << "\t, Roll No : " << arr[index].rollNo; 
    //     } else if(level > 1) {
    //         printLevelOrder(2 * index + 1, level -1);
    //         printLevelOrder(2 * index + 2, level -1);
    //     }
    // }

    public:
        // Constructor
        StudentMaxHeap(int size) {
            this->arr = new Student[size];

            this->maxSize = size;
            this->curSize = 0;
        }

        // Destructor
        ~StudentMaxHeap() {
            delete arr;
        }

        // isEmpty  --> Check whether the heap is empty or not
        bool isEmpty() {
            if(curSize == 0) {
                cout << "Heap is Empty" << endl;
                return true;
            }

            cout << "Heap is not Empty" << endl;
            return false;
        }

        // isFull  --> Check whether the heap is full or not
        bool isFull() {
            if(curSize == maxSize) {
                cout << "Heap is Full" << endl;
                return true;
            }

            cout << "Heap is not Full" << endl;
            return false;
        }

        // maxHeapify
        void maxHeapify(Student* arr, int i, int cS) {
            int left_i = 2 * i + 1;

            int right_i = 2 * i + 2;

            int largest = i;

            if(left_i < curSize && arr[left_i].cgpa > arr[largest].cgpa) 
                largest = left_i;

            if(right_i < curSize && arr[right_i].cgpa > arr[largest].cgpa) 
                largest = right_i;

            if(largest != i) {
                swap(arr[i],  arr[largest]);

                maxHeapify(arr, largest, curSize);
            }
        }

        // Insert Member Function
        bool insert(int rollNo, double cgpa) {
            if(!isFull()) {
                int np = curSize;
                (arr[curSize]).cgpa = cgpa;
                (arr[curSize]).rollNo = rollNo;

                curSize++;

                while(np != 0 && arr[np].cgpa >= arr[((np - 1) / 2)].cgpa) {
                    if(arr[np].cgpa == arr[((np - 1) / 2)].cgpa) {
                        if(arr[np].rollNo < arr[((np - 1) / 2)].rollNo) {
                            swap(arr[np], arr[((np - 1) / 2)]);

                            np = ((np - 1) / 2);
                        }

                    } else {
                        swap(arr[np], arr[((np - 1) / 2)]);

                        np = ((np - 1) / 2);
                    }
                }
                return true;
            }

            cout << "\nUnable to Insert\n";
            return false;
        }

        // Remove Function
        bool remove (int &rollNo, double & cgpa) {
            if(!isEmpty()) {
                rollNo = arr[0].rollNo;
                cgpa = arr[0].cgpa;

                arr[0].cgpa = arr[curSize-1].cgpa;
                arr[0].rollNo = arr[curSize-1].rollNo;

                curSize--;

                maxHeapify(arr, 0, curSize);

                return true;
            }

            cout << "\nUnable to Remove\n";
            return false;
        }


        // Display Student List
        void displayStudentList() {
            if(curSize > 0) {
                cout << "\n*** Displaying Student List ***\n\n";
                Student* temp = arr;
                int cS = curSize;


                while (cS > 0) {
                    if(temp[0].cgpa == temp[1].cgpa) {
                        if(temp[0].rollNo > temp[1].rollNo) {
                            swap(temp[0], temp[1]);
                        }
                    } 
                        cout << "CGPA: " << temp[0].cgpa << endl;
                        cout << "Roll No: " << temp[0].rollNo << endl;
                        cout << endl;

                        temp[0].cgpa = temp[cS-1].cgpa;
                        temp[0].rollNo = temp[cS-1].rollNo;

                        cS--;

                        maxHeapify(temp, 0, cS);
                }

                // cout << "CGPA: " << temp[0].cgpa << endl;
                // cout << "Roll No: " << temp[0].rollNo << endl;
            } else {
                cout << "\n No Student Exists\n\n";
            }
        }

        // Level Order
        void levelOrder() {
            if(curSize > 0) {
                // int count = 0;

                cout << "\n*** Student Details (LevelOrder) ***" << endl << endl;
                for(int i = 0; i < curSize; i++) {
                    cout << " CGPA: " << arr[i].cgpa << "\t, Roll No : " << arr[i].rollNo; 
                    cout << endl;

                }

                cout << endl;
            } else {
                cout << "\n No Student Exists\n\n";
            }
        }
};


int main() {
    StudentMaxHeap student1(6);
    int choice = 0;

    while(choice != 5) {
        cout << "\n*** Menue ***" << endl;
        cout << "1. Insert a new student" << endl;
        cout << "2. Remove (and display) the student with the Max CGPA" << endl;
        cout << "3. Display the list of students (Descending order of CGPA)" << endl;
        cout << "4. Display the list of students (Level-order traversal)" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            int rollNo;
            double cgpa;

            cout << "\nEnter Roll No: ";
            cin >> rollNo;
            
            cout << "\nCGPA: ";
            cin >> cgpa;

            student1.insert(rollNo, cgpa);

            cout << "\n Successfully Inserted Data\n";
        } else if(choice == 2) {
            int rollNo = 0;
            double cgpa = 0;

            if(student1.remove(rollNo, cgpa)) {
                cout << "\n Student with Max CGPA is: \n";
                cout << "Roll No: " << rollNo << endl;
                cout << "CGPA: " << cgpa << endl;
            } else {
                cout << "\n No Student Exists\n\n";
            }

        } else if(choice == 3) {

            student1.displayStudentList();
        } else if(choice == 4) {

            student1.levelOrder();
        } else if(choice == 5) {

            cout << endl << "Thank You!... You are successfully Exited" << endl;
        } else {

            cout << endl << "Invalid Input... Please Try Again" << endl << endl;
            exit(0);
        } 
    }
    

    return 0;
}