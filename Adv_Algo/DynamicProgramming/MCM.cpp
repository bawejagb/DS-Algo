/*
Matrix Chain Multiplication Problem

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

void show(vector<vector<int>> dps, int a, int b){
    if(a==b)
        cout << 'A' << a << ' ';
    else{
        cout << '(';
        show(dps, a, dps[a][b]);
        show(dps, dps[a][b]+1, b);
        cout << ')';
    }
}

int MCM(int dim[], int N){
    int dpm[N][N]{};
    vector<vector<int>> dps(N, vector<int> (N, 0));
    for(int l = 2; l < N; l++){
        for(int i = 1; i < N-l+1; i++){
            int j = i+l-1;
            dpm[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int a = dpm[i][k]+dpm[k+1][j]+dim[i-1]*dim[k]*dim[j];
                if(a < dpm[i][j]){
                    dpm[i][j] = a;
                    dps[i][j] = k;
                } 
            }
        }
    }
    /* for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			cout << dpm[i][j] << '|';
		cout << endl;
	} */
    show(dps,1,N-1);
    return dpm[1][N-1];
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N;
    cin >> N;
    int dim[N];
    for (int i = 0; i < N; i++)
        cin >> dim[i];
    int res;
    res = MCM(dim, N);
    cout << "\nTotal Mul: " << res;
    return 0;
}