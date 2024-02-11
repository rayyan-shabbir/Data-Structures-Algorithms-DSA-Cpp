#include "iostream"
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid+1, k = left;

    int size1 = mid - left + 1;     //size of left sub array
    int size2 = right - mid;        //size of right sub array

    int size = size1 + size2;

    int temp[size];

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++, k++;
        } else {
            temp[k] = arr[j];
            j++, k++;
        }
    }   

    while(i <= mid) {
        temp[k] = arr[i];
        i++, k++;
    }

    while(j <= right) {
        temp[k] = arr[j];
        j++, k++;
    }

    for(int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
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

	mergeSort(A, 0, 9);

	//display the array content 
	for (size_t i = 0; i < 10; i++)
	{
		cout << A[i] << endl;
	}

	return 0;
}