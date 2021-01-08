/*
Given an integer A, generate a square matrix filled with
 elements from 1 to A2 in spiral order.

Made By : Gaurav baweja
*/
#include <iostream>
using namespace std;
class Spiral
{
	int a;
	int **mat;
	public:
		Spiral (int x)
		{
			a = x;
			mat = new int *[a];
			for (int i = 0; i < a; i++)
				mat[i] = new int [a];
		}
		void show()
		{
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < a; j++)
					cout << mat[i][j] << "  ";
				cout << endl;
			}
		}
		void make()
		{
			int x = a;
			int y = a;
			int i = 0;
			int j = 0;
			int k = 0;
			int count = 1;
			while( i < x && j < y)
			{
				for (k = j; k < y; k++)
					mat[i][k] = count++;
				i++;
				for (k = i; k < x; k++)
					mat[k][y-1] = count++;
				y--;
				for (k = y-1; k >= j; k--)
					mat[x-1][k] = count++;
				x--;
				for (k = x-1; k >=i; k--)
					mat[k][j] = count++;
				j++;
			}
		}
	~Spiral()
	{
		delete(mat);
	}
};

main()
{
	int a;
	while (1)
	{
		cout << " Enter number 'n' to generate" 
			"spiral square matrix nxn: ";
		cin >> a;
		if (a > 0)
			break;
		else
			cout << "Number cannot be <= 0 !\n";
	}
	Spiral s1(a);
	s1.make();
	s1.show();
	return 0;
}
