/*
0/1 Knapsack Problem 

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> Item;

bool sortbyRatio(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return ((double)a.second/a.first > (double)b.second/b.first);
}

int Knapsack(int idx, int weight){
    if(idx == Item.size() || weight <= 0)
        return 0;
    if(weight - Item[idx].first >= 0)
        return max(Item[idx].second + Knapsack(idx+1, weight-Item[idx].first),
                 Knapsack(idx+1, weight));
    else
        return Knapsack(idx+1, weight);
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
    int cost;
    cost = Knapsack(0, cap);
    cout << "Total Cost: " << cost;
    return 0;
}