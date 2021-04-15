#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    int *prt;
    public:
    Disjoint(int n){
        prt = new int[n+1];
        for(int i = 0; i <= n; i++){
            prt[i] = i;
        }
    }
    int find(int val){
        if(val == prt[val]) return val;
        prt[val] = find(prt[val]);
        return prt[val];
    }
    void unionEt(int u, int v){
        prt[v] = u;
    }
};

struct Job{
    int id, dline, profit;
};

bool JobCmp(Job a, Job b){
    return a.profit > b.profit;
}

int maxDline(Job lis[], int size){
    int mx = 0;
    for(int i = 0; i < size; i++)
        if(lis[i].dline > mx)
            mx = lis[i].dline;
    return mx;
}

vector<Job> FindJobSeq(Job lis[], int size){
    sort(lis, lis + size, JobCmp);
    vector<Job> res;
    Job k;
    int pos, mx = maxDline(lis, size);
    Disjoint dj(mx);
    for(int i = 0; i < size; i++){
        k = lis[i];
        pos = dj.find(k.dline);
        if(pos > 0){
            dj.unionEt(dj.find(pos-1), pos);
            res.push_back(k);
        }
    }
    return res;
}

void ShowJobs(vector<Job> res){
    cout << "Jobs can be performed:\n";
    cout << "JobID  DLine  Profit\n";
    for(int i = 0; i < res.size(); i++){ 
        cout << res[i].id << "\t" << res[i].dline 
        << "\t" << res[i].profit << endl; 
    }
}

main(){
    int size;
    cout << "Number of Jobs: ";
    cin >> size;
    Job lis[size];
    cout << "jobID  DLine  Profit\n";
    for(int i = 0; i < size; i++){
        cout << i+1 << ". ";
        lis[i].id = i+1;
        cin >> lis[i].dline >> lis[i].profit;
    }
    vector<Job> res = FindJobSeq(lis, size);
    ShowJobs(res);
    return 0;
}