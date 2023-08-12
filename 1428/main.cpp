#include <iostream>
#include <queue>
using namespace std;

int n,m,s,t,w;
class Edge{
public:
    int s,t,w;
    Edge(int ss,int tt,int ww){s=ss;t=tt;w=ww;}
};
class Cmp{
public:
    bool operator()(Edge &a,Edge &b){
        return a.w==b.w?a.w>b.w:a.w<b.w;
    }
};
priority_queue<Edge,vector<Edge>,Cmp> edge;
bool previous[5000]{false};
long long res=0;

int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>s>>t>>w;
        Edge e(s,t,w);
        edge.push(e);
        Edge ee(s,t,w);
        edge.push(ee);
    }
    previous[edge.top().s]=true;
    for(int i =0;i<2*m;i++){
        if(previous[edge.top().t]) continue;
        else {
            res+=edge.top().w;
            previous[edge.top().t]=true;
            edge.pop();
        }
    }
    cout<<res;
    return 0;
}
