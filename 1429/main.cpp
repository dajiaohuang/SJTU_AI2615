#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,x,s,t,a;
class Job
{
public:
    int s;
    int t;
    int a;
    Job(int ss,int tt,int aa){s=ss;t=tt;a=aa;}
};

bool cmp(Job j1,Job j2){
    return j1.t<j2.t;
}

vector<Job> job;
int main() {
    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        cin>>s>>t>>a;
        Job j(s,t,a);
        job.push_back(j);
    }
    sort(job.begin(),job.end(),cmp);
    int dp[100001][2]{0};
    int flag;
    for(int i=1;i<=m;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        //cout<<dp[i][0]<<endl;
        for(int j=1;j<=i;j++){
            if(job[j-1].t>=job[i-1].s) break;
            flag=j;
        }
        dp[i][1]=dp[flag+1][0]+job[i-1].a;
        //cout<<dp[i][1]<<endl;
    }
    cout<<max(dp[m][0],dp[m][1])<<endl;
    return 0;
}
