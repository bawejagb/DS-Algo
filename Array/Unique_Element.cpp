/*
Design the logic to remove the duplicate elements from an 
Array and after the deletion the array should contain the unique 
elements.

Made By : Gaurav baweja
*/
#include<iostream>
using namespace std;
void remove_duplicate(int *, int);
void show(int *, int);

int main()
{
	int arr[] = {1,1,1,2,2,2,2,6,7,8,9,9,9,1,1,1};
	int length = sizeof(arr)/sizeof(arr[0]);
	cout << "Elements of Array:\n";
	show(arr, length);
	cout << "Unique elements in array:\n";
	remove_duplicate(arr, length);
	show(arr, length);
	return 0;
}

void show(int * arr, int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void remove_duplicate(int *test_arr, int size)
{
	int test;
	for (int i = 0; i < size; i++)
	{
		test = test_arr[i];
		int flag = 0;
		for (int j = i+1; j < size; j++)
		{
			if (test == test_arr[j])
				flag++;	
			else if (flag)
				test_arr[j-flag] = test_arr[j];
		}
		for (int k = size - flag; k < size; k++)
			test_arr[k] = 0;
	}
}

/*
void remove_duplicate(int *test_arr, int size) // Time complexity: n
{
	int final_arr [size] = {};
	int max_value = 0;
	for (int i = 0; i < size; i++)
		if (max_value < test_arr[i])
			max_value = test_arr[i];
	int* temp_arr = new int [max_value];
	int index = 0;
	for (int i = 0; i < size; i++)
		{
			temp_arr[test_arr[i]]++;
			if (temp_arr[test_arr[i]] == 1)
			{
				final_arr[index] = test_arr[i];
				index++;
			}
		}
	for(int i = 0; i < size; i++)
		test_arr[i] = final_arr[i];
	delete (temp_arr);
	
}
*/
