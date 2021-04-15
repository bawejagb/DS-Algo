#include<bits/stdc++.h>
using namespace std;

struct Act{
    int id, start, end;
};

bool ActCmp(Act a, Act b){
    return a.end < b.end;
}

vector<Act> FindActivity(Act lis[], int size){
    sort(lis, lis + size, ActCmp);
    vector<Act> res;
    Act k = lis[0];
    res.push_back(k);
    for(int i = 1; i < size; i++){
        if(k.end <= lis[i].start){
            res.push_back(lis[i]);
            k = lis[i];
        }
    }
    return res;
}

void ShowAct(vector<Act> res){
    cout << "Activities can be performed:\n";
    cout << "ActID  Start  End\n";
    for(int i = 0; i < res.size(); i++){ 
        cout << res[i].id << "\t" << res[i].start 
        << "\t" << res[i].end << endl; 
    }
}

main(){
    int size;
    cout << "Number of Activities: ";
    cin >> size;
    Act lis[size];
    cout << "ActID  Start  End\n";
    for(int i = 0; i < size; i++){
        cout << i+1 << ". ";
        lis[i].id = i+1;
        cin >> lis[i].start >> lis[i].end;
    }
    vector<Act> res = FindActivity(lis, size);
    ShowAct(res);
    return 0;
}