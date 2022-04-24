// Problem: Help Chef
// Contest: CodeChef - CodeChef Starters 35 Division 3 (Rated)
// URL: https://www.codechef.com/START35C/problems/HLPCHF
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, k;
vi adj[NMAX];
int kn[NMAX];
bool is_kn[NMAX];
int dist[NMAX];
int sum[NMAX];
int cnt[NMAX];

int ans_dist;
int ans_node;

int c0, d0;

void dfs0(int u, int p, int d){
	
	dist[u] = max(dist[u], d);
	
	if(d > d0 && is_kn[u]){
		c0 = u;
		d0 = d;
	}
	
	for(auto v : adj[u]) if(v != p){
		dfs0(v, u, d+1);
	}
}

void dfs(int u, int p){
	
	sum[u] = 0;
	cnt[u] = is_kn[u];
	
	for(auto v : adj[u]) if(v != p){
		
		dfs(v, u);
		sum[u] += sum[v] + cnt[v];
		cnt[u] += cnt[v];	
	}	
}

void go(int u, int p){
	
	int cans = sum[u] - dist[u];
	
	// cout << u+1 << ' ' << sum[u] << ' ' << cans << endl;
	
	if(cans < ans_dist || (cans==ans_dist && u > ans_node)){
		ans_dist = cans;
		ans_node = u;
	}
	
	for(auto v : adj[u]) if(v != p){
		
		sum[u] -= sum[v] + cnt[v];
		cnt[u] -= cnt[v];
		
		sum[v] += sum[u] + cnt[u];
		cnt[v] += cnt[u];
		
		go(v, u);
		
		sum[v] -= sum[u] + cnt[u];
		cnt[v] -= cnt[u];
		
		sum[u] += sum[v] + cnt[v];
		cnt[u] += cnt[v];	
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> k;
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
			is_kn[i] = false;
		}
		
		for(int i = 0; i < k; i++){
			cin >> kn[i];
			kn[i]--;
			is_kn[kn[i]] = true;
		}
		
		for(int i = 0; i < n-1; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		{
			
			memset(dist, 0, sizeof dist);
			
			c0 = kn[0];
			
			d0 = 0;
			dfs0(c0, -1, 0);
			
			d0 = 0;
			dfs0(c0, -1, 0);
			
			d0 = 0;
			dfs0(c0, -1, 0);
		}
		
		// for(int i = 0; i < n; i++) cout << dist[i] << ' '; cout << endl;
		
		dfs(0, -1);
		
		ans_dist = INFLL;
		ans_node = -2;
		
		go(0, -1);
		
		// cout << ans_node+1 << ' ' << ans_dist << endl;
		cout << ans_node+1 << endl;
    }	
}
