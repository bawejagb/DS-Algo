/*
Bubble Sort
:Putting largest element at the end
Made by: Gaurav Baweja
*/
#include<iostream>
using namespace std;

void display(int size, int arr[])
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int size, int arr[])
{
    int min, j;
    for (int i = 0; i < size; i++)
    {
        bool change_flag = 0;
        for(int j = 1; j <size - i; j++)
            if(arr[j-1] > arr[j])
            {
                swap(&arr[j-1], &arr[j]);
                change_flag = 1;
            }
        if(!change_flag)
            break;
    }
}
main()
{
    int size = 10;
     int arr[size] = {10,8,5,9,1,7,6,3,4,2};
     cout << "Unsorted List:\n";
     display(size, arr);
     BubbleSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}