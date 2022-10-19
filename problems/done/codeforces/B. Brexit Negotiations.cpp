// Problem: B. Brexit Negotiations
// Contest: Codeforces - 2018-2019 ICPC Northwestern European Regional Programming Contest (NWERC 2018)
// URL: https://codeforces.com/gym/102483/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 4e5 + 10;

int n;
vi adj[NMAX];
int arr[NMAX];
bool vis[NMAX];
int pos[NMAX];
int dfs[NMAX], sz;

void go(int u){
	
	vis[u] = true;
	
	for(auto v : adj[u]) if(!vis[v]){
		go(v);
	}	
	
	dfs[sz++] = u;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	
    	cin >> arr[i];
    	
    	int k; cin >> k; while(k--){
    		
    		int u;
    		cin >> u;
    		u--;
    		
    		adj[i].push_back(u);
    	}
    }
    
    iota(pos, pos+n, 0);
    sort(pos, pos+n, [&](int i, int j){
    	return arr[i] > arr[j];
    });
    
    for(int i = 0; i < n; i++) if(!vis[pos[i]]){
    	go(pos[i]);
    }
    
    // cout << sz << endl;
    // for(int i = 0; i < n; i++) cout << dfs[i] << ' '; cout << endl;
    // for(int i = 0; i < n; i++) cout << arr[dfs[i]] << ' '; cout << endl;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
    	int cans = max(ans, arr[dfs[i]] + i);
    	ans = max(ans, cans);
    }
    
    cout << ans << endl;
}
