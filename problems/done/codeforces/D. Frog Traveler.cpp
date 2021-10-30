// Problem: D. Frog Traveler
// Contest: Codeforces - Codeforces Round #751 (Div. 2)
// URL: https://codeforces.com/contest/1602/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 3e5 + 10;

int n;
int a[NMAX], b[NMAX];

int dist[NMAX][2];
int par[NMAX][2];

pii tree[NMAX << 2];

vi query(int nd, int l, int r, int q_l, int q_r, int val, int par){
    
    if(r < q_l || q_r < l){
        return (vi){};
    }
    
    if((q_l <= l && r <= q_r) && (tree[nd].first <= val)){
        return (vi) {};
    }
    
    if(l == r){
        tree[nd] = {val, par};
        return (vi){l};
    }
    
    int mid = (l+r)/2;
    vi st_path = query(nd*2, l, mid, q_l, q_r, val, par);
    vi nd_path = query(nd*2+1, mid+1, r, q_l, q_r, val, par);
    
    tree[nd] = max(tree[nd*2], tree[nd*2+1]);
    
    if(st_path > nd_path){
        for(auto i : nd_path){
            st_path.push_back(i);
        }
        return st_path;
    }
    else{
        for(auto i : st_path){
            nd_path.push_back(i);
        }
        return nd_path;
    }
}

void go(){
    
    memset(dist, INF, sizeof dist);
    memset(tree, INF, sizeof tree);
    
    priority_queue< iii > que;
    que.push({0, {0, 0}});
    dist[0][0] = 0;
    
    while(!que.empty()){
        
        auto tp = que.top();
        que.pop();
        
        int cd = -1 * tp.first;
        int ci = tp.second.first;
        bool k = tp.second.second;
        
        if(k){
            
            int ni = max(int(0), ci-b[ci]);
            
            if(dist[ni][0] > cd){
                dist[ni][0] = cd;
                par[ni][0] = ci;
                que.push({-1 * cd, {ni, 0}});
            }
            
            continue;
        }
        
        if(dist[ci][k] < cd) continue;
        
        if(ci + a[ci] >= n){
            dist[n][1] = cd+1;
            par[n][1] = ci;
            break;    
        }
        
        vi q = query(1, 0, n-1, ci+1, ci+a[ci], cd+1, ci);
        
        for(auto nxt : q){    
            dist[nxt][1] = cd+1;
            par[nxt][1] = ci;
            que.push({-1 * (cd+1), {nxt, 1}});
        }
    }
    
    if(dist[n][1] >= INF){
        cout << -1 << endl;
        return;
    }
    
    cout << dist[n][1] << endl;
    
    int cur = n;
    int cur_k = 1;
    
    vi ans;
    
    while(true){
        ans.push_back(cur);
        if(!cur) break;
        cur = par[cur][cur_k];
        cur_k ^= 1;
    }
    
    for(int i = ans.size()-2; i >= 0; i-=2){
        cout << n-ans[i] << ' ';
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    reverse(a, a+n);
    reverse(b, b+n);
    
    go();
}
