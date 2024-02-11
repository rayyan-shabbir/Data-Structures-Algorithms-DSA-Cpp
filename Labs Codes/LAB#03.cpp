#include "iostream"
using namespace std;

struct Point3D 
{
    float x, y, z;
};


class PointList {              
    private:
        struct Point3D *array;
        int maxSize;
        int curSize;
        int cursor;

    public:
        //CONSTRUCTOR
        PointList(int maxSize) {
            this->maxSize = maxSize;
            this->curSize = -1;
            this->cursor = -1;

            if(maxSize <= 0) {
                array = NULL;
            } else {
                this->array = new Point3D[maxSize];

                for (int i = 0; i < maxSize; i++)
                {
                    this->array[i].x = 0;
                    this->array[i].y = 0;
                    this->array[i].z = 0;
                }
            }
        }

        //DESTRUCTOR
        ~PointList() {
            delete[] array;
        }

        //MEMBER FUNCTIONS
        bool isEmpty() {
            if(curSize == -1) return true;

            return false;
        }

        bool isFull() {
            if(curSize+1 == maxSize) return true;

            return false;
        }
        
        void insert(struct Point3D newPoint) {
            if(!isFull()) {
                curSize++;
                cursor = curSize;

                array[curSize] = newPoint;
            } else {
                cout << "\nLIST IS FULL" << endl;
            }
        }

        void showStructure() {
            if(!isEmpty()) {
                cout << "\nList::\n";
                for (int i = 0; i <= curSize; i++)
                {
                    cout << "Point# " << i << ": ";
                    cout << "x = " << this->array[i].x;
                    cout << ", y = " << this->array[i].y;
                    cout << ", z = " << this->array[i].z;
                    cout << endl;
                }
                cout << endl;
            } else {
                cout << "EMPTY LIST...." << endl;
            }
        }

        Point3D getCursor() {
            struct Point3D temp;
            if(!isEmpty()) {
                temp = array[cursor];
            } else {
                cout << "List is Empty" << endl;
                temp.x = -1;
                temp.y = -1;
                temp.z = -1;
            }
            return temp;
        }

        void gotoBeginning() {
            if(!isEmpty()) {
                cursor = 0;
            } else {
                cout << "\nLIST IS EMPTY" << endl;
            }
        }

        void gotoEnd() {
            if(!isEmpty()) {
                cursor = curSize;
            } else {
                cout << "\nLIST IS EMPTY" << endl;
            }
        }

        bool gotoNext() {
            if(cursor != curSize) {
                cursor++;
                return true;
            }

            return false;
        }

        bool gotoPrior() {
            if(cursor != 0) {
                cursor--;
                return true;
            }

            return false;
        }

        void clear() {
            curSize = -1;
            cursor = -1;

            for (int i = 0; i < maxSize; i++)
            {
                this->array[i].x = 0;
                this->array[i].y = 0;
                this->array[i].z = 0;
            }   
        }

        bool replace(struct Point3D newPoint) {
            if(!isEmpty()) {
                struct Point3D temp = newPoint;
                newPoint = array[cursor];
                array[cursor] = temp;

                return true;
            }

            return false;
        }

        void remove() {
            if(!isEmpty()) {
                array[cursor].x = array[curSize].x;
                array[cursor].y = array[curSize].y;
                array[cursor].z = array[curSize].z;

                array[curSize].x = 0;
                array[curSize].y = 0;
                array[curSize].z = 0;

                curSize--;

                if(!isEmpty()) {
                    if(cursor+1 == curSize) {
                        cursor = 0;
                    }
                }
            }
        }
};



int main() {
    PointList rdx1(5);

    cout << rdx1.isEmpty() << endl;
    cout << rdx1.isFull() << endl;
    rdx1.showStructure();

    //rdx1.gotoBeginning();

    struct Point3D newPoint1;
    newPoint1.x = 1;
    newPoint1.y = 2;
    newPoint1.z = 3;

    rdx1.insert(newPoint1);

    struct Point3D newPoint2;
    newPoint2.x = 4;
    newPoint2.y = 5;
    newPoint2.z = 6;

    rdx1.insert(newPoint2);

    struct Point3D newPoint3;
    newPoint3.x = 7;
    newPoint3.y = 8;
    newPoint3.z = 9;

    rdx1.insert(newPoint3);

    struct Point3D newPoint4;
    newPoint4.x = 10;
    newPoint4.y = 11;
    newPoint4.z = 12;

    rdx1.insert(newPoint4);

    struct Point3D newPoint5;
    newPoint5.x = 13;
    newPoint5.y = 14;
    newPoint5.z = 15;

    rdx1.insert(newPoint5);

    // struct Point3D newPoint6;
    // newPoint6.x = 16;
    // newPoint6.y = 17;
    // newPoint6.z = 18;

    //rdx1.insert(newPoint6);
    
    rdx1.showStructure();

    //rdx1.gotoBeginning();
    //rdx1.gotoEnd();

    // newPoint1 = rdx1.getCursor();
    // cout << newPoint1.x << endl;
    // cout << newPoint1.y << endl;
    // cout << newPoint1.z << endl;



    //cout << endl << rdx1.gotoNext() << endl;

    rdx1.remove();

    rdx1.showStructure();

    // cout << endl;
    // newPoint1 = rdx1.getCursor();
    // cout << newPoint1.x << endl;
    // cout << newPoint1.y << endl;
    // cout << newPoint1.z << endl;

    //cout << endl << rdx1.gotoPrior();

    /*cout << rdx1.getCursor().x << endl;
    cout << rdx1.getCursor().y << endl;
    cout << rdx1.getCursor().z << endl; */

    // rdx1.clear();
    // rdx1.showStructure();

    // struct Point3D newPoint4;
    // newPoint4.x = 12;
    // newPoint4.y = 13;
    // newPoint4.z = 14;

    //cout << rdx1.replace(newPoint4);

    //rdx1.insert(newPoint4);
    //rdx1.showStructure();
    return 0;
}