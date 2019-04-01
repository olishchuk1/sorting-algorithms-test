#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int sizeMenu(void) 
{
	/*
	Scrolling interactive menu
	
	You can operate with with the menu by using
	up and down arrow keys.

	To choose one of the item, you have to press
	Enter key.
	*/

	//Creating menu items
	string menu[3] = { "1. 100",
		   			   "2. 1000",
		   			   "3. 10000" };

	//Shows us current choice
	int pointer = 0;

	//The main loop of the menu
	while (true) {

		system("cls");

		//Sets initial text color
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Choose a size of the array:\n\n";

		for (int i = 0; i < 3; ++i) 
		{
			if (i == pointer) 
			{
				//Changes the color of currently choosen item
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << menu[i] << endl;
			}

			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}

		//Checks which key was pressed
		while (true) 
		{
			//VK_UP - UP ARROW key
			if (GetAsyncKeyState(VK_UP) != 0) 
			{
				pointer -= 1;

				if (pointer == -1) 
				{
					pointer = 2;
				}
				break;
			}

			//VK_DOWN - DOWN ARROW key
			else if (GetAsyncKeyState(VK_DOWN) != 0) 
			{
				pointer += 1;

				//Checks if pointer is out of range
				if (pointer == 3) 
				{
					pointer = 0;
				}
				break;
			}

			//VK_RETURN - Enter key
			else if (GetAsyncKeyState(VK_RETURN) != 0) 
			{
				//Returns the result
				switch (pointer) 
				{
				case(0):
					return 100;

				case(1):
					return 1000;

				case(2):
					return 10000;
				}
			}
		}
		Sleep(150);
	}
}

int sortMenu(void) 
{
	string menu[6] = { "1.Bubble sort",
					   "2.Insertion sort",
					   "3.Selection sort",
					   "4.Merge sort",
					   "5.Quicksort",
					   "6.Heap sort" };
	int pointer = 0;

	while (true) 
	{

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "How to sort the array?:\n\n";

		for (int i = 0; i < 6; ++i) 
		{
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << menu[i] << endl;
			}

			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}

		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0) {

				pointer -= 1;
				
				if (pointer == -1) 
				{
					pointer = 5;
				}
				break;
			}

			else if (GetAsyncKeyState(VK_DOWN) != 0) 
			{
				pointer += 1;
				if (pointer == 6) 
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) 
			{
				return pointer + 1;
			}
		}
		Sleep(150);
	}
}


void print(int arr[], int n)
{
	/*
	Function prints arrays.
	arr[] - array
	n - length of the array
	*/
	for (int i = 0; i < n; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int bubbleSort(int *arr, int n) 
{
	/*
	Bubble Sort is the simplest 
	sorting algorithm that works 
	by repeatedly swapping the 
	adjacent elements if they are 
	in wrong order.
	*/
	int counter = 0;
	for (int k = n - 2; k >= 0; k--) 
	{
		for (int i = 0; i <= k; i++) 
		{
			counter++;

			if (arr[i] > arr[i + 1]) 
			{
				//Main operation
				swap(arr[i], arr[i + 1]);
				counter++;
			}
		}
	}
	return counter;
}

int insertionSort(int *arr, int n) 
{
	/*
	
	*/
	int counter = 0,
		temp, temp1;

	for (int i = 1; i < n; i++) 
	{
		temp1 = arr[i];
		int j = i;

		while ((j >= 1)&&(arr[j - 1] > temp1)) 
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;

			counter++;
			j--;
		}
		arr[j] = temp1;
	}
	return counter;
}

int selectionSort(int *arr, int n) 
{
	/*
	The selection sort algorithm
	sorts an array by repeatedly
	finding the minimum element
	(considering ascending order)
	from unsorted part and putting
	it at the beginning. The algorithm
	maintains two subarrays in a given array.

	1) The subarray which is already sorted.
	2) Remaining subarray which is unsorted.

	In every iteration of selection sort,
	the minimum element (considering ascending
	order) from the unsorted subarray is
	picked and moved to the sorted subarray.
	*/
	int minInd, 
		counter = 0;

	for (int i = 0; i < n - 1; i++) 
	{
		minInd = i;

		for (int j = i + 1; j < n; j++) 
		{
			counter++;

			if (arr[j] < arr[minInd]) 
			{
				minInd = j;
			}
		}
		swap(arr[minInd], arr[i]);
	}
	return counter;
}

 
void merge(int *arr, int l, int m, int r, int &counter) 
{
	/*
	Merges two subarrays of arr[].
	First subarray is arr[l..m]
	Second subarray is arr[m+1..r]
	*/
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//create temp arrays
	int *L = new int[n1];
	int *R = new int[n2];

	//Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
		counter++;
	}

	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
		counter++;
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 

	while (i < n1 && j < n2)
	{
		counter++;

		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}

		else
		{
			arr[k] = R[j];
			j++;
		}

		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];

		i++;
		k++;
		counter++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];

		j++;
		k++;
		counter++;
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int *arr, int l, int r, int &counter)
{
	counter++;
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m, counter);
		mergeSort(arr, m + 1, r, counter);

		merge(arr, l, m, r, counter);
	}
}
void quickSort(int *arr, int low, int high, int &counter)
{
	/*
	*/
	int i = low;
	int j = high;
	int pivot = arr[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;

		while (arr[j] > pivot)
			j--;

		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
			counter++;
		}
	}

	counter++;

	if (j > low)
		quickSort(arr, low, j, counter);

	if (i < high)
		quickSort(arr, i, high, counter);
}

void heapify(int *arr, int n, int i, int &counter)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest]) 
	{
		largest = l;
		counter++;
	}

	if (r < n && arr[r] > arr[largest]) 
	{
		largest = r;
		counter++;
	}

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		counter++;
		heapify(arr, n, largest, counter);
	}
}

int heapSort(int *arr, int n) 
{
	int counter = 0;

	for (int i = n / 2; i >= 0; i--) 
	{
		counter ++;
		heapify(arr, n, i ,counter);
	}

	for (int i = n - 1; i >= 0; i--) 
	{
		counter++;
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, counter);
	}
	return counter;
}

int main() 
{
	srand(time(NULL));

	int n = sizeMenu();
	Sleep(150);

	int *arr = new int[n];
	for (int i = 0; i < n; i++) 
	{
		arr[i] = rand() % 10000 + 1;
	}

	cout << endl;
	int choice = sortMenu();
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	print(arr, n);

	switch (choice) 
	{
	case (1):
	{
		int counter = 0;

		cout << endl << "Buble sort" << endl;
		cout << "Counter: " << bubbleSort(arr, n) << endl;
		print(arr, n);

		ofstream resultFile;
		resultFile.open("bubleSort.csv");

		for (int i = n / 10; i <= n; i += 10) 
		{
			for (int j = 0; j <= i; j++) 
			{
				arr[j] = rand() % 10000 + 1;
			}
			counter = bubbleSort(arr, i);
			resultFile << i << ";" << counter << endl;
		}
		break;
	}
	case(2):
	{
		int counter = 0;

		cout << endl << "Insertion sort" << endl;
		cout << "Counter: " << insertionSort(arr, n) << endl;
		print(arr, n);

		ofstream resultFile;
		resultFile.open("insertionSort.csv");

		for (int i = 1; i <= n; i += 10) 
		{
			for (int j = 0; j <= i; j++) 
			{
				arr[j] = rand() % 10000 + 1;
			}
			counter = insertionSort(arr, i);
			resultFile << i << ";" << counter << endl;
		}
		break;
	}
	case(3):
	{
		int counter = 0;

		cout << endl << "Selection sort" << endl;
		cout << "Counter: " << selectionSort(arr, n) << endl;
		print(arr, n);

		ofstream resultFile;
		resultFile.open("selectionSort.csv");

		for (int i = 1; i <= n; i += 10) 
		{
			for (int j = 0; j <= i; j++) 
			{
				arr[j] = rand() % 10000 + 1;
			}
			counter = selectionSort(arr, i);
			resultFile << i << ";" << counter << endl;
		}
		break;
	}
	case(4): 
	{
		int counter = 0;

		cout << endl << "Merge sort" << endl;
		mergeSort(arr, 0, n - 1, counter);
		cout << "Counter: " << counter << endl;
		print(arr, n);

		ofstream resultFile;
		resultFile.open("mergeSort.csv");

		for (int i = 1; i <= n; i += 10) 
		{
			counter = 0;
			for (int j = 0; j <= i; j++) 
			{
				arr[j] = rand() % 10000 + 1;
			}
			mergeSort(arr, 0, i - 1, counter);
			resultFile << i << ";" << counter << endl;
		}		
		break;
	}
	case(5): 
	{
		int counter = 0;

		cout << endl << "Quicksort" << endl;
		quickSort(arr, 0, n-1, counter);
		cout << "Counter: " << counter << endl;
		print(arr, n);

		ofstream resultFile;
		resultFile.open("quickSort.csv");

		for (int i = 1; i <= n; i += 10) 
		{
			counter = 0;
			for (int j = 0; j <= i; j++) 
			{
				arr[j] = rand() % 10000 + 1;
			}
			quickSort(arr, 0, i-1, counter);
			resultFile << i << ";" << counter << endl;
		}
		break;
	}
	case(6): 
	{
		int counter = 0;

		cout << endl << "Heapsort" << endl;
		cout << "Counter: " << heapSort(arr, n) << endl;
		print(arr, n);

		ofstream resultFile;
		resultFile.open("heapSort.csv");

		for (int i = 1; i <= n; i += 10) 
		{
			for (int j = 0; j <= i; j++) 
			{
				arr[j] = rand() % 10000 + 1;
			}
			counter = heapSort(arr, i);
			resultFile << i << ";" << counter << endl;
		}
		break;
	}
	default:
		cout << "Wrong choice! " << endl;
	}

	system("pause");
	return 0;
}