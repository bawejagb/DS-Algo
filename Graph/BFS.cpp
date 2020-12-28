/*
Write a program to implement breadth first search algorithm.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class GRAPH
{
    map<T,list<T>> head;
    void backtrack(map<T,tuple<bool,int,T>> &lst, T start, T ct)
    {
        stack<T> st;
        while(ct != start)
        {
            st.push(ct);
            ct = get<2>(lst[ct]);
        }
        cout << "START->" << ct << '(' << get<1>(lst[ct]) << ")->";
        while(!st.empty())
        {
            cout << st.top() << '(' << get<1>(lst[st.top()]) << ")->";
            st.pop();
        }
        cout << "END\n";
    }
    public:
    void AddEdge(T start_vx, T end_vx)
    {
        head[start_vx].push_back(end_vx);
        head[end_vx].push_back(start_vx);
    }

    void BFS(T start, T end)
    {
        queue<T> qt;
        qt.push(start);
        map<T,tuple<bool,int,T>> visited;
        for(auto p : head)
            visited[p.first] = make_tuple(0,0,'\0');
        get<1>(visited[start]) = 0;
        get<2>(visited[start]) = 0;
        while(!qt.empty())
        {
            T current = qt.front();
            qt.pop();
            cout << current << '('<< get<1>(visited[current]) << ") ";
            get<0>(visited[current]) = 1;
            for(T adj : head[current])
                if(!get<0>(visited[adj]))
                    {
                        qt.push(adj);
                        get<0>(visited[adj]) = 1;
                        get<1>(visited[adj]) = get<1>(visited[current])+1;
                        get<2>(visited[adj]) = current;
                    }
        }
        cout << endl;
        this->backtrack(visited, start, end);
    }
};


main()
{
    GRAPH<char> g;
    g.AddEdge('a', 'b');
    g.AddEdge('a', 'c');
    g.AddEdge('b', 'd');
    g.AddEdge('c', 'b');
    g.AddEdge('d', 'e');
    g.AddEdge('e', 'f');
    g.BFS('a', 'f');
    return 0;
}