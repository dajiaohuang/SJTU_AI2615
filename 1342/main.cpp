#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Edge{
public:
    int des;
    int weight;
    Edge(int d,int w){weight=w;des =d;}
};
class Cmp{
public:
    bool operator()(Edge &a,Edge &b){
        return a.weight==b.weight?a.weight>b.weight:a.weight<b.weight;
    }
};
int main() {
    int n,m,s,t,a,b,w;
    cin>>n>>m>>s>>t;
    vector<long long> dist;
    vector<priority_queue<Edge,vector<Edge>,Cmp >* > G;
    vector<bool> flag;
    for (int i=0;i<n;i++){
        dist.push_back(LONG_LONG_MAX);
        flag.push_back(false);
        G.push_back(new priority_queue<Edge,vector<Edge>,Cmp > >);
    }
    for (int i=0;i<m;i++){
        cin>>a>>b>>w;
        G[a]->push(Edge(b,w));
        G[b]->push(Edge(a,w));
    }
    dist[s-1]=0;
    flag[s-1]=true;
    queue<int> q;
    q.push(s);

    return 0;
}