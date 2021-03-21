// Problem: A. Linova and Kingdom
// Contest: Codeforces - Codeforces Round #635 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1336/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e5 + 15, N = 1e6 + 16, inf = 1e9 + 9;

int n, k;
vector<vector<int> > g;
int lvl[2 * M], sz[2 * M];
vector<int> Ans;

int dfs(int u, int par) {
    if(par != -1) lvl[u] = lvl[par] + 1;
    for(int v: g[u])
        if(v != par) sz[u] += 1 + dfs(v, u);
    return sz[u];
}

int main() {
    scanf("%d %d", &n, &k);
    g.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++) {
        Ans.push_back(lvl[i] - sz[i]);
    }
    sort(Ans.begin(), Ans.end());
    reverse(Ans.begin(), Ans.end());
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        ans += Ans[i];
    }
    printf("%I64d\n", ans);
}