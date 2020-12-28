/*
Write a program to implement Floyd–Warshall's shortest path algorithm.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

class GRAPH
{
    public:
    vector<vector<int> > adjMax;
    int size;
    GRAPH(int s)
    {
        size = s;
        adjMax.resize(size,vector<int>(size,0));
    }  
    void addEdge(int v1, int v2, int dis, bool bdir=false)
    {
        adjMax[v1][v2] = dis;
        if(bdir)
            adjMax[v2][v1] = dis;
    }
    void showAdj()
    {
        cout << "Adjacent Matrix\n";
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                cout << adjMax[i][j] << "  ";
            cout << endl;
        }
    }
};

void FloydWarshall(vector<vector<int> > adjMax)
{
    int size = adjMax.size();
    vector<vector<int> > resMax(size, vector<int>(size, INT_MAX));
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == j)
                resMax[i][j] = 0;
            else if(adjMax[i][j] != 0)
                resMax[i][j] = adjMax[i][j];
        }
    }
    for(int k = 0; k < size; k++)
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                if(resMax[i][k] != INT_MAX && resMax[k][j] != INT_MAX)
                    resMax[i][j] = min(resMax[i][j], resMax[i][k] + resMax[k][j]);
                    
     cout << "All shotest path Adjacent Matrix\n";
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                cout << resMax[i][j] << "  ";
            cout << endl;
        }
}

main()
{
    GRAPH g(5);
    g.addEdge(0, 1, 3);
    g.addEdge(2, 1, 4);
    g.addEdge(0, 4, -4);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 7);
    g.addEdge(3, 2, -5);
    g.addEdge(3, 0, 2);
    g.addEdge(4, 3, 6);
    g.showAdj();
    FloydWarshall(g.adjMax);
    return 0;
}