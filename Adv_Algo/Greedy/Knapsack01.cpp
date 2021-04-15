#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>, int> dp;

int Knapsack_basic(int val[], int wt[], int W, int n){
    if(W == 0 || n == 0)    return 0;
    if(wt[n-1] > W) return Knapsack_basic(val, wt, W, n-1);
    else return max(val[n-1]+Knapsack_basic(val,wt,W-wt[n-1],n-1),
                    Knapsack_basic(val,wt,W,n-1));
}

int Knapsack_dp(int val[], int wt[], int W, int n){
    if(W == 0 || n == 0)    return 0;
    if(dp.find({W,n}) != dp.end())  return dp[{W,n}];
    if(wt[n-1] > W)
        dp[{W,n}] = Knapsack_basic(val, wt, W, n-1);
    else 
        dp[{W,n}] = max(val[n-1]+Knapsack_basic(val,wt,W-wt[n-1],n-1),
                    Knapsack_basic(val,wt,W,n-1));
    return dp[{W,n}];
}

int Knapsack_tab(int val[], int wt[], int W, int n){
    int tab[n+1][W+1]{};
    int max_val = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(W >= wt[i-1])
                tab[i][j] = max(tab[i-1][j], tab[i-1][W-wt[i-1]]+val[i-1]);
            else
                tab[i][j] = tab[i-1][j];
            //cout << tab[i][j] << '|';
            if(max_val < tab[i][j])
                max_val = tab[i][j];
        }
        //cout << endl;
    }
    return max_val;
}

main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    //cout << Knapsack_basic(val, wt, W, n);
    //cout << Knapsack_dp(val, wt, W, n);
    cout << Knapsack_tab(val, wt, W, n);
    return 0;
}