#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    string a;
    int n;
    cin >> n;
    vector<string> v1(n);
    vector<string> v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v1[i] = a;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v2[i] = a;
    }
    map<string, string> m;
    int i = 0;
    while (i < n)
    {
        if (!m.count(v1[i]))
        {
            m.insert({ v1[i],v2[i] });
        }
        else
        {
            if (v2[i] != m[v1[i]])break;     
        }
        i++;
    }
    if (i == n) cout << "Yes";
    else cout << "No";
}