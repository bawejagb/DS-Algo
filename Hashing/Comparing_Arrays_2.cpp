/*
You are provided with two arrays. 
Write a program to find numbers which 
are present in first array, 
but not present in the second array.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

main()
{
    int a[] = {1, 2, 3, 4, 5, 10};
    int b[] = {2, 3, 1, 0, 5};
    int a_size = sizeof(a)/sizeof(a[0]);
    int b_size = sizeof(b)/sizeof(b[0]);
    unordered_set<int> st;
    for (int i = 0; i < b_size; i++)
        st.insert(b[i]);
    cout << "Elements of A[] not present in B[]:\n";
    for(int i = 0; i <a_size; i++)
        if(st.find(a[i]) == st.end())
            cout << a[i] << ' ';
    return 0;
}

