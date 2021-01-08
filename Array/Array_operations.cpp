/*
Write a program to find sum of every row 
and every column in a two-dimensional array.

Made By : Gaurav baweja
*/
#include <iostream>
using namespace std;
#define m 3
#define n 4
void show(int [m][n]);
void row_sum(int [m][n]);
void col_sum(int [m][n]);
main()
{
	int mat[m][n] = {{1,2,3,4},
					{5,6,7,8},
					{9,1,2,3}};
	cout << "Matrix elements are: \n";
	show(mat);
	row_sum(mat);
	col_sum(mat);
	return 0;
}

void show(int arr[m][n])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}

void row_sum(int arr[m][n])
{
	int sum;
	for (int i = 0; i < m; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
			sum += arr[i][j];
		cout << "Sum of row " << i+1 << " : " << sum << endl;
	}
}

void col_sum(int arr[m][n])
{
	int sum;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
			sum += arr[j][i];
		cout << "Sum of column " << i+1 << " : " << sum << endl;
	}
}
