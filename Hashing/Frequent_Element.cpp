/*
Write a program to determine the most 
frequent element an array. If there are multiple 
elements that are appearing the maximum number 
of times, then print any one of them.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

int FreqElement(int[], int);

main()
{
    int arr[] = {5, 8, 2, 1, 3, 2, 6, 5, 3, 2, 1, 8, 6, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Frequent Element: " << FreqElement(arr, size);
    return 0;
}

int FreqElement(int arr[], int size)
{
    int val, count = 0;
    unordered_map<int,int> hs;// Hash Table
    for(int i = 0; i < size; i++)
        hs[arr[i]]++;
    for(auto k : hs)
        if (count < k.second)
        {
            count = k.second;
            val = k.first;
        }
    return val;
}