/*
Reverse the elements of an array

Made By : Gaurav baweja

*/
#include <iostream>
using namespace std;

void show(int*, int);
void reverse(int*, int);
void swap(int*, int*);

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int length = sizeof(arr)/ sizeof(arr[0]);
	cout << "Elements of array:\n";
	show(arr, length);
	reverse(arr, length);
	cout << "Elements of reverse array:\n";
	show(arr, length);
}

void show(int *arr, int size)
{
	for(int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void reverse(int *arr, int size)
{
	for (int i = 0; i < size / 2; i++)
		swap(&arr[i], &arr[size-i-1]);
}

void swap(int *a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

