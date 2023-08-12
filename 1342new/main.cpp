#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int dest;
    long long weight;
    Edge(int d,long long w){dest=d;weight=w;}
};
typedef pair<long long ,int > Pair;
int main(){
    vector<long long> dist;
    //vector<bool> state;
    vector<Edge> G[6201];
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    int x,y;
    long long w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        Edge e1(y,w);
        G[x].push_back(e1);
        Edge e2(x,w);
        G[y].push_back(e2);
        dist.push_back(LONG_LONG_MAX);
        //state.push_back(false);
    }

    priority_queue<Pair ,vector<Pair> , greater<Pair> > q;
    dist[s]=0;
    q.push(Pair(0,s));
    while (!q.empty()){
        Pair p=q.top();
        q.pop();
        int v=p.second;
        if(dist[v]<p.first) continue;
        for(int i =0;i<G[v].size();i++){
            Edge e = G[v][i];
            if(dist[e.dest]>dist[v]+e.weight){
                dist[e.dest]=dist[v]+e.weight;
                q.push(Pair(dist[e.dest],e.dest));
            }
        }
    }
    cout<<dist[t];
    return 0;
}