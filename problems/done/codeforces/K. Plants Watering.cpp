// Problem: K. Plants Watering
// Contest: Codeforces - ECPC 2019 Kickoff
// URL: https://codeforces.com/gym/102881/problem/K
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5+1;
ll a, b;
int main () {
    int n;
    freopen("plants.in", "r", stdin);
    scanf("%d",&n);
    int a[n], h[n], c[n], d[n];
    for (int i=0;i<n;i++)
        scanf("%d",a + i);

    for (int i=0;i<n;i++)
        scanf("%d",h + i);
    for (int i = 1;i < n; i++){
        c[i] = a[i] - a[i-1];
        d[i] = h[i] - h[i-1];
    }
    int mx = 0;
    for (int i=1;i<n;i++){
        if (c[i] < 0) {
            if (d[i] <= 0) {
                return !printf("-1\n");
            }
            mx = max(mx, (-c[i] + d[i] - 1) / d[i]);
        }
    }
    for (int i=1;i<n;i++){
        if ( 1ll * c[i] + mx *1ll* d[i] < 0) return !printf("-1");
    }
    printf("%d", mx);
}