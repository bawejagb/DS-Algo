/*
Quick Sort Iterative Algo
Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
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

void QuickSort(int arr[], int size){
    int st, PI, ed, i = 0;
    int front[size], end[size];
    front[0] = 0; end[0] = size - 1;
    while(i >= 0){
        st = front[i];
        ed = end[i];
        PI = PvtPosition(arr, st, ed);
        i--;
        if(PI-1 > st){
            i++; 
            front[i] = st;
            end[i] = PI-1;
        }
        if(PI+1 < ed){
            i++; 
            front[i] = PI+1;
            end[i] = ed;
        }
    }
}

int main(){
    int res, size, val, select;
    /* int arr[] = {2,1,4,5,3};
    size = sizeof(arr)/sizeof(arr[0]); */
    cout << "Array Size: ";
    cin >> size;
    int arr[size];
    cout << ">> ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    QuickSort(arr, size);
    cout << "After sort:\n";
    for(int i = 0 ; i < size; i++)
        cout << arr[i] << ' ';
    return 0;
}