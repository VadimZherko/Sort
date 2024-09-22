#include <iostream>

using namespace std;

void swap(int*, int*);
void fill_array(int*, int);
void print_array(int*, int);
void bubble_sort(int*, int);
void quick_sort(int*, int, int);
void insertion_sort(int*, int);

int main()
{
	setlocale(LC_ALL, "ru");
	
	int size;
	cout << "Enter array size";
	cin >> size;

	int* array = new int[size] {0};
	fill_array(array, size);
	cout << "Initial array:";
	print_array(array, size);
	cout << endl;

	while (true)
	{
		cout << "\n1.BubbleSort\n2.Quick_Sort\n3.InsertionSort\nВыберить сортировку.";
		int number = 0;
		cin >> number;
		switch (number) {
		case 1:
			bubble_sort(array, size);
			cout << "\nSorting result:" << endl;
			print_array(array, size);
			break;
		case 2:
			quick_sort(array, 0, size - 1);
			cout << "\nSorting result:" << endl;
			print_array(array, size);
			break;
		case 3:
			insertion_sort(array, size);
			cout << "\nSorting result:" << endl;
			print_array(array, size);
			break;
		default:
			cout << "Something's wrong.";
		}
	}

	delete array;
}

void print_array(int* array, int size)
{


	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}

	cout << endl;
}

void fill_array(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand();
	}
}

void swap(int &first, int &second)
{
	int temp = first;
	first = second;
	second = temp;
}

void bubble_sort(int* array,int size)
{
	int start_size = size;
	
	for (; size != 1; size--)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

void quick_sort(int* array, int first_ind, int size )
{
	if (first_ind < size)
	{
		int sup_elem = array[first_ind + (size - first_ind) / 2];
		int i = first_ind, j = size;

		
			while (array[i] < sup_elem) {
				i++;
			}
			while (array[j] > sup_elem) {
				j--;
			}
			if (i <= j) {
				swap(array[i], array[j]);
				i++;
				j--;
			}

		if (first_ind < j) quick_sort(array, first_ind, j);
		if (i < size) quick_sort(array, i, size);
	}
}

void insertion_sort(int* array, int size) 
{
	for (int i = 1; i < size; i++) 
	{
		int key = array[i];
		int j = i - 1;

		while (j >= 0 && array[j] > key) 
		{
			array[j + 1] = array[j];
			j--;
		}
		array[++j] = key;
	}
}
