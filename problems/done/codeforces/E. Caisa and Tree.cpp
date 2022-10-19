// Problem: E. Caisa and Tree
// Contest: Codeforces - Codeforces Round #264 (Div. 2)
// URL: https://codeforces.com/contest/463/problem/E
// Memory Limit: 256 MB
// Time Limit: 10000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

const int AMAX = 2e6 + 10;

int n, q;
int val[NMAX];
vi adj[NMAX];
int depth[NMAX];
int spf[AMAX];
vi tmp[AMAX];
int ans[NMAX];

void sieve(){
	
	for(int i = 0; i < AMAX; i++){
		spf[i] = i;
	}	
	
	for(int i = 2; i < AMAX; i++){
		if(spf[i]==i){
			for(int j = i*i; j < AMAX; j+=i){
				if(spf[j]==j){
					spf[j] = i;
				}
			}
		}
	}
}

void dfs(int u, int p){
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		dfs(v, u);
	}
}

void go(int u, int p){
	
	vi factors;
	
	{
		int t = val[u];
		while(t > 1){
			int p = spf[t];
			while(t%p==0) t/=p;
			factors.push_back(p);
		}
		
		int cans = -1;
		int cans_depth = -1;
		
		for(auto f : factors){
			if(!tmp[f].empty()){
				int w = tmp[f].back();
				if(cans_depth < depth[w]){
					cans = w;
					cans_depth = depth[w];
				}
			}
		}
		
		ans[u] = cans;
	}
	
	for(auto f : factors){
		tmp[f].push_back(u);
	}
	
	for(auto v : adj[u]) if(v != p){
		go(v, u);
	}
	
	for(auto f : factors){
		assert(tmp[f].back()==u);
		tmp[f].pop_back();
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> q;
    for(int i = 0; i < n; i++){
    	cin >> val[i];
    }
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    sieve();
    dfs(0, -1);
    go(0, -1);
    
    while(q--){
    	int k;
    	cin >> k;
    	if(k==1){
    		int u;
    		cin >> u;
    		u--;
    		int cans = ans[u];
    		if(cans != -1) cans++;
    		cout << cans << endl;
    	}
    	else{
    		int u, w;
    		cin >> u >> w;
    		u--;
    		val[u] = w;
    		go(0, -1);
    	}
    }
}
