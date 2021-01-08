/*
Find the matrix multiplication

Made By : Gaurav baweja
*/
#include <iostream>
using namespace std;
#define a1 2
#define a2 3
#define b1 3
#define b2 2

void matrix_mul(int [a1][a2], int [b1][b2], int [a1][b2]);
void show_matrix(int, int, int*);

int main()
{
	int matrix1[a1][a2] = {{1,2,3}, {4,5,6}};
	int matrix2[b1][b2] = {{1,2}, {3,4}, {5,6}};	
	int result [a1][b2] = {0};
	
	if (a2 == b1)
	{
		cout << "Matrix 1 is: \n";
		show_matrix(a1, a2, matrix1[0]);
		cout << "Matrix 2 is: \n";
		show_matrix(b1, b2, matrix2[0]);
		matrix_mul(matrix1, matrix2, result);
		cout << "Matrix multiplication is:" << endl;
		show_matrix(a1, b2, result[0]);
	}
	else
		cout << "Matrix cannot be multiplied!";
}
void matrix_mul(int arr1[a1][a2], int arr2[b1][b2], int out[a1][b2])
{
	for (int i = 0; i < a1; i++) // result row
		for (int j = 0; j < b2; j++) // result column
			for (int l = 0; l < b1; l++) // addition loop
				out[i][j] += (arr1[i][l] * arr2[l][j]);
	
}
void show_matrix(int a, int b, int *arr)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << arr[i * b + j] << ' ';
		cout << endl;
	}
}
