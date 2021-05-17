/*
Graph Coloring 1 Problem

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

bool check(vector<vector<bool>> Graph, int N, int node, int c){
    for(int i = 0; i < N; i++){
        if(Graph[node][i] && c == res[i])
            return false;
    }
    return true;
}

bool GraphColoring(vector<vector<bool>> Graph, int N, int M, int node){
    if(node == N){
        show();
        return true;
    }
    bool flag = 0;
    for(int i = 1; i <= M; i++){
        if(check(Graph, N, node, i)){
            res[node] = i;
            if (GraphColoring(Graph, N, M, node + 1))
                flag = 1;
        }
    }
    return flag;
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N, M, edges, a, b;
    cin >> N >> M >> edges;
    vector<vector<bool>> Graph(N, vector<bool>(N, 0));
    for(int i = 0; i < edges; i++){
        cin >> a >> b;
        Graph[a][b] = 1;
        Graph[b][a] = 1;
    }
    res.resize(N, 0);
    if (GraphColoring(Graph, N, M, 0))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}