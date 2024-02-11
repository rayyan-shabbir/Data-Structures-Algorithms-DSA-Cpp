#include "iostream"
#include "fstream"
#include "ctime"

using namespace std;

// Add necessary instructions to count the Number of Key Comparsisons and Data Movements
static int countKey = 0;
static int countData = 0;
// You are NOT Allowed to add any input/output instructions in sorting algorithms


// Bubble Sort
void bubbleSort(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			countKey++;
			if (a[j] > a[j + 1])
				countData++;
				swap(a[j], a[j + 1]);
		}
	}
}

// Selection Sort
void selectionSort(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < size; j++)
		{
			countKey++;
			if (a[min] > a[j])
				min = j;
		}
		countData++;
		swap(a[i], a[min]);
	}
}

// Insertion Sort
void insertionSort(int a[], int size)
{
	int j = 0;

	for (int i = 0; i < size - 1; i++)
	{
		j = i + 1;

		countKey++;
		while (j > 0 && a[j] < a[j - 1])
		{
			countData++;
			swap(a[j], a[j - 1]);
			j--;
			countKey++;
		}
	}
}

int main()
{
	// Read the data from file here
	int arr[20000];
	int size;
	ifstream inf("in20000a.txt", ios::in);

	if (!inf)
	{
		cout << "ERROR" << endl;
		exit(0);
	}

	inf >> size;

	while (!inf.eof())
	{
		for (int i = 0; i < 20000; i++)
		{
			inf >> arr[i];
		}
	}
	
	clock_t startTime = clock();

	for (int i = 0; i < 10; i++)
	{
		// Make a call to sorting algorithm. DO NOT perform any other operation here
		//bubbleSort(arr, 500);
		//selectionSort(arr, 500);
		insertionSort(arr, 20000);

		clock_t endTime = clock();
		double elapse = ((double)endTime - (double)startTime) / CLOCKS_PER_SEC;
		cout << "The operation took " << elapse << " seconds";

		// Add any other instructions here, if required
		cout << "\nKey Comparisions of :: " << countKey << endl;
		cout << "\nData Movements of :: " << countData << endl;
	}

	return 0;
}