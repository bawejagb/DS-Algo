/*
0/1 Knapsack Problem Recrusive

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int Knapsack(vector<int> &Wt, vector<int> &Val, int W, int N, int idx){
    if(idx == N || W == 0)
        return 0;
    if(dp[idx][W] != -1)
        return dp[idx][W];
    if(Wt[idx] > W)
        return dp[idx][W] = Knapsack(Wt, Val, W, N, idx+1);
    return dp[idx][W] = max(Val[idx]+Knapsack(Wt, Val, W-Wt[idx], N, idx+1),
                             Knapsack(Wt, Val, W, N, idx+1));

}


#define OFFLINE_JUDGE 0
main(){
    #if OFFLINE_JUDGE > 0
    freopen("../input.txt","r", stdin);
    freopen("../output.txt","w", stdout);
    #endif
    int N, W;
    cin >> N >> W;
    vector<int> Wt(N), Val(N);
    for(int i = 0; i < N; i++)
        cin >> Wt[i] >> Val[i];
    dp.resize(N,vector<int>(W+1,-1));
    int max_val = Knapsack(Wt, Val, W, N, 0);
    cout << "Total Value: " << max_val;
    return 0;
}