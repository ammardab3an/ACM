#include<bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 10;
const int MOD = 998244353 ;

int add(int x, int y){
    return (1ll*x+y)%MOD;
}

int mul(int x, int y){
    return (x*1ll*y)%MOD;
}

int pow_exp(int n, int p){
    if(p==0) return 1;
    if(p&1) return mul(n, pow_exp(n, p-1));
    int ret = pow_exp(n, p/2);
    return mul(ret, ret);
}

int fac[NMAX], ifac[NMAX], p2[NMAX], ip2[NMAX];
void init(){
    fac[0] = 1;
    for(int i = 1; i < NMAX; i++){
        fac[i] = mul(fac[i-1], i);
    }
    ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
    for(int i = NMAX-2; i >= 0; i--){
        ifac[i] = mul(ifac[i+1], i+1);
    }
    p2[0] = 1;
    for(int i = 1; i < NMAX; i++){
        p2[i] = mul(p2[i-1], 2);
    }
    ip2[NMAX-1] = pow_exp(p2[NMAX-1], MOD-2);
    for(int i = NMAX-2; i >= 0; i--){
        ip2[i] = mul(ip2[i+1], 2);
    }
}

int n;
vector<int> adj[NMAX];
int cnt[NMAX];
int sz[NMAX];
int ans;

void go(int u, int p=-1){

    sz[u] = 1;
    for(auto v : adj[u]) if(v != p){
        go(v, u);
        sz[u] += sz[v];
    }

    if(sz[u]%2==1){
        if(p != -1){
            cnt[p]++;
        }
    }

    if(cnt[u]){
        int m = cnt[u] - cnt[u]%2;
        int cans = m<2 ? 1 : mul(fac[m], ip2[m/2]);
        if(cnt[u]%2==1) cans = mul(cans, cnt[u]);
        ans = mul(ans, cans);
    }
}

signed main(){

    init();

    cin >> n;
    for(int i = 0; i < n-1; i++){

        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 1;
    go(0);

    cout << ans << endl;
}
