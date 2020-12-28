/*
Write a program to represent a graph using adjacency 
list and perform basic operations like degree (in/out) 
of a vertex, adjacent vertices, number of edges, etc.

Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
    int vertex;
    Node* next;
    Node(): next{NULL}{}
};

class AdjList
{
    int vx_count;
    public:
    Node** head;
    AdjList(int count)
    {
        vx_count = count;
        head = new Node*[count]();
    }
    void AddEdge(int start_vx, int end_vx)
    {
        Node* newNode = new Node();
        newNode->vertex = end_vx;
        Node *temp = head[start_vx];
        if(!temp)
            head[start_vx]=newNode;
        else
        {
            while(temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void degIn(int vt)
    {
        int deg_in = 0;
        for(int i = 0; i < vx_count; i++)
        {
            Node *temp = head[i];
            while(temp)
            {
                if(temp->vertex == vt)
                    deg_in++;
                temp = temp->next;
            }
        }
        cout << "In Degree of " << vt << " : " << deg_in << endl;
    }
    void degOut(int vt)
    {
        int deg_out = 0;
        Node *temp = head[vt];
        while(temp)
        {
            deg_out++;
            temp = temp->next;
        }
        cout << "Out Degree of " << vt << " : " << deg_out << endl;
    }
    void adjVertex(int vt)
    {
        Node *temp = head[vt];
        if(temp)
        {
            cout << "Adjacent Vertex of " << vt << " : ";
            while(temp)
            {
                cout << temp->vertex << ' ';
                temp = temp->next;
            }
        }
        else
            cout << "No adjacent vertex!";
        cout << endl;
    }
    void edges()
    {
        int total_edges = 0;
        for(int i = 0; i < vx_count; i++)
        {
            Node *temp = head[i];
            while(temp)
            {
                if(temp->vertex != i)
                    total_edges++;
                temp = temp->next;
            }
        }
        cout << "Total edges of graph : " << total_edges << endl;
    }
};
main()
{
    AdjList graph(5);
    graph.AddEdge(0,1);
    graph.AddEdge(1,1);
    graph.AddEdge(2,1);
    graph.AddEdge(3,1);
    graph.AddEdge(4,1);
    graph.AddEdge(0,2);
    graph.degIn(2);
    graph.degOut(1);
    graph.adjVertex(0);
    graph.edges();
    return 0;
}