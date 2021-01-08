/*
Develop a Menu driven program to demonstrate the following operations of
Arrays
��MENU��-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.SEARCH
6.EXIT

Made By : Gaurav baweja
*/

#include <iostream>
using namespace std;

class datalist
{
	int arr_size;
	int *arr;
	
	public:
		datalist(int size)
		{
			arr_size = size;
			arr = new int [arr_size]();
		}
		
		void create(int index)
		{
			int pc = index * 2;
			int *pa = new int [pc]();
			for (int i = 0; i < arr_size; i++)
				pa[i] = arr[i];
			delete(arr);
			arr = pa;
			arr_size = pc;
		}
		
		void display()
		{
			for (int i = 0; i < arr_size; i++)
			cout << arr[i] << ' ';
			cout << endl;
		}
		
		void insert(int data, int index)
		{
			if (index < 0)
				cout << "Index cannot be negative!";
			if (index >= arr_size)
			{
				create(index);
				insert(data, index);
			}
			else
				arr[index] = data;
		}
		
		void delete_(int index)
		{
			if (index < 0)
				cout << "Index cannot be negative!\n";
			if (index >= arr_size)
				cout << "Index out of range!\n";
			else
			{
				for (int i = index+1; i <= arr_size; i++)
					arr[i-1] = arr[i];
				arr[arr_size-1] = 0;
			}
		}
		
		void delete_(int * data)
		{
			int index;
			index = search(*data);
			if (index < 0)
				cout << *data << " is not in array!\n";
			else
				delete_(index);
		}
		
		int search(int data)
		{
			for (int i = 0;i < arr_size; i++)
			{
				if (arr[i] == data)
					return i;
			}
			return -1;
		}
};

int main()
{
	int a;
	datalist arr(1);
	
	cout << "--- MENU ---\n1. CREATE\n2. DISPLAY\n3. INSERT\n4. "
	 "DELETE\n5. SEARCH\n6. EXIT\n";
	
	while (1)
	{
		cout << "Select operation: ";
		cin >> a;
		switch (a)
		{
			case 1:// CREATE
				{
					cout << "Enter size of array: ";
					int size;
					cin >> size;
					arr = datalist(size);
					cout << "Array Created with size " << size << endl;
					break;
				}
			case 2:// DISPLAY
				{
					arr.display();
					break;
				}
			case 3:// INSERT
				{
					int data, index;
					cout << "Enter data value and index number: \n";
					cin >> data >> index;
					arr.insert(data, index);
					break;
				}
			case 4:// DELETE
				{
					int data;
					cout << "Enter data to delete: \n";
					cin >> data;
					arr.delete_(&data);
					cout << data << " deleted from array!\n";
					break;
				}
			case 5:// SEARCH
				{
					int data, index;
					cout << "Enter data to search in array: \n";
					cin >> data;
					index = arr.search(data);
					if( index < 0)
						cout << data << " is not in the array!\n";
					else
						cout << data << " is at index " << index << endl;
					break;
				}
			default:// EXIT
				{
					exit(0);
					break;
				}
		}
	}
	return 0;
}
