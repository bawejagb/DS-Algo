/*
0/1 Knapsack Problem tuple method

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> Item;
vector<bool> res;
float maxProfit = 0;
int totalItems = 0;
bool sortbyRatio(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return ((double)a.second/a.first > (double)b.second/b.first);
}
float fractionKnapsack(vector<bool> &bestSet, int cap){
    vector<pair<int,int>> lis;
    for(int i = 0; i < bestSet.size(); i++)
        if(bestSet[i])
            lis.push_back(Item[i]);
    sort(lis.begin(), lis.end(), sortbyRatio);
    pair<int, int> it;
    int size = lis.size();
    int wt;
    float sum = 0;
    for(int i = 0; cap > 0 && i < size; i++){
        it = lis[i];
        wt = min(cap, it.first);
        cap -= wt;
        sum += ((double)wt*it.second/it.first);
    }
    return sum;
}

void Knapsack(int idx, int weight, float profit, vector<bool> bestSet, int cap){
    
    if(idx == bestSet.size() || weight <= 0){
        if(weight >= 0 && profit > maxProfit){
            maxProfit = profit;
            res = bestSet;
            totalItems = idx;
        }
        return;
        }
    if(weight - Item[idx].first >= 0 && profit >= maxProfit)
         Knapsack(idx+1, weight-Item[idx].first, profit, bestSet, cap);
    bestSet[idx] = 0;
    profit = fractionKnapsack(bestSet, cap);
    Knapsack(idx+1, weight, profit, bestSet, cap);
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N, cap;
    cin >> N >> cap;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b; // Wt, Val
        Item.push_back({a,b});
    }
    sort(Item.begin(), Item.end(), sortbyRatio);
    int cost = 0;
    vector<bool> bestSet(N,1);
    //res.resize(N);
    float profit = fractionKnapsack(bestSet, cap);
    Knapsack(0, cap, profit, bestSet, cap);
    for(int i = 0; i < totalItems; i++)
        if(res[i])
            cost += Item[i].second;
    cout << "Total Cost: " << cost;
    return 0;
}