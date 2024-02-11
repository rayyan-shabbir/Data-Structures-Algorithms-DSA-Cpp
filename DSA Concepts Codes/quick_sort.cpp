// Quick Sort
#include "iostream"
using namespace std;

/* Partition the list into two halves based
   on pivot and return PIVOT index */
int partition(int A[], int left, int right)
{
    int l = left, r = right;
    int p = left; // Choosing first element as pivot

    // Partition based on p (pivot)
    while (l < r)
    {
        while (A[l] <= A[p] && l < r)
            l++;

        while (A[r] > A[p])
            r--;

        if (l < r)
        {
            swap(A[l], A[r]);
        }
    }

    swap(A[p], A[r]);

    return r;
}

void quickSort(int A[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(A, left, right);

        for (int i = 0; i < 10; i++)
        {
            cout << A[i] << "\t";
        }

        cout << endl;

        quickSort(A, left, pivot - 1);
        quickSort(A, pivot + 1, right);
    }
}

int main()
{
    int A[] = {41, 79, 65, 35, 21, 48, 59, 87, 52, 28};

    cout << "List:\t";
    for (int i = 0; i < 10; i++)
    {
        cout << "\t" << A[i];
    }

    cout << endl;

    quickSort(A, 0, 9);

    cout << endl;

    cout << "\nSorted List: ";
    for (int i = 0; i < 10; i++)
    {
        cout << "\t" << A[i];
    }

    return 0;
}