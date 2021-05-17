/*
Optimal Binary Search Tree Problem

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

void show(vector<vector<int>> dps, int a, int b,int K[]){
    if(a==b)
        return;
    else{
		cout << K[dps[a][b]-1] << '|';
        show(dps, a, dps[a][b]-1, K);
        show(dps, dps[a][b], b, K);
        
    }
}

int OBST(int K[], int F[], int N){
	int dp[N+1][N+1]{};
	int Fs[N+1]{};
	vector<vector<int>> dps(N+1, vector<int> (N+1, 0));
	for(int i = 1; i <= N; i++){
		Fs[i] += (Fs[i-1]+F[i-1]);
	}
	for(int l = 2; l <= N+1; l++){
		for(int i = 0; i <= N-l+1; i++){
			int j = i+l-1;
			dp[i][j] = INT_MAX;
			for(int k = i; k <= j; k++){
				int s = dp[i][k]+dp[k+1][j]+Fs[j]-Fs[i];
				if(s < dp[i][j]){
					dp[i][j] = s;
					dps[i][j] = k+1;
				}
			}
		}
	}
	/* for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++)
			cout << dp[i][j] << '|';
		cout << endl;
	} */
	show(dps,0,N, K);
	return dp[0][N];
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N;
	cin >> N;
	int K[N];
	int F[N];
	for(int i = 0; i < N; i++){
		cin >> K[i] >> F[i];
	}
	int total_cost = OBST(K, F, N);
	cout << "\nTotal Cost: " << total_cost;
    return 0;
}