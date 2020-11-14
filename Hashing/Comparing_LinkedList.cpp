/*
Write a program that creates union and intersection lists 
from the two Linked Lists given as an input. 
The union list contains unique elements present in both the 
input Linked Lists and intersection list contains common 
elements present in the given lists. Order of elements in 
output lists doesn’t matter.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
main()
{
    forward_list<int> l1;
    forward_list<int> l2;
    l1.push_front(20);
    l1.push_front(4);
    l1.push_front(15);
    l1.push_front(10);
    l2.push_front(10);
    l2.push_front(2);
    l2.push_front(4);
    l2.push_front(8);
    unordered_map<int, int> mp;
    for(int &i : l1)
        mp[i]++;
    for(int &i : l2)
        mp[i]++;    
    forward_list<int> unLL;
    forward_list<int> inLL;
    for(auto i : mp)
    {
        if(i.second == 2)
            inLL.push_front(i.first);
        unLL.push_front(i.first);
    }
    cout << "Intersection of list:\n";
    for(int &i : inLL)
        cout << i << ' ';
    cout << endl; 
    cout << "Union of list:\n";
    for(int &i : unLL)
        cout << i << ' ';
    cout << endl;
}