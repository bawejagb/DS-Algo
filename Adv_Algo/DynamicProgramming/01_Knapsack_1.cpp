/*
0/1 Knapsack Problem Tabulation

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

vector<bool> Knapsack_01(int W[],int P[],int N,int Cap){	
	int dp[N+1][Cap+1]{};
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= Cap; j++){
			if(j < W[i-1])
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			else
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i-1]]+P[i-1]);
		}
	}
	vector<bool> res(N,0);
	int a,b;
	a = N;
	b = Cap;
	/* for(int i = 0; i <= N; i++){
		for(int j = 0; j <= Cap; j++)
			cout << dp[i][j] << '|';
		cout << endl;
	} */
	while(a > 0 && b > 0){
		while(a > 0 && b > 0 && dp[a-1][b] == dp[a][b]){
			a--;
		}
		res[a-1] = 1;
		b -= W[a-1];
		a--;
	}
	return res;
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N, Cap;
	cin >> N >> Cap;
	int P[N];
	int W[N];
	for(int i = 0; i < N; i++){
		cin >> W[i] >> P[i];
	}
	vector<bool> res = Knapsack_01(W,P,N,Cap);
	int sum = 0;
	cout << "W|P\n";
	for(int i = 0; i < N; i++){
		if(res[i] == 1){
			cout << W[i] << '|' << P[i] << endl;
			sum += P[i];
		}
	}
	cout << "Total profit: " << sum;
    return 0;
}