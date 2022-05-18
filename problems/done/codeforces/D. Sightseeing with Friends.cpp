// Problem: D. Sightseeing with Friends
// Contest: Codeforces - 2021, XIII Donald Knuth Annual Programming Contest by ESCOM-IPN
// URL: https://codeforces.com/gym/103256/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
pair<int,int> a[1000009];
int p[1000009];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, q;
    cin>>n>>m>>q;
    for(int i=0; i<m; i++)
    {
        cin>>a[i].first>>a[i].second;
    }

    sort(a , a+m);

    for(int i=0; i<m; i++)
    {
        p[a[i].first] = max(p[a[i].first], a[i].second);
    }
    for(int i=1; i<=n; i++)
    {
        p[i] = max(p[i], p[i-1]);
    }

    int x,y;
    while(q--)
    {
        cin>>x>>y;
        if(x>y) swap(x,y);
        if(p[x] >= y) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}