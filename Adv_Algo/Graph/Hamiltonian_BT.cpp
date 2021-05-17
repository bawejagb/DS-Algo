/*
Hamiltonian path algorithm

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

void NextValue(int V, vector<int> &R, vector<vector<bool>> &G){
    int i;
    while(1){
        R[V] = (R[V]+1) % (R.size());
        if(R[V] == 0)  return;
        if(G[R[V-1]][R[V]] == 1){
            for(i = 1; i < V; i++)
                if(R[i] == R[V]) break;
            if(i == V && (V < R.size()-1 || (V == R.size()-1 && G[R[R.size()-1]][R[1]] == 1)))
                return;
        }
    }
}

void Hamiltonian(int V, vector<int> &R, vector<vector<bool>> &G){
    while(1){
        NextValue(V, R, G);
        if(R[V] == 0) return;
        if(V == R.size()-1){
            for(int i = 1; i < R.size(); i++)
                cout << R[i] << ' ';
            cout << endl;
        }
        else
            Hamiltonian(V+1, R, G);
    }
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int size, edges, n1, n2;
    cin >> size;
    cin >> edges;
    vector<vector<bool>> graph(size+1,vector<bool>(size+1,0));
    for(int i = 0; i < edges; i++){
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
        graph[n2][n1] = 1;
    }
    vector<int> out(size+1, 0);
    out[1] = 1;
    Hamiltonian(2, out, graph);
    
    return 0;
}