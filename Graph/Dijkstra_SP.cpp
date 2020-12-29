/*
Write a program to implement Dijkstra's shortest path algorithm.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>

class GRAPH
{
public:
    typedef pair<int,T> pairIT;
    map<T,list<pairIT> > adjList;
    void addEdge(T v1, T v2, int dis, bool bdir=false)
    {
        adjList[v1].push_back(make_pair(dis, v2));
        if(bdir)
            adjList[v2].push_back(make_pair(dis,v1));
    }
    void showAdj()
    {
        for(auto adj : adjList)
        {
            cout << adj.first << " : ";
            for(auto p : adj.second)
                cout << '(' << p.second
                    << ',' << p.first << ") ";
            cout << endl;
        }
    }
};
template<typename T>
void dijkstraSP(map<T,list<pair<int,T> > > &adjList, T start)
{
    typedef pair<int,T> pairIT;
    map<T,pairIT> refList;
    for(auto adj : adjList)
        refList[adj.first] = make_pair(INT_MAX, -1);
    refList[start].first = 0;
    set<pairIT> st;
    st.insert(make_pair(0,start));
    while(!st.empty())
    {
        T vx = (*(st.begin())).second;
        st.erase(st.begin());
        for(auto adj : adjList[vx])
        {
            if((refList[vx].first != INT_MAX) && (adj.first + refList[vx].first < refList[adj.second].first))
            {
                auto old_pair = st.find(make_pair(refList[adj.second].first,adj.second));
                if(old_pair != st.end())
                    st.erase(old_pair);
                refList[adj.second].first = adj.first + refList[vx].first;
                refList[adj.second].second = vx;
                st.insert(adj);
            }
        }
    }
    cout << "Shortest Path:\n"; 
    for(auto adj : refList)
        cout << start << "->" << adj.first
            << ':' << adj.second.first << endl;
}

main()
{
    GRAPH<char> g;
    g.addEdge('a','b',10);
    g.addEdge('a','c',5);
    g.addEdge('b','c',2);
    g.addEdge('c','b',3);
    g.addEdge('b','d',1);
    g.addEdge('c','d',9);
    g.addEdge('c','e',2);
    g.addEdge('e','d',6);
    g.addEdge('d','e',4);
    g.showAdj();
    dijkstraSP<char>(g.adjList, 'a');
    return 0;
}