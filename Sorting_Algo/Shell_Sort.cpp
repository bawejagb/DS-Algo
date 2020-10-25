/*
Shell Sort
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

void ShellSort(int size, int arr[])
{
    for(int gap = size/2; gap >= 1; gap = gap/2)
    {
        for(int i = gap; i < size; i++)
        {
            int j, min = arr[i];
            for(j = i - gap; j >= 0 && arr[j] > min; j -= gap)
                arr[j+gap] = arr[j];
            arr[j+gap] = min;
        }
    }
}

main()
{
    int size = 10;
     int arr[size] = {1,8,5,9,10,7,6,3,4,2};
     cout << "Unsorted List:\n";
     display(size, arr);
     ShellSort(size, arr);
     cout << "Sorted List:\n";
     display(size, arr);
     return 0;
}