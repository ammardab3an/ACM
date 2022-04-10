// Problem: Fixed-Length Paths II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2081
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

//typedef unsigned int        uint;
//typedef long long int       ll;
//typedef unsigned long long  ull;
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct FenwickTree {

    int n;
    vector<int> bit;  // binary indexed tree

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

} tree(NMAX);

int n, k1, k2, nn, ans, mx_d;
set<int> adj[NMAX];
int sz[NMAX];

void go(int u, int p, int d, bool b){

	if(d > k2) return;

    mx_d = max(mx_d, d);

    if(!b){
        ans += tree.sum(max(int(0), k1-d), max(int(0), k2-d));
    }
    else{
        tree.add(d, 1);
    }

	for(auto v : adj[u]) if(v != p){
		go(v, u, d+1, b);
	}
}

void dfs1(int u, int p){
	nn++;
	sz[u] = 1;
	for(auto v : adj[u]) if(v != p){
		dfs1(v, u);
		sz[u] += sz[v];
	}
}

int dfs2(int u, int p){

	for(auto v : adj[u]) if(v != p) if(sz[v] > nn/2){
		return dfs2(v, u);
	}

    mx_d = 0;

	for(auto v : adj[u]){

        go(v, u, 1, 0);
        go(v, u, 1, 1);
	}

    for(int i = 1; i <= mx_d; i++){
        tree.add(i, -tree.sum(i, i));
    }

	return u;
}

void decompose(int u, int p){

	nn = 0;
	dfs1(u, u);

	int centroid = dfs2(u, u);

	for(auto v : adj[centroid]){
		adj[v].erase(centroid);
		decompose(v, centroid);;
	}

	adj[u].clear();
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
//    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    cin >> n >> k1 >> k2;

    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }

    tree.add(0, 1);

    decompose(0, -1);

    cout << ans << endl;
}
