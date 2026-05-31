#include "bits/stdc++.h"
using namespace std;

long long dist[2501]{LONG_LONG_MAX};

class Edge{
public:
    int from;
    int to;
    long long weight;
    Edge(int a,int b,long long w){from=a;to=b;weight=w;}
};
vector<Edge> E;
bool flag = false;
int U, V;

int main(){
    int n,m,a,b,w;
    cin>>n>>m;
    int pre[2501]{-1};
    //int num=0;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        Edge e (a,b,w);
        E.push_back(e);
        //num++;
    }
    //BF
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(dist[E[j].from]+E[j].weight<dist[E[j].to]){
                pre[E[j].to]=E[j].from;
                dist[E[j].to]=dist[E[j].from]+E[j].weight;
            }
        }
    }
    //BFagain
    for(int j =0;j<m;j++){
        if(dist[E[j].from]+E[j].weight<dist[E[j].to]){
            flag= true;
            pre[E[j].to]=E[j].from;
            dist[E[j].to]=dist[E[j].from]+E[j].weight;
            U=E[j].from;
            V=E[j].to;
            break;
        }
    }

    if (!flag){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    bool vis[2501]{false};
    vis[U]=true;vis[V]=true;


    int temp=pre[U];
    while (!vis[temp]){
        vis[temp]= true;
        temp = pre[temp];
    }

    
    int start = temp;
    int cycle[2501]{-1};
    cycle[1]=start;
    int cnt=1;
    temp = pre[start];
    while(temp!=start){
        if(temp !=-1){
            cnt++;
            cycle[cnt]=temp;
        }
        temp=pre[temp];
    }
    cout<<cnt<<endl;
    for(int i=cnt;i>=1;i--){
        cout<<cycle[i]<<' ';
    }

    return 0;
}