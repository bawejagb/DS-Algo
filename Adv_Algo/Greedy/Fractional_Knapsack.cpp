#include<bits/stdc++.h>
using namespace std;

struct item{
    int id, profit, weight;
};

bool ItemCmp(item a, item b){
    return ((double)a.profit/a.weight > (double)b.profit/b.weight);
}

float FindItemLis(item lis[], int size, int cap){
    sort(lis, lis + size, ItemCmp);
    item it;
    int wt;
    float sum = 0;
    for(int i = 0; cap > 0 && i < size; i++){
        it = lis[i];
        wt = min(cap, it.weight);
        cap -= wt;
        sum += ((double)wt*it.profit/it.weight);
    }
    return sum;
}


main(){
    int size, cap;
    cout << "Enter Capacity: ";
    cin >> cap;
    cout << "Number of Items: ";
    cin >> size;
    item lis[size];
    cout << "ItemID  Weight  Profit\n";
    for(int i = 0; i < size; i++){
        cout << i+1 << ". ";
        lis[i].id = i+1;
        cin >> lis[i].weight >> lis[i].profit;
    }
    float res = FindItemLis(lis, size, cap);
    cout << "Total Profit: " << res;
    return 0;
}