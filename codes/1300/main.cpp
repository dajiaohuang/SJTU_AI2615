#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> a;

void read_input_data_vector()
{
    int m;
    cin >> n >> k >> m; a.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    unsigned int z = a[m - 1];
    for (int i = m; i < n; i++)
    {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}

int partition(int l,int r){
    int i = l;
    for(int j= l;j<r;j++){
        if(a[j]<a[r]) swap(a[j],a[i++]);
    }
    swap(a[r],a[i]);
    return i;
}

int random_select(int l,int r){
    int i = partition(l,r);
    if(i==k-1) return a[i];
    if(i<=k-1) return random_select(i+1,r);
    return random_select(l,i-1);
}

int main() {
    read_input_data_vector();
    cout<<random_select(0,n-1);
    return 0;
}
