/*
n-queen Problem

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

void show(int Q[], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Q[i] == j)
                cout << 'Q' << i+1;
            else
                cout << " - ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkPlace(int r, int c, int Q[]){
    for(int i = 0; i < r; i++){
        if(Q[i] == c || abs(r-i) == abs(Q[i]-c))
            return false;
    }
    return true;
}

void NQueen(int k, int N, int Qc[]){
    for(int i = 0; i < N; i++){
        if(checkPlace(k, i , Qc)){
            Qc[k] = i;
            if(k == N-1){
                show(Qc, N);
            }
            else
                NQueen(k+1, N, Qc);
        }
    }
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N;
    cin >> N;
    int Qc[N]{};
    NQueen(0, N, Qc);
    return 0;
}