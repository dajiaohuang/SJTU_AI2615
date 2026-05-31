#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,s,t,w;
long long res=0;
class Edge{
public:
    int s,t,w;
    Edge(int ss,int tt,int ww){s=ss;t=tt;w=ww;}
/*    bool operator > (const Edge& E) const
    {
        return w > E.w;
    }*/
};
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
/*class cmp{
public:
    bool operator() (Edge a,Edge b)
    {
        if(a.w!=b.w) return a.w<b.w;
        return a.w==b.w;
    }
};
//bool cmp(const Edge &a,const Edge &b){return a.w<b.w;}
priority_queue<Edge,vector<Edge>,cmp > edge;*/

int p[5000];

int findfather(int a)
{
    while(p[a] != a) a= p[a];
    return a;
}

int main() {
    cin>>n>>m;
    vector<Edge> edge;
    for(int i=0;i<m;i++){
        cin>>s>>t>>w;
        Edge e(s,t,w);
        edge.push_back(e);
    }

    sort(edge.begin(),edge.end(),cmp );
    for (int i = 0;i < n;i++) p[i] = i;
    for(int i=0;i<m;i++){
        s=edge[i].s;
        t=edge[i].t;
        w=edge[i].w;
        //cout<<w<<endl;
        s= findfather(s);
        t= findfather(t);
        if(s!=t)
        {
            p[s]=p[t];
            res+=w;
        }
    }
    cout<<res;
    return 0;
}
