/*
Write a program to implement kruskal's minimum spanning tree algorithm.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class GRAPH{

    map<T, list<pair<T,int> > > head;
    T parentVtx(T vx, map<T,pair<T,int> > &vtxMap)
    {
        if(vtxMap[vx].first != vx)
            vtxMap[vx].first = parentVtx(vtxMap[vx].first, vtxMap);
        return vtxMap[vx].first;
    }
    void Union(T vx1, T vx2, map<T,pair<T,int> > &vtxMap)
    {
        vx1 = parentVtx(vx1,vtxMap);
        vx2 = parentVtx(vx2, vtxMap);
        if(vtxMap[vx1].second > vtxMap[vx2].second)
            vtxMap[vx2].first = vx1;
        else 
            vtxMap[vx1].first = vx2;
        if(vtxMap[vx1].second == vtxMap[vx2].second)
            vtxMap[vx2].second++;
    }
public:
    void addEdge(T start, T end, int wgt, bool bdir=true)
    {
        head[start].push_back(make_pair(end,wgt));
        if(bdir)
            head[end].push_back(make_pair(start,wgt));
    }
    void showAdj()
    {
        for (auto adj : head)
        {
            cout << adj.first << " : ";
            for(auto lis : adj.second)
                cout << '(' << lis.first << ',' << lis.second << ") ";
            cout << endl;
        }
    }
    void kruskalMST()
    {
        list<pair<int,pair<T,T> > > edgList;
        map<T,pair<T,int> > vtxMap;
        list<tuple<T,T,int> > res;
        for(auto edg : head)
        {   
            vtxMap[edg.first] = make_pair(edg.first, 0);
            for(auto p : edg.second)
                edgList.push_back(make_pair(p.second,make_pair(edg.first,p.first)));
        }
        edgList.sort();
        int size = vtxMap.size();
        int tot_edges = 0;
        for(auto p : edgList)    
        {
            T vx1 = p.second.first;
            T vx2 = p.second.second;
            if(parentVtx(vx1,vtxMap) != parentVtx(vx2,vtxMap))
            {
                tot_edges++;
                res.push_back(make_tuple(vx1,vx2,p.first));
                Union(vx1,vx2,vtxMap);
            }
            if(tot_edges == size - 1)
                break;
        }
        cout << "Minimum spanning tree:\n";
        for(auto p : res)
            cout<< '(' << get<0>(p) << ',' << get<1>(p) << ',' << get<2>(p) << ")\n";
    }
};
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
    g.kruskalMST();
    return 0;
}
