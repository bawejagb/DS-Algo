/*
Radix Sort
:The idea of Radix Sort is to do expr by expr sort starting 
from least significant expr to most significant expr. 
Radix sort uses counting sort as a subroutine to sort 
positive elements.
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

void CountingSort(int n, int arr[], int expr)
{
    int temp[n], count[10] = {0};    
    for(int i = 0; i < n; i++)
        count[(arr[i]/expr)%10]++;
    for(int i = 1; i <10; i++)
        count[i] = count[i-1] + count[i];
    for(int i = n-1; i >= 0; i--)
        temp[--count[(arr[i]/expr)%10]] = arr[i]; 
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}

void RadixSort(int n, int arr[])
{
    int expr, max;
    max = arr[0];
    for(int i = 1; i < n; i++)
        if(max < arr[i])
            max = arr[i];
    for(int expr = 1; max / expr > 0; expr *= 10)
        CountingSort(n, arr, expr);
}

main()
{
    int size = 10;  //Sample Data array size
     int arr[size] = {170, 45, 75, 90, 802, 24, 2, 66, 1111, 9};   //Sample Data Set
     cout << "Unsorted List:\n";
     display(size, arr);
     RadixSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}