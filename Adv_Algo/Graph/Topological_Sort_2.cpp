/*
Topological Sort Disjoint Set algorithm

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> G, int node, bool visit[], vector<int>& res){
    visit[node] = 1;
    for(int i = 0; i < G[node].size(); i++){
        if(!visit[G[node][i]])
            DFS(G, G[node][i], visit, res);
    }
    res.push_back(node);
}

vector<int> TopologicalSort(vector<vector<int>> G, int N){
    bool visit[N]{};
    vector<int> res;
    for(int i = 0; i < N; i++)
        if(!visit[i])
            DFS(G, i, visit, res);
    return res;
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N, edges, u, v;
    cin >> N;
    cin >> edges;
    vector<vector<int>> G(N, vector<int>());
    for(int i = 0; i < edges; i++){
        cin >> u >> v;
        G[u].push_back(v);
    }
    vector<int> out;
    out = TopologicalSort(G, N);
    for(int i = out.size()-1; i >= 0; i--)
        cout << out[i] << '>';
    cout << endl;
    return 0;
}