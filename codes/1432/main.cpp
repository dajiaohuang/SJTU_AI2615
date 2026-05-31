#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Dp{
public:
    int i;
    int v;
    bool operator > (const Dp &b) const { return v>b.v ;}
    bool operator < (const Dp &b) const { return v<b.v ;}
    Dp(int ii,int vv){i=ii;v=vv;}
};

int main(){
    int n,a;
    cin>>n;
    int A[100000];
    int res[100000];
    vector<Dp> dp;
    Dp d= Dp(0,1);
    dp.push_back(d);
    res[0]=1;
    make_heap(dp.begin(),dp.end());
    for(int i=0;i<n;i++){
        cin>>a;
        A[i] = a;
        d=Dp(i,1);
        for(int j=0;j<i;j++){
            if(A[dp[j].i]>a){
                d.v=dp[j].v+1;
                break;
            }
        }
        dp.push_back(d);
        push_heap(dp.begin(), dp.end());
        cout<< d.v<<' ';
    }
    return 0;
}
