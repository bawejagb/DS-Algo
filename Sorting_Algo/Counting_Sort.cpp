/*
Counting sort is a linear time sorting algorithm 
that sort in O(n+k) time.
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

void CountingSort(int n, int arr[])
{
    int min, max, temp[n];
    min = max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(min > arr[i])
            min = arr[i];
        if(max < arr[i])
            max = arr[i];
    }
    int count[max-min+1] = {0};
    for(int i = 0; i < n; i++)
        count[arr[i]-min]++;
    for(int i = 1; i < max-min+1; i++)
        count[i] = count[i-1] + count[i];
    for(int i = n-1; i >= 0; i--)
        temp[--count[arr[i]-min]] = arr[i]; 
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}

main()
{
    int size = 10; //Sample Data array size
     int arr[size] = {10,8,5,9,12,9,9,3,4,2}; //Sample Data Set
     cout << "Unsorted List:\n";
     display(size, arr);
     CountingSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}