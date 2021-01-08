/*
 Write a program to find a saddle point 
in a two-dimensional array. A saddle point 
in a numerical array is a number that is 
larger than or equalto every number in its 
column, and smaller than or equal to every 
number in its row.

Made By : Gaurav baweja
*/
#include <iostream>
#define m 3
#define n 4
using namespace std;
void show(int [m][n]);
void SaddlePoint(int [m][n]);
main()
{
	int mat[m][n] = {{11,9,12,14},
					{24,2,23,21},
					{15,6,7,228}
					};
	cout << "2D Array elements are: \n";
	show(mat);
	SaddlePoint(mat);
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

void SaddlePoint(int arr[m][n])
{
	int point1;
	int min_col = 0;
	int max_row = 0;
	int i;
	for (i = 0; i < m; i++)
	{
		point1 = arr[i][0];
		for (int j = 0; j < n; j++)
			if (point1 >= arr[i][j] )
			{
				point1 = arr[i][j];
				min_col = j;
				max_row = i; 
			}
		for (int j = 0; j < m; j++)
			if (point1 < arr[j][min_col] )
			{
				max_row  = j;
			}
		if(point1 == arr[max_row][min_col])
		{
			cout << "Saddle point in 2D array is: " << point1 << endl;
			break;
		}	
	}
	if(i == m)
		cout << "There is no saddle point in 2D array!" << endl;
}
