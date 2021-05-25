#include<bits/stdc++.h>
using namespace std;

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
    sort(lis, lis + size, JobCmp);//Sorting on the basis of Profit
    vector<Job> res;
    Job k;
    int mx = maxDline(lis, size);
    int slot[mx+1]{};
    for(int i = 0; i < size; i++){
        k = lis[i];
        for(int j = k.dline; j > 0; j--){
            if(!slot[j]){
                slot[j] = k.id;
                res.push_back(k);
                break;
            }
        }
    }
    cout << "Job order:\n";
    for(int i = 1; i <= mx; i++)
        cout << slot[i] << '|';
    cout << "\n";
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