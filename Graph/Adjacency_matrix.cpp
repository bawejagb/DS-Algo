/*
Write a program to represent a graph using adjacency 
matrix and perform basic operations like degree (in/out) 
of a vertex, adjacent vertices, number of edges, etc.

Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

class AdjMatrix
{
    int size;
    int **head;
    public:
    AdjMatrix(int s)
    {
        size = s;
        head = new int* [s];
        for(int i = 0; i < s; i++)
            head[i] = new int [s]();
    }
    void AddEdge(int start_vx, int end_vx)
    {
        head[start_vx][end_vx] = 1;
    }
    void degIn(int vt)
    {
        int deg_in = 0;
        for (int i = 0; i < size; i++)
            if(head[i][vt] == 1)
                deg_in++;
        cout << "In Degree of " << vt << " : " << deg_in << endl;
    }
    void degOut(int vt)
    {
        int deg_out = 0;
        for (int i = 0; i < size; i++)
            if(head[vt][i] == 1)
                deg_out++;
        cout << "Out Degree of " << vt << " : " << deg_out << endl;
    }
    void adjVertex(int vt)
    {
        bool status = 0;
        for(int i = 0; i < size; i++)
            if(head[vt][i] == 1)
            {
                cout << i << ' ';
                status = 1;
            }
        if(!status)
            cout << "No adjacent vertex!";
        cout << endl;
    }
    void edges()
    {
        int total_edges = 0;
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                if(head[i][j] == 1 && i != j)
                    total_edges++;
        cout << "Total edges of graph : " << total_edges << endl;
    }
};

main()
{
    AdjMatrix graph(5);
    graph.AddEdge(0,1);
    graph.AddEdge(1,1);
    graph.AddEdge(2,1);
    graph.AddEdge(3,1);
    graph.AddEdge(4,1);
    graph.AddEdge(0,2);
    graph.degIn(1);
    graph.degOut(1);
    graph.adjVertex(0);
    graph.edges();
    return 0;
}