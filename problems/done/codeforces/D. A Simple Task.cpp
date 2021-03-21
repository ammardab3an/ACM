// Problem: D. A Simple Task
// Contest: Codeforces - Codeforces Beta Round #11
// URL: https://codeforces.com/problemset/problem/11/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e5 + 15, N = 1e6 + 16, inf = 1e9 + 9;
vector<vector<int> > g;
ll n, m, x, y, vis[123], dp[19][(1 << 19)];
ll dfs(int root, int u, int p, int msk) {
    if(msk & (1 << u)) {
        int x = __builtin_popcount(msk);
        if(x > 2 && u == root) {
            return 1;
        }
        return 0;
    }
    ll& ret = dp[u][msk];
    if(ret + 1) return ret;
    ret = 0;
    for(int v: g[u]) {
        if(p == v) continue;
        if(v >= root) ret += dfs(root, v, u, msk | (1 << u));
    }
    return ret;
}
int main() {
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        --x, --y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    ll Ans = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        Ans += dfs(i, i, -1, 0);
    }
    Ans >>= 1;
    cout << Ans;
}