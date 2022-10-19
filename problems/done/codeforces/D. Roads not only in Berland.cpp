// Problem: D. Roads not only in Berland
// Contest: Codeforces - Codeforces Beta Round #25 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/25/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
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
 
const int NMAX = 1e3 + 10;

int n;
pii edges[NMAX];
int par[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool merge(int u, int v){
	if((u=get_par(u))==(v=get_par(v))){
		return false;
	}
	if(rand()&1) swap(u, v);
	par[u] = v;
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n-1; i++){
    	cin >> edges[i].first >> edges[i].second;
    }
    
    for(int i = 1; i <= n; i++){
    	par[i] = i;
    }
    
    vi del;
    for(int i = 0; i < n-1; i++){
    	
    	int u = edges[i].first;
    	int v = edges[i].second;
    	
    	if(!merge(u, v)){
    		del.push_back(i);
    	}
    }
    
    vpii ad;
    for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++) if(merge(i, j)){
    	ad.push_back({i, j});
    }
    
    assert(del.size()==ad.size());
    
    cout << del.size() << endl;
    for(int i = 0; i < del.size(); i++){
    	cout << edges[del[i]].first << ' ' << edges[del[i]].second << ' ';
    	cout << ad[i].first << ' ' << ad[i].second << endl;
    }
}
