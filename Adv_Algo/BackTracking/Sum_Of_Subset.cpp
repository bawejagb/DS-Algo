/*
Sum-of-Subsets Problem

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> res;
void show(){
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
}

bool checkFeasible(int St[], int W, int wt, int total, int idx){
    return ((wt + total) >= W) && ((wt + St[idx]) <= W);
}

void SumOfSubset(int St[], int N, int W, int wt, int total, int idx){
    //cout << "(" << wt << "," << total << ")";
    if(wt == W){
        show();
        return;
    }
    if(idx >= N)
        return;
    if(checkFeasible(St, W, wt, total, idx)){
        res.push_back(St[idx]);
        SumOfSubset(St, N, W, wt+St[idx], total-St[idx], idx+1);
        res.pop_back();
        SumOfSubset(St, N, W, wt, total-St[idx], idx+1);
    }
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N, W, total = 0;
    cin >> N >> W;
    int St[N];
    for(int i = 0; i < N; i++){
        cin >> St[i];
        total += St[i];
    }
    sort(St, St+N);
    SumOfSubset(St, N, W, 0, total, 0);
    return 0;
}