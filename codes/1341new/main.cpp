#include <bits/stdc++.h>
using namespace std;

long long n,m;

int main() {
    cin>>n>>m;
    int a,b;
    bool v_a,v_b;
    vector<vector<int>> G(2 * n + 1);
    vector<vector<int>> R(2 * n + 1);
    vector<int> marked(2*n + 1, 0);
    vector<int> finish_R(2 * n + 1, 0);
    vector<int> SCC(2 * n + 1, 0);
    vector<int> result(n + 1);

    for(int i=1;i<=n;i++){
        cin>>a>>v_a>>b>>v_b;
        G[2*a-1+!v_a].push_back(2*b-1+v_b);
        R[2 * b - 1 + v_b].push_back(2 * a - 1 + !v_a);
        G[2 * b - 1 + !v_b].push_back(2 * a - 1 + v_a);
        R[2 * a - 1 + v_a].push_back(2 * b - 1 + !v_b);
    }
    dfs_time_G(R, marked, finish_R);




    for (int x = 1;x <= n;x++)
    {
        if (SCC[2 * x - 1] == SCC[2 * x])
        {
            cout << "No";
            return 0;
        }
        result[x] = SCC[2 * x - 1] < SCC[2 * x] ? 0 : 1;
    }

    cout << "Yes" << endl;
    for (int x = 1;x <= n;x++)
    {
        cout << result[x] << ' ';
    }

    return 0;
}
