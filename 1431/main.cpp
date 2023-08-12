#include <iostream>
#include <vector>
using namespace std;

int dp[801][10001]{0};
int w[801];
int v[801];
int c[801];
int main() {
    int n,W;
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for (int j=1;j<=W;j++){
            if (j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[n][W];
}
