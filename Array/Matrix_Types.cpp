/*
Space required to store any two-dimensional array is 
number of row X number of column, Assuming array is used 
to store elements of the following matrices,implement 
an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix

Made By : Gaurav baweja
*/
#include <iostream>
using namespace std;
int* Diagonal(int);
int* Symmetric(int);
int* TriDiagonal(int);
int* LowerTrianglular(int);
int* UpperTrianglular(int);

main()
{
	int a;
	int size;
	int *matrix;
	cout << "Enter a number to create below matrix:\n"
			"1. Diagonal Matrix\n"
			"2. Tri-diagonal Matrix\n"
			"3. Lower triangular Matrix\n"
			"4. Upper triangular Matrix\n"
			"5. Symmetric Matrix\n\n";
	while (1)
	{
		cout << "Select operation: ";
		cin >> a;
		switch (a)
		{
			case 1:// Diagonal
				{
					cout << "Enter a size of Diagonal matrix nXn: ";
					cin >> size;
					matrix = Diagonal(size);
					break;
				}
			case 2:// Tri-diagonal
				{
					cout << "Enter a size of TriDiagonal matrix nXn: ";
					cin >> size;
					matrix = TriDiagonal(size);
					break;
				}
			case 3:// Lower triangular
				{
					cout << "Enter a size of Lower triangular matrix nXn: ";
					cin >> size;
					matrix = LowerTrianglular(size);
					break;
				}
			case 4:// Upper triangular
				{
					cout << "Enter a size of Upper triangular matrix nXn: ";
					cin >> size;
					matrix = UpperTrianglular(size);
					break;
				}
			case 5:// Symmetric
				{
					cout << "Enter a size of Symmetric matrix nXn: ";
					cin >> size;
					matrix = Symmetric(size);
					break;
				}
			default:// EXIT
				{
					exit(0);
					break;
				}
		}
	}
}

int* Diagonal(int size)
{
	int* mat = new int [size];
	
	for (int i = 0; i < size; i++)
	{
		cout << "Enter value at " << i << "X" << i << ": ";
		cin >> mat[i];
	}
	cout << "\nDiagonal matrix of " << size << "X" << size << " is:\n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				cout << mat[i] << ' ';
			else
				cout << 0 << ' ';
		}
	cout << endl;
	}
	cout << endl;
	
	return mat;
}

int* TriDiagonal(int size)
{
	int element_size = 3 * size - 2;
	int* mat = new int [element_size];
	int count = 0;
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
	{
		if (abs(i - j) <= 1)
		{
			cout << "Enter value at " << i << "X" << j << ": ";
			cin >> mat[count];
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (abs(i - j) <= 1)
			{
				cout << mat[count] << ' ';
				count++;
			}
			else
				cout << 0 << ' ';
		}
		cout << endl;
	}
	return mat;
}

int* LowerTrianglular(int size)
{
	int element_size = (size+1)*(size)/2;
	int* mat = new int [element_size];
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
	{
		if (j <= i)
		{
			cout << "Enter value at " << i << "X" << j << ": ";
			cin >> mat[j + i + (i - 1)*i/2];
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j <= i)
				cout << mat[j + i + (i - 1)*i/2] << ' ';
			else
				cout << 0 <<  ' ';
		}
		cout << endl;
	}
	return mat;
}

int* UpperTrianglular(int size)
{
	int element_size = (size+1)*(size)/2;
	int* mat = new int [element_size];
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
	{
		if (j >= i)
		{
			cout << "Enter value at " << i << "X" << j << ": ";
			cin >> mat[j + i*(size - 1) - (i - 1)*i/2];
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j >= i)
				cout << mat[j + i*(size - 1) - (i - 1)*i/2] << ' ';
			else
				cout << 0 <<  ' ';
		}
		cout << endl;
	}
	return mat;
}

int* Symmetric(int size)
{
	int element_size = (size+1)*(size)/2;
	int* mat = new int [element_size];
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
	{
		if (j >= i)
		{
			cout << "Enter value at " << i << "X" << j << ": ";
			cin >> mat[j + i* (size - 1) - i*(i - 1)/2];
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j >= i)
				cout << mat[j + i * (size - 1) - (i - 1)*i/2] << ' ';
			else
				cout << mat[i + j * (size - 1) - (j - 1)*j/2] <<  ' ';
		}
		cout << endl;
	}
	return mat;
}
