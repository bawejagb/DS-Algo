//Welsh Powell Algorithm
/*
Graph Coloring 2 Problem

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> color;

void show(){
    for(int i = 0; i < color.size(); i++)
        cout << color[i] << ' ';
    cout << endl;
}

int GraphColoring(vector<vector<int>> Graph, int N){
    vector<pair<int,int>> deg(N);
    for(int i = 0; i < N; i++)
        deg[i] = {Graph[i].size(),i};
    sort(deg.rbegin(), deg.rend());
    int crom = 0;
    for(int i = 0; i < N; i++){
        int ver = deg[i].second;
        if(color[ver] != 0)
            continue;
        crom++;
        color[ver] = crom;
        for(int j = 0; j < N; j++){
            bool flag = 1;
            if(color[j] != 0)
                continue;
            for(auto k : Graph[j]){
                if(color[k] == crom)
                    flag = 0;
            }
            if(flag)
                color[j] = crom;
        }
    }
    return crom;
}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    int N, edges, a, b;
    cin >> N >> edges; // Vertices | edges
    vector<vector<int>> Graph(N);
    for(int i = 0; i < edges; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    color.resize(N, 0);
    int Cromatic = GraphColoring(Graph, N);
    cout << "Cromatic number: " << Cromatic;
    return 0;
}