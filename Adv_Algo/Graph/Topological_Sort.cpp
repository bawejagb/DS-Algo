/*
Topological Sort algorithm

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> TopologicalSort(vector<vector<int>> G, int N){
    int cnt[N]{};
    vector<int> res;
    queue<int> qu;
    for(int i = 0; i < N; i++)
        for(auto v : G[i])
            cnt[v]++;
    for(int i = 0; i < N; i++)
        if(cnt[i] == 0)
            qu.push(i);
    while(!qu.empty()){
        int temp = qu.front();
        qu.pop();
        for(auto v : G[temp]){
            cnt[v]--;
            if(cnt[v] == 0)
                qu.push(v);
        }
        res.push_back(temp);
    }
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
    for(int i = 0; i < out.size(); i++)
        cout << out[i] << '>';
    cout << endl;
    return 0;
}