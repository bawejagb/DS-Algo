/*
Write a program to implement the following operations on a Sparse Matrix,
 assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.

Made By : Gaurav baweja
*/
#include <iostream>
using namespace std;
void Transpose();
void Addition();
void Multiplication();

class SparseMatrix
{
	int **mat;
	int row, col, len;
	
	public:
		SparseMatrix(int r, int c, int count)
		{
			row = r;
			col = c;
			len = 0;
			mat = new int *[count+1];
			for (int i = 0; i < count+ 1; i++)
				mat[i] = new int [3];
			insert(r, c, count);
		}
		void changeValue(int r, int c, int value)
		{
			if (r > row || c > col)
				cout << "Invalid Entry!";
			else
			{
				for (int i = 0; i < len; i++)
					if (mat[i][0] == r && mat[i][1] == c)
					{
						mat[i][2] = value;
						break;
					}
			}
		}
		void insert(int r, int c, int value)
		{
			if (r > row || c > col)
				cout << "Invalid Entry!";
			else
			{
				mat[len][0] = r;
				mat[len][1] = c;
				mat[len][2] = value;
				len++;
			}
		}
		void show()
		{
			cout << "R C V\n";
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < 3; j++)
					cout << mat[i][j] << ' ';
				cout << endl;
			}
		}
		void transpose()
		{
			int test[len-1][3] = {};
			int count[col] = {};
			int index[col] = {};
			for (int i = 1; i < len; i++)
				count[mat[i][1]]++;
			for (int i = 1; i < col; i++)
				index[i] = index[i-1] + count[i-1];
				
			for (int i = 1; i < len; i++)
			{
				int c = mat[i][1];
				test[index[c]][0] = c;
				test[index[c]][1] = mat[i][0];
				test[index[c]][2] = mat[i][2]; 
				index[c]++;
			}
			for (int i = 1; i < len; i++)
			{
				mat[i][0] =  test[i-1][0];
				mat[i][1] =  test[i-1][1];
				mat[i][2] =  test[i-1][2];
			}
		}
		
		SparseMatrix addition(SparseMatrix s)
		{
			int size = len + s.len - 2;
			SparseMatrix result(row, col, size);
			int a_count = 1;
			int b_count = 1;
			int r_count = 0;
			while (a_count < len && b_count < s.len)
			{
				if(mat[a_count][0] > s.mat[b_count][0] ||
					mat[a_count][0] == s.mat[b_count][0] &&
					mat[a_count][1] > s.mat[b_count][1])
				{
					result.insert(s.mat[b_count][0],
						s.mat[b_count][1],
						s.mat[b_count][2]);
					b_count++;
					r_count++;
				}
				else if(mat[a_count][0] < s.mat[b_count][0] ||
					mat[a_count][0] == s.mat[b_count][0] &&
					mat[a_count][1] < s.mat[b_count][1])
				{
					result.insert(mat[a_count][0],
						mat[a_count][1],
						mat[a_count][2]);
					a_count++;
					r_count++;
				}
				else
				{
					int temp;
					temp = mat[a_count][2] + s.mat[b_count][2];
					if (temp > 0)
						result.insert(mat[a_count][0],
							mat[a_count][1],
							temp);
					a_count++;
					b_count++;
					r_count++;
				}
			}
			while (a_count < len)
			{
				result.insert(mat[a_count][0],
							mat[a_count][1],
							mat[a_count][2]);
				a_count++;
				r_count++;
			}
			while (b_count < s.len)
			{
				result.insert(s.mat[b_count][0],
							s.mat[b_count][1],
							s.mat[b_count][2]);
				b_count++;
				r_count++;	
			}
			result.changeValue(row, col, r_count);
			return result;
		}
		
		SparseMatrix multiply(SparseMatrix s)
		{
			int size = row * s.col;
			int r_count = 0;
			SparseMatrix result(row, s.col, size);
			s.transpose();
			for (int i = 1; i < len;)
			{
				int r = mat[i][0];
				for (int j = 1; j < s.len;)
				{
					int c = s.mat[j][0];
					int sum = 0;
					int temp_a = i;
					int temp_b = j;
					while(temp_a < len && temp_b < s.len &&
						mat[temp_a][0] == r && s.mat[temp_b][0] == c)
					{
						if (mat[temp_a][1] < s.mat[temp_b][1])
							temp_a++;
						else if (mat[temp_a][1] > s.mat[temp_b][1])
							temp_b++;
						else
						{
							sum += mat[temp_a][2] * s.mat[temp_b][2];
							temp_a++;
							temp_b++;
						}
					}
					if (sum != 0)
					{
						result.insert(r, c, sum);
						r_count++;
					}
						
					while(j < s.len &&
						s.mat[j][0] == c)
						j++;
				}
				while(i < len &&
						mat[i][0] == r)
						i++;
			}
			result.changeValue(row, col, r_count);
			return result;
		}			
};

main()
{
	cout << "Select below Matrix operation\n"
			"(1) Transpose of a matrix\n"
			"(2) Addition of two matrices\n"
			"(3) Multiplication of two matrices\n\n";
	int opt;
	while (1)
	{
		cout << "Select opearation: ";
		cin >> opt;
		switch (opt)
		{
			case 1:// Transpose of a matrix
				{
					Transpose();
					break;
				}
			case 2:// Addition of two matrices
				{
					Addition();
					break;
				}
			case 3:// Multiplication of two matrices
				{
					Multiplication();
					break;
				}
			default:// EXIT
				{
					exit(0);
				}
		}
	}
	return 0;
}

void Transpose()
{
	int row, col, elements;
	cout << "Enter the number of rows, columns and elements in matrix\n";
	cout << "Rows: ";
	cin >> row;
	cout << "Columns: ";
	cin >> col;
	cout << "Elements: ";
	cin >> elements;
	if (elements <= row*col)
	{
		SparseMatrix s1(row, col, elements);
		cout << "Enter value of row, column & element:\n";
		int r, c, val;
		for (int i = 0; i < elements; i++)
		{
			cout << i + 1 << ". ";
			cin >> r >> c >> val;
			s1.insert(r, c, val);
		}
		cout << "Triplet of matrix:\n";
		s1.show();
		s1.transpose();
		cout << "Transpose of a matrx:\n";
		s1.show();
	}
	else
		cout << "Exceeds matrix elements count!\n\n";
	
}

void Addition()
{
	int row1, col1, elements1, row2, col2, elements2;
	cout << "Enter the number of rows, columns and elements in Matrix 1\n";
	cout << "Rows: ";
	cin >> row1;
	cout << "Columns: ";
	cin >> col1;
	cout << "Elements: ";
	cin >> elements1;
	cout << "Enter the number of rows, columns and elements in Matrix 2\n";
	cout << "Rows: ";
	cin >> row2;
	cout << "Columns: ";
	cin >> col2;
	cout << "Elements: ";
	cin >> elements2;
	if (row1 == row2 || col1 == col2)
	if (elements1 <= row1*col1 && elements2 <= row2*col2)
	{
		SparseMatrix s1(row1, col1, elements1);
		SparseMatrix s2(row2, col2, elements2);
		cout << "Enter value of row, column & element in Matrix 1:\n";
		int r, c, val;
		for (int i = 0; i < elements1; i++)
		{
			cout << i+1 << ". ";
			cin >> r >> c >> val;
			s1.insert(r, c, val);
		}
		cout << "Enter value of row, column & element in Matrix 2:\n";
		for (int i = 0; i < elements2; i++)
		{
			cout << i+1 << ". ";
			cin >> r >> c >> val;
			s2.insert(r, c, val);
		}
		cout << "Triplet of matrix1:\n";
		s1.show();
		cout << "Triplet of matrix2:\n";
		s2.show();
		SparseMatrix s3 = s1.addition(s2);
		cout << "Addition of Matrix 1 and Matrix 2:\n";
		s3.show();
	}
	else
		cout <<  "Exceeds matrix elements count!\n\n";
	else
		cout << "Matrix cannot be added!\n\n";
}

void Multiplication()
{
	int row1, col1, elements1, row2, col2, elements2;
	cout << "Enter the number of rows, columns and elements in Matrix 1\n";
	cout << "Rows: ";
	cin >> row1;
	cout << "Columns: ";
	cin >> col1;
	cout << "Elements: ";
	cin >> elements1;
	cout << "Enter the number of rows, columns and elements in Matrix 2\n";
	cout << "Rows: ";
	cin >> row2;
	cout << "Columns: ";
	cin >> col2;
	cout << "Elements: ";
	cin >> elements2;
	if (col1 == row2)
	if (elements1 <= row1*col1 && elements2 <= row2*col2)
	{
		SparseMatrix s1(row1, col1, elements1);
		SparseMatrix s2(row2, col2, elements2);
		cout << "Enter value of row, column & element in Matrix 1:\n";
		int r, c, val;
		for (int i = 0; i < elements1; i++)
		{
			cout << i+1 << ". ";
			cin >> r >> c >> val;
			s1.insert(r, c, val);
		}
		cout << "Enter value of row, column & element in Matrix 2:\n";
		for (int i = 0; i < elements2; i++)
		{
			cout << i+1 << ". ";
			cin >> r >> c >> val;
			s2.insert(r, c, val);
		}
		cout << "Triplet of matrix1:\n";
		s1.show();
		cout << "Triplet of matrix2:\n";
		s2.show();
		SparseMatrix s3 = s1.multiply(s2);
		cout << "Multiplication of Matrix 1 and Matrix 2:\n";
		s3.show();
	}
	else
		cout <<  "Exceeds matrix elements count!\n\n";
	else
		cout << "Matrix cannot be multiplied!\n\n";
}

