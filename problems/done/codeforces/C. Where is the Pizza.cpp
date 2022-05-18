// Problem: C. Where is the Pizza?
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/C
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

vi adj[NMAX];
int vis[NMAX], vid;

int dfs(int u){
	
	int ret = 1;
	
	vis[u] = vid;
	for(auto v : adj[u]) if(vis[v] != vid){
		ret += dfs(v);
	}	
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){
			
		int n;
		cin >> n;
		
		vector<vi> vec(2, vi(n));
		
		for(int j = 0; j < 2; j++)
		for(int i = 0; i < n; i++){
			cin >> vec[j][i];
			vec[j][i]--;
		}
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		vector<vi> tmp(n);
		for(int j = 0; j < 2; j++)
		for(int i = 0; i < n; i++){
			tmp[vec[j][i]].push_back(i);
		}
		
		for(int i = 0; i < n; i++){
			
			assert(tmp[i].size()==2);
			
			int u = tmp[i][0];
			int v = tmp[i][1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vid++;
		for(int i = 0; i < n; i++){
			
			int ci;
			cin >> ci;
			ci--;
			
			if(ci != -1){
				dfs(i);
			}
		}
		
		int cnt = 0;
		for(int i = 0; i < n; i++) if(vis[i] != vid){
			int sz = dfs(i);
			if(sz > 1) cnt++;
		}
		
		int ans = pow_exp(2, cnt);
		cout << ans << endl;
    }	
}
