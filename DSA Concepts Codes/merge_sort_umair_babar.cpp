//Merge Sort
#include "iostream"
using namespace std;

//Merge
void merge(int arr[], int left, int mid, int right) 
{
    int size1 = mid - left + 1;     //size of left sub array
    int size2 = right - mid;        //size of right sub array

    /* create temporary arrays */
    int *L = new int[size1];
    int *R = new int[size2];

    /* Copy data to temprary arrays L and R */
    for(int i = 0; i < size1; i++) 
        L[i] = arr[left+i];

    for(int i = 0; i < size2; i++)
        R[i] = arr[mid+1+i];

    /* Merge the temporary arrays back into original array A from left till right*/
    int i = 0, j = 0, k = left;     // Initial index of merged subarray

    while(i < size1 && j < size2) {
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of Left(L) array, if there are any */
    while(i < size1) {
        arr[k] = L[i];
        i++, k++;
    }

    /* Copy the remaining elements of Right(R) array, if there are any */
    while(j < size2) {
        arr[k] = R[j];
        j++, k++;
    }

    // Free temporary arrays
    delete[] L;
    delete[] R;
}

//Merge Sort
void mergeSort(int arr[], int left, int right) 
{
    if(left < right) {
        int mid = left + (right - left)/2;

        // Sort first and second halves
        mergeSort(arr, left, mid);      //left half
        
        mergeSort(arr, mid + 1, right); //right half

        merge(arr, left, mid, right);   //merge the elements
    }
}

int main()
{
	int A[] = { 38, 27, 43, 3, 9, 55, 12, 82, 10, 5 };

	//display the array content 
	cout << "List:\t";
    for (int i = 0; i < 7; i++)
    {
        cout << "\t" << A[i];
    }

    mergeSort(A, 0, 9);

    cout << "\nSorted List: ";
    for (int i = 0; i < 7; i++)
    {
        cout << "\t" << A[i];
    }
	return 0;
}
