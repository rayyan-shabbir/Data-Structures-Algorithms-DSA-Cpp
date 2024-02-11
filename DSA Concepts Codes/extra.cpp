#include <iostream>

using namespace std;

class Student
{

    double cgpa;
    int rollNo;

public:
    Student()
    {
    this->cgpa = 0;
    this->rollNo = 0;
    }
    Student(double cgpa, int rollNo)
    {
        this->cgpa = cgpa;
        this->rollNo = rollNo;
    }

    void details()
    {
        cout << " CGPA = " << cgpa<<endl;
        cout << " Roll number = " << rollNo<<endl;
    }

    friend class StudentMaxHeap;
};

class StudentMaxHeap
{
private:
    Student *arr;
    int curSize;
    int maxSize;

public:
    StudentMaxHeap(int size)
    {
        this->arr = new Student[size];
        maxSize = size;
        curSize = 0;
    }

    ~StudentMaxHeap()
    {
        delete arr;
    }

    bool isEmpty()
    {
        if (curSize == 0)
        {
            cout << "\n Heap is empty...."<<endl;
            return true;
        }
        cout << "\n Heap is not empty.."<<endl;
        return false;
    }

    bool isFull()
    {
        if (curSize == maxSize)
        {
            cout << "\n Heap is full..";
            return true;
        }

        cout << "\n Heap is not full..";
        return false;
    }

    bool insert(int rollNo, double cgpa)
    {
        if (curSize < maxSize)
        {
        Student *newNode = new Student(cgpa, rollNo);
            this->arr[curSize] = *newNode;
            int np = curSize;

            while (np != 0 && (arr[np].cgpa >= arr[(np - 1) / 2].cgpa))
            {
                if (arr[np].cgpa == arr[(np - 1) / 2].cgpa)
                {
                    if (arr[np].rollNo > arr[(np - 1 / 2)].rollNo)
                        swap(arr[np], arr[(np - 1) / 2]);
                        np = (np-1)/2;
                }
                else
                {
                    swap(arr[np], arr[(np - 1) / 2]);
                    np = (np - 1) / 2;
                }
            }
            return true;
        }

        return false;
    }

    bool remove()
    {
        /*heapify(arr, maxSize, 0);
        double max = arr[0].cgpa;
        arr[0]  = arr[--curSize];*/

        int max = arr[0].cgpa;
        arr[0].cgpa = arr[--curSize].cgpa;
        heapify(arr,maxSize,0);
        return max;
    }

    void heapify(Student* arr, int N, int i) {
        int largest = i;
    
        int left = 2 * i + 1;

        int right = 2 * i + 2;

        if (left < N && arr[left].cgpa > arr[largest].cgpa)
            largest = left;
        if (right < N && arr[right].cgpa > arr[largest].cgpa)
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }
    }

    void display() {
        for (int i = 0; i < curSize; i++)
        {
            arr[i].details();
            cout << endl;
        }
    }

    void levelorder()
    {
        display();
    }
};

int main() {
    StudentMaxHeap obj1(5); 
    obj1.insert(1, 3.5);
    obj1.insert(2, 2.5);
    obj1.insert(3, 2.6);
    obj1.insert(5, 2.9);
    obj1.display();
    cout << "----------------" << endl;
    obj1.remove();
    obj1.display();
    return 0;
}