/*
Eulerian path and circuit algorithm

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

void traverse(vector<vector<bool>> graph, vector<bool> &visit, int node){
    int size = graph.size();
    visit[node] = 1;
    for(int i = 0; i < size; i++){
        if(graph[node][i] && !visit[i])
            traverse(graph, visit, i);
    }
}

bool isConnected(vector<vector<bool>> graph){
    int size = graph.size();
    int len, node = 0;
    vector<bool> visit(size,0);
    for(int i = 0; i < size; i++){
        len = 0;
        for(int j = 0; j < size; j++){
            if(graph[i][j] == 1)
                len++;
        }
        if(len > 0){
            node = i;
            break;
        }
    }
    traverse(graph, visit, node);
    for(int i = 0; i < size; i++){
        if(!visit[i]){
            len = 0;
            for(int j = 0; j < size; j++){
                if(graph[i][j] == 1)
                    len++;
            }
            if(len > 0)
                return 0;
        }
    }
    return 1;
}

int isEulerian(vector<vector<bool>> graph){
    int size = graph.size();
    int deg, oddDeg = 0;
    if(!isConnected(graph))
        return 0;
    for(int i = 0; i < size; i++){
        deg = 0;
        for(int j = 0; j < size; j++){
            if(graph[i][j] == 1)
                deg++;
        }
        if(deg % 2 == 1)
            oddDeg++;
    }
    if(oddDeg == 0)
        return 2; 
    else if(oddDeg == 2)
        return 1;
    else
        return 0;
}

main(){
    int size, edges, n1, n2;
    cout << "Number of Nodes: ";
    cin >> size;
    cout << "Number of Edges: ";
    cin >> edges;
    cout << "Edge  Node1  Node2\n";
    vector<vector<bool>> graph(size,vector<bool>(size,0));
    for(int i = 0; i < edges; i++){
        cout << i+1 << ". ";
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
        graph[n2][n1] = 1;
    }
    int res = isEulerian(graph);
    if(res == 0)
        cout << "Not Eulerian!";
    else if(res == 1)
        cout << "Eulerian Path!";
    else
        cout << "Eulerian Circuit!";
    return 0;
}