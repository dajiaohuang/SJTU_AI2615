#include <bits/stdc++.h>
using namespace std;

struct num{
    int data;
    int res;
    num(int d): data(d),res(0){}
};

vector<num> a;

int n;

void merge(int l,int r,int m){
    int i=l,j=m+1;
    vector<num> t;
    while(i<=m&&j<=r){
        if(a[i].data<=a[j].data){
            a[i].res+=(t.size()-i+l);
            t.push_back(a[i++]);
        }
        else{
            a[j].res+=(m+1-i);
            t.push_back(a[j++]);
        }
    }
    while(i<=m){
        a[i].res+=(t.size()-i+l);
        t.push_back(a[i++]);
    }
    while(j<=r){
        t.push_back(a[j++]);
    }
    for(int k=l;k<=r;k++){
        a[k]=t[k-l];
    }
}

void merge_sort(int l,int r){
    if(l==r)return;
    int m = (l+r)>>1;
    merge_sort(l,m);
    merge_sort(m+1,r);
    merge(l,r,m);
}

int main() {
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        a.push_back(num(data));
    }
    merge_sort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i].res<<' ';
    }
}
