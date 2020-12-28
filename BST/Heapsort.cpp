/*
Implement Heapsort (Increasing/Decreasing order).

Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int c = b;
    b = a;
    a = c;
}

void maxheapify(int arr[], int size, int index)
{
    int max_index = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < size && arr[left] > arr[max_index])
        max_index = left;
    if(right < size && arr[right] > arr[max_index])
        max_index = right;
    if(max_index != index)
    {
        swap(arr[index], arr[max_index]);
        maxheapify(arr, size, max_index);
    }
}

void minheapify(int arr[], int size, int index)
{
    int min_index = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < size && arr[left] < arr[min_index])
        min_index = left;
    if(right < size && arr[right] < arr[min_index])
        min_index = right;
    if(min_index != index)
    {
        swap(arr[index], arr[min_index]);
        minheapify(arr, size, min_index);
    }
}

void heapsort(int arr[], int size, bool max_min)
{
    for(int i = size/2 - 1; i >= 0; i--)
    {
        if(max_min)
            maxheapify(arr, size, i);
        else
            minheapify(arr, size, i);
    }
    for(int i = size-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        if(max_min)
            maxheapify(arr, i, 0);
        else
            minheapify(arr, i, 0);
    }
}

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

main()
{
    int arr[] = {5,2,10,19,6,1,11,15,3,9,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Before sort:\n";
    display(arr, size);
    heapsort(arr, size, 1);     // (1/0) Accending/Decending
    cout << "After sort:\n";
    display(arr, size);
    return 0;
}