/*
Merge Sort Iterative Algo
Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int temp[right-left+1];
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++,k++;
    }
    while(j <= right){
        temp[k] = arr[j];
        j++,k++;
    }
    for(i = left, k = 0; i <= right; i++){
        arr[i] = temp[k];
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left == right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    int res, size, val, select;
    //int arr[] = {2,1,4,5,3};
    //size = sizeof(arr)/sizeof(arr[0]);
    cout << "Array Size: ";
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    mergeSort(arr, 0, size-1);
    cout << "After sort:\n";
    for(int i = 0 ; i < size; i++)
        cout << arr[i] << ' ';
    return 0;
}