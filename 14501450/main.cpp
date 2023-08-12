#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int M=201,N=201,INF=1000000000;
int source =1,sink=0,n=0;;
int level[N];
struct edge {
    int next, to, flow;
};
edge e[(M + 1) * 2]; // double space for back edge, reserve 0 for null
int edge_cnt = 2; // reverse(e[x]) = e[x ^ 1]
int list_head[N]; // init as 0
void add_edge (int u, int v, int flow) {
    e[edge_cnt] = {list_head[u], v, flow};
    list_head[u] = edge_cnt++;
    e[edge_cnt] = {list_head[v], u, 0};
    list_head[v] = edge_cnt++;
}

int cur[N];
int dfs(int x, int flow) {
    if (x == sink) return flow;
    int used = 0;
    for (int &i = cur[x]; i != 0; i = e[i].next) { // i : reference to cur[x]
        if (e[i].flow > 0 && level[x] + 1 == level[e[i].to]) {
            int ret = dfs(e[i].to, min(e[i].flow, flow - used));
            if (ret) {
                used += ret;
                e[i].flow -= ret;
                e[i ^ 1].flow += ret;
                if (used == flow) break;
                // NOTE: if not break,
                // the current flow optimization is broken,
                // since current edge is still useful
            }
        }
    }
    return used;
}

bool make_level() {
    memset(level, -1, sizeof(level));
    level[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = list_head[x]; i != 0; i = e[i].next)
            if (e[i].flow > 0 && level[e[i].to] < 0) {
                level[e[i].to] = level[x] + 1;
                q.push(e[i].to);
            }
    }
    return (level[sink] >= 0);
}

int dinic() {
    int ans = 0;
    while (make_level()) {
        for (int i = 1; i <= n; i++) { // initialize cur[]
            cur[i] = list_head[i];
        }
        ans += dfs(source, INF); // dfs ONCE with inf flow
    }
    return ans;
}


int main() {
    cin>>n;
    sink=2*n+1;
    int x;
    for(int i=0;i<n;i++){
        add_edge(source,i+1,1);
        add_edge(i+1,source,0);
        add_edge(i+n+1,sink,1);
        add_edge(sink,i+n+1,0);
        for(int j=0;j<n;j++){
            cin>>x;
            if(x){
                add_edge(i+1,n+j-1,1);
                add_edge(n+j-1,i+1,0);
            }
        }
    }
    cout<<dinic();
    return 0;
}
