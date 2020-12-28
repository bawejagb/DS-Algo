/*
Write a program to implement prim's minimum spanning tree algorithm.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class GRAPH
{
    public:
    typedef pair<int, T> ITpair;
    map<T,list<ITpair > > adjList;
    void addEdge(T v1, T v2, int wgt, bool bdir=true)
    {
        adjList[v1].push_back(make_pair(wgt,v2));
        if(bdir)
            adjList[v2].push_back(make_pair(wgt,v1));
    }
    void showAdj()
    {
        for (auto adj : adjList)
        {
            cout << adj.first << " : ";
            for(auto lis : adj.second)
                cout << '(' << lis.second << ',' << lis.first << ") ";
            cout << endl;
        }
    }
};
template<typename T>
void primsMST(map<T,list<pair<int, T> > > &adjList, T start)
{
    typedef pair<int, T> ITpair;
    map<T,ITpair> refList;
    map<T,bool> setvx;
    set<ITpair> st;
    for(auto adj : adjList)
    {
        refList[adj.first] = make_pair(INT_MAX,-1);
        setvx[adj.first] = false;
    }
    refList[start].first = 0;
    st.insert(make_pair(0,start));
    while(!st.empty())
    {
        T vx = (*(st.begin())).second;
        st.erase(st.begin());
        setvx[vx] = true;
        for(auto adj : adjList[vx])
        {
            if(!setvx[adj.second] && adj.first < refList[adj.second].first)
            {
                auto old_pair = st.find(make_pair(refList[adj.second].first, adj.second));
                if(old_pair != st.end())
                    st.erase(old_pair);
                refList[adj.second].first = adj.first;
                refList[adj.second].second = vx;
                st.insert(adj);
            }
        }
    }
    refList.erase(start);
    cout << "Minimum Spanning Tree:\n";
    for(auto p : refList)
        cout << p.second.second << '-' << p.first 
            << ':' << p.second.first << endl;
}

main()
{
    GRAPH<char> g;
    g.addEdge('a','b',5);
    g.addEdge('a','c',10);
    g.addEdge('b','d',15);
    g.addEdge('d','e',20);
    g.addEdge('c','d',30);
    g.addEdge('c','b',4);
    g.addEdge('e','f',3);
    g.addEdge('f','g',12);
    g.addEdge('e','g',18);
    g.showAdj();
    primsMST<char>(g.adjList, 'a');
    return 0;
}