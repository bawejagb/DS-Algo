/*
Find the Transpose of a Matrix

Made By : Gaurav baweja
*/
#include<iostream>
using namespace std;
#define r 3
#define c 3

void show(int, int, int*);
void transpose(int [r][c], int [c][r]);

main()
{
	int arr1[r][c] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int arr2[c][r] = {};
	cout << "Matrix is:\n";
	show(r, c, arr1[0]);
	transpose(arr1, arr2);
	cout << "Transpose of matrix is:\n";
	show(c, r, arr2[0]);
}

void show(int a, int b, int *arr)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << arr[i * b + j] << ' ';
		cout << endl;
	}
}
void transpose(int arr[r][c], int res[c][r])
{
	for(int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			res[i][j] = arr[j][i];
}
