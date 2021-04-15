/*
Binary Search Iterative Algo
Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

int BinarySearch(int val, int arr[], int end){
    int mid, start;
    start = 0; 
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == val)
            return mid;
        if(arr[mid] < val)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main(){
    int res, size, val, select;
    int arr[] = {2,4,6,8,10};
    size = sizeof(arr)/sizeof(arr[0]);
    while(1){
        cout << "\nSelect option:\n"
        "1. Binary Search\n2. Exit\nIN>> ";
        cin >> select;
        switch (select){
            case 1:{ // Binary Search
                cout << "Enter a number to search from an array: ";
                cin >> val;
                cout << "OUT>> ";
                res = BinarySearch(val, arr, size-1);
                if(res != -1)
                    cout << "Present at Index: " << res << endl;
                else
                    cout << "Not present\n";
                break;
            }
            default:{
                exit(0);
            }
        }
    }
    return 0;
}