/*
Given a matrix of m * n elements (m rows, n columns),
 return all elements of the matrix in spiral order.

Made By : Gaurav baweja
*/
#include <iostream>
#define m 5
#define n 5
using namespace std;
void show(int [m][n]);
int* spiral(int [m][n]);

main()
{
	int mat[m][n] = {{1,2,3,4,5},
					{6,7,8,9,10},
					{11,12,13,14,15},
					{16,17,18,19,20},
					{21,22,23,24,25}};
	int * arr;
	cout << "Matrix elements are: \n";
	show(mat);
	cout << "Spiral order Matrix elements are: \n";
	arr = spiral(mat);
	for (int i = 0; i < m*n; i++)
		cout << arr[i] << ' ';
	return 0;
}

void show(int arr[m][n])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << "  ";
		cout << endl;
	}
}

int* spiral(int mat[m][n])
{
	int * arr = new int [m*n];
	int x = m;
	int y = n;
	int i = 0;
	int j = 0;
	int k = 0;
	int index = 0;
	while (i < x && j < y)
	{
		for (k = j; k < x; k++)
		{
			//cout << mat[i][k] << ' ';
			arr[index] = mat[i][k] ;
			index++;
		}
		i++;
		for (k = i; k < y; k++)
		{
			//cout << mat[k][y-1] << ' ';
			arr[index] = mat[k][y-1];
			index++;
		}
		y--;
		for (k = y-1; k >= j; k--)
		{
			//cout << mat[x-1][k] << ' ';
			arr[index] = mat[x-1][k];
			index++;
		}
		x--;
		for (k = x -1; k >= i; k--)
		{
			//cout << mat[k][j] << ' ';
			arr[index] = mat[k][j];
			index++;
		}
		j++;
		
	}
	return arr;
}
