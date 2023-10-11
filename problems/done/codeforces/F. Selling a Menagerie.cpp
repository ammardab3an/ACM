// Problem: F. Selling a Menagerie
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/F
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int n;
int arr[NMAX];
int nxt[NMAX];
int _nxt[NMAX];
bool vis[NMAX];
bool skip[NMAX];

vi adj[NMAX];

vi ans, tmp;

void dfs(int u){
	
	if(vis[u]){
		
		// cout << u << endl;
		// for(auto e : tmp) cout << e << ' '; cout << endl << flush;
		
		vi ntmp;
		ntmp.push_back(u);
		while(tmp.back() != u){
			ntmp.push_back(tmp.back());
			tmp.pop_back();
		}
		
		tmp = ntmp;
		
		return;
	}
	
	tmp.push_back(u);
	vis[u] = true;
	
	dfs(nxt[u]);
}

void dfs2(int u){

	vis[u] = true;
	
	// cout << ' ' << u << endl << flush;
	
	for(auto v : adj[u]){
		dfs2(v);
	}
	
	ans.push_back(u);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		cin >> n;
		
		for(int i = 0; i < n; i++){
			vis[i] = false;
			skip[i] = false;
			adj[i].clear();
		}
		
		for(int i = 0; i < n; i++){
			cin >> nxt[i];
			nxt[i]--;
			adj[nxt[i]].push_back(i);
		}
		
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		ans.clear();
		
		for(int i = 0; i < n; i++) if(!vis[i]){
					
			tmp.clear();
			dfs(i);
			
			// for(auto e : tmp) cout << e << ' '; cout << endl << flush;
			
			for(auto e : tmp){
				skip[e] = true;
			}
			
			for(auto u : tmp){
				for(auto v : adj[u]) if(!skip[v]){
					dfs2(v);
				}
			}
			
			int u = tmp.front();
			for(auto v : tmp) if(arr[v] < arr[u]){
				u = v;
			}
			
			int v = nxt[u];
			
			while(true){
				ans.push_back(v);
				if(v==u) break;
				v = nxt[v];
			}
		}
		
		for(auto e : ans) cout << e+1 << ' '; cout << endl;
    }	
}
