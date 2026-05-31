#include <bits/stdc++.h>
using namespace std;
bool visitedg[100001]{false};
bool visitedr[100001]{false};
vector<int> G[100001],R[100001];
stack<int> S;
long long cnt=0,res=0;

void DFSg(int s){
    visitedg[s]=true;
    for(int i=0;i<G[s].size();i++){
        int v =G[s][i];
        if(!visitedg[v])
            DFSg(v);
    }
    S.push(s);
}

void DFSr(int s){
    cnt++;
    visitedr[s]=true;
    for(int i=0;i<R[s].size();i++){
        int v =R[s][i];
        if(!visitedr[v]){
            //cout<<cnt<<endl;
            DFSr(v);
        }
    }
}

int main() {
    int n,m,s;
    cin>>n>>m;
    int u,v;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        R[v].push_back(u);
    }
    //while( !S.empty() )S.pop() ;
    for(int i =0;i<n;i++){
        if(!visitedg[i]){
            DFSg(i);
        }
    }

    while (!S.empty()){
        s = S.top();
        S.pop();
        if (!visitedr[s]) {
            cnt=0;
            DFSr(s);
            res+=cnt*(cnt-1)/2;
        }
    }
    cout<<res;
    return 0;
}
