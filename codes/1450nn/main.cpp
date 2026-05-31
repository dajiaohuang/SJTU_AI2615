#include<iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N=100001,inf=1000000000;
int n,cnt=1,x,s=0,t=0;
int ve[N],e[N],ne[N],h[N],e2[N];

void add(int u,int v,int c){
    ve[++cnt]=v;
    ne[cnt]=h[u];
    h[u]=cnt;
    e[cnt]=c;
    e2[cnt]=c;
}

int d[N];
bool bfs(){
    memset(d,0,sizeof(d));
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(s);
    d[s]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=h[x];i;i=ne[i])
            if(!d[ve[i]]&&e[i]){
                d[ve[i]]=d[x]+1;
                q.push(ve[i]);
            }
    }
    return (d[t]!=0);
}

int dinic_step(int x,int rest){
    if(x==t) return rest;
    int cur=rest;
    for(int i=h[x];i&&cur;i=ne[i])
    {
        if((d[ve[i]]==d[x]+1)&&e[i])
        {
            int k=dinic_step(ve[i],min(cur,e[i]));
            if(!k) d[ve[i]]=0;
            e[i]-=k,e[i+1]+=k;
            cur-=k;
        }
    }
    return rest-cur;
}

int dinic()
{
    int ans=0;
    while (bfs()) ans+= dinic_step(0,inf);
    return ans;
}

void graph(){
    for(int i=0;i<n;i++){
        add(s,i+1,1);
        add(i+1,s,0);
        add(n+i+1,t,1);
        add(t,n+i+1,0);
        for(int j=0;j<n;j++){
            cin>>x;
            if(x) {
                add(i + 1, n + j + 1, 1);
                add(n + j + 1, i + 1, 0);
            }
        }
    }
}

void mat(){
    int res[N];
    for(int i=1;i<=n;i++){
        for(int j=h[i];j;j=ne[j])
            if(ve[j]!=0 && ve[j]!=2*n+1 && e[j]==0 && e2[j]==1 )
                res[i]=ve[j]-n;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(res[i]==j) <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cin>>n;
    t=2*n+1;
    graph();
    if(dinic()==n) cout<<"Yes"<<endl;
    else{
        cout<<"No"<<endl;
        return 0;
    }
    mat();
}
