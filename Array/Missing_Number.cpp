/*
Design the Logic to Find a Missing Number 
in a Sorted Array from 1 to n.

Made By : Gaurav baweja
*/
#include<iostream>
using namespace std;
void show(int*, int);
int find_missing(int*, int);

main()
{
	int arr[] = {1,2,3,4,5,6,7,8,10,11,12,13,14};
	int size = sizeof(arr) / sizeof(arr[0]);
	int missing;
	cout << "Elements in array:\n";
	show(arr, size);
	missing = find_missing(arr, size);
	if (missing <= 0)
		cout << "No missing number found!";
	else
		cout << "Missing number is " << missing;
}

void show(int* test_arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << test_arr[i] << ' ';
	cout << endl;
}

int find_missing(int* test_arr, int size)// Checking index
{
	int ref = 1;
	for (int i = 0; i < size; i++)
	{
		if (ref != test_arr[i])
			return ref;
		else
			ref++;
	}
	return 0;
}

/*
int find_missing(int* test_arr, int size)// Array sum difference
{
	int sum = (test_arr[size-1]) * (test_arr[size-1] + 1) / 2;	
	int res = 0;
	for (int i = 0; i < size; i++)
		res += test_arr[i];
	return sum - res;
}	
*/
/*
int find_missing(int* test_arr, int size)// XOR operation
{
	int res1 = 0;
	int res2 = 0;
	for (int i = 0; i < size; i++)
		res1 = res1 ^ test_arr[i];
	for (int i = 1; i <= test_arr[size-1]; i++)
		res2 = res2 ^ i;
		return (res1 ^ res2);
}
*/


