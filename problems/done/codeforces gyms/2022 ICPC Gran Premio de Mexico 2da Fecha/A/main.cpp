#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

const int NMAX = 2e5 + 10;
const int MOD = 1e9+7;

int add(int x, int y){
    int ret = (1ll*x+y)%MOD;
    return (ret+MOD)%MOD;
}

int mul(int x, int y){
    int ret = (x*1ll*y)%MOD;
    return (ret+MOD)%MOD;
}

int n, m, c;
vector<pair<int, int>> adj[NMAX];
int val[NMAX];
int mem[NMAX][101];

int dfs(int u, int rm){

    if(rm < 0){
        return 1e12;
    }

    if(u==0){
        return 1;
    }

    int &ret = mem[u][rm];
    if(ret+1) return ret;

    int ans = 0;
    for(auto [v, d] : adj[u]){
        ans += d + dfs(v, rm-d);
        if(ans > 1e9) ans = 1e9;
    }

    return ret = ans;
}

int go(int i, int rm){

    if(rm < 0){
        return 0;
    }

    if(i==n){
        return 1;
    }

    int &ret = mem[i][rm];
    if(ret+1) return ret;

    int st_path = go(i+1, rm);
    int nd_path = (val[i]<=rm) ? go(i, rm-val[i]) : 0;

    return ret = add(st_path, nd_path);
}

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> c;
    for(int i = 0; i < m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        adj[v].push_back({u, d});
    }

    memset(mem, -1, sizeof mem);

    for(int i = 0; i < n; i++){
        val[i] = dfs(i, c);
        if(val[i] < 0) val[i] = 1e9;
    }

    memset(mem, -1, sizeof mem);

    int ans = add(-1, go(0, c));
    cout << ans << endl;
}
