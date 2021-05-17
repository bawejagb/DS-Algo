/*
Ford-Fulkerson algorithm

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

bool BFS_PathExist(vector<vector<int>> G, int s, int t, int N, int parent[]){
    bool visit[N]{};
    queue<int> qt;
    qt.push(s);
    while(!qt.empty()){
        int u = qt.front();
        visit[u] = 1;
        qt.pop();
        for(int i = 0; i < N; i++){
            if(G[u][i] > 0 && !visit[i]){
                qt.push(i);
                parent[i] = u;
                if(i == t)
                    return 1;
                visit[i] = 1;
            }
        }
    }
    return 0;
}   

int FordFulkerson(vector<vector<int>> G, int s, int t, int N){
    int maxFlow = 0;
    int parent[N]{};
    while(BFS_PathExist(G, s, t, N, parent)){
        int u, minFlow = INT_MAX;
        for(int i = t; i != s; i = parent[i]){
            u = parent[i];
            minFlow = min(minFlow, G[u][i]);
        }
        for(int i = t; i != s; i = parent[i]){
            u = parent[i];
            G[i][u] += minFlow;
            G[u][i] -= minFlow;
        }
        maxFlow += minFlow;
    }
    return maxFlow;
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int size, edges, n1, n2, cap;
    cin >> size;
    cin >> edges;
    vector<vector<int>> graph(size,vector<int>(size,0));
    for(int i = 0; i < edges; i++){
        cin >> n1 >> n2 >> cap;
        graph[n1][n2] = cap;
    }
    int maxFlow = 0;
    maxFlow = FordFulkerson(graph, 0, 5, size);
    cout << "Max Flow: " << maxFlow;
    return 0;
}