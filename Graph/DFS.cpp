/*
Write a program to implement depth first search algorithm.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class GRAPH
{
    map<T,list<T>> head;
    void backtrack(map<T,tuple<bool,int,int,T>> &lst, T start, T ct)
    {
        stack<T> st;
        while(ct != start)
        {
            st.push(ct);
            ct = get<3>(lst[ct]);
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

    void DFS(T start, T end)
    {
        int time = 1;
        stack<T> st;
        map<T,tuple<bool,int,int,T>> visited;
        st.push(start);
        T pre, crt;
        for(auto p : head)
            visited[p.first] = make_tuple(0,0,0,'\0');
        get<1>(visited[start]) = time;
        while(!st.empty())
        {
            time++;
            bool status = 0;
            crt = st.top();
            get<0>(visited[crt]) = 1;
            for(T adj : head[crt])
                if(!get<0>(visited[adj]))
                {
                     st.push(adj);
                     get<1>(visited[adj]) = time;
                     status = 1;
                     break;
                }
            if(!status)
            {
                st.pop();
                if(st.empty())
                    pre = '\0';
                else
                    pre = st.top();
                get<2>(visited[crt]) = time;
                get<3>(visited[crt]) = pre;
                
            }
        }
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
    g.AddEdge('c', 'd');
    g.AddEdge('d', 'e');
    g.AddEdge('e', 'f');
    g.DFS('a', 'f');
    return 0;
}