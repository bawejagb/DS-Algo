/*
Selection Sort
:Put minimum value at the beginning
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

void SelectionSort(int size, int arr[])
{
    int min, max;
    for (int i = 0; i < size-i-1; i++)
    {
        min = i;
        max = size - i - 1;
        for (int j = i; j < size-i; j++)
        {
            if (arr[min] > arr[j])
                min = j;
            if (arr[max] < arr[j])
                max = j;
        }
        if(min != i && max != i)
            swap(&arr[i], &arr[min]);
        else 
        {
            swap(&arr[size - i - 1], &arr[max]);
            swap(&arr[i], &arr[min]);
            max = size - i - 1;
        }
        if(max != size - i - 1)
            swap(&arr[size - i - 1], &arr[max]);
    }
}

main()
{
    int size = 10;
     int arr[size] = {10,8,5,9,1,7,6,3,4,2};
     cout << "Unsorted List:\n";
     display(size, arr);
     SelectionSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}