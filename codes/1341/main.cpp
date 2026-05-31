#include <bits/stdc++.h>
using namespace std;

typedef pair<int,bool> E;
vector<E> G[1000001][2];
vector<E> R[1000001][2];
bool visited[1000001];
int res[1000001];
int s,t;
bool DFSG(int m,int n){
    visited[m]=true;
    for(int i=0;i<G[m][n].size();i++){
        int v =G[m][n][i].first;
        int f = G[m][n][i].second;
        if(v==s && f==1-t) return true;
        if(!visited[v])
            return(DFSG(v,f));
    }
    return false;
}

int main() {
    int n,m,i,j,a,b;cin>>n>>m;E e;
    for(int k=0;k<m;k++){
        cin>>i>>a>>j>>b;
        e.first=j;
        e.second=b;
        G[i][1-a].push_back(e);
        e.first=i;
        e.second=1-b;
        R[j][b].push_back(e);
        e.first=i;
        e.second=a;
        G[j][1-b].push_back(e);
        e.first=j;
        e.second=1-b;
        R[i][a].push_back(e);
    }
    for(int i=0;i<n;i++){
        if(!visited[i])
    }
    return 0;
}
