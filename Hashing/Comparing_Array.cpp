/*
Write a program that, given an array A[] of n numbers and 
another number x, determines whether or not there exist 
two elements in A[] whose sum is exactly x.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

bool CheckPairSum(int[], int, int);

main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int sum = -5;
    int size = sizeof(arr)/sizeof(arr[0]);
    if(CheckPairSum(arr, size, sum))
        cout << "Sum of pairs exist in list!\n";
    else 
        cout << "Sum of pairs doesn't exist in list!\n";
    return 0;
}

bool CheckPairSum(int arr[], int size, int sum)
{
    unordered_set<int> st;
    for(int i = 0; i < size; i++)
    {
        if(st.find(sum-arr[i]) != st.end())
        {
            cout << "Pair: " << arr[i] << ',' << sum-arr[i] << endl;
            return 1;
        }
        st.insert(arr[i]);
    }
    return 0;
}