/*
Quick Sort Recursive Algo
Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int PvtPosition(int arr[], int start, int end){
    int PI = start;
    for(int i = start; i < end; i++){
        if(arr[i] < arr[end]){
            swap(&arr[i],&arr[PI]);
            PI++;
        }
    }
    swap(&arr[PI], &arr[end]);
    return PI;
}

void QuickSort(int arr[], int start, int end){
    if(start < end){
        int PI = PvtPosition(arr, start, end);
        QuickSort(arr, start, PI-1);
        QuickSort(arr, PI+1, end);
    }
}

int main(){
    int res, size, val, select;
    /* int arr[] = {2,1,4,5,3};
    size = sizeof(arr)/sizeof(arr[0]); */
    cout << "Array Size: ";
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    QuickSort(arr, 0, size-1);
    cout << "After sort:\n";
    for(int i = 0 ; i < size; i++)
        cout << arr[i] << ' ';
    return 0;
}