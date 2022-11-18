// Problem: C. Karen and Supermarket
// Contest: Codeforces - Codeforces Round #419 (Div. 1)
// URL: https://codeforces.com/problemset/problem/815/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, p;
vi adj[5050];
int arr[5050][2];
int mem0[5050][5050][2];
int mem1[5050][5050][2];
int sz[5050];
vi suf[5050];

void dfs(int u, int p){
	
	sz[u] = 1;
	for(auto v : adj[u]){
		dfs(v, u);
		sz[u] += sz[v];
		suf[u].push_back(sz[v]);
	}	
	
	if(!suf[u].empty()){
		int sz = suf[u].size();
		for(int i = sz-2; i >= 0; i--){
			suf[u][i] += suf[u][i+1];
		}
	}
}

int go(int u, int rm, bool b);

int calc(int p, int i, int rm, bool b){
	
	if((rm < 0) || (sz[p]-1 < rm)){
		return INF;
	}
	
	if(i==adj[p].size()){
		return rm==0 ? 0 : INF;
	}
	
	int u = adj[p][i];
	int &ret = mem1[u][rm][b];
	if(ret+1) return ret;
	
	int ans = INFLL;
	
	int l = max(int(0), rm-suf[p][i]+sz[u]);
	int r = min(sz[u], rm);
	assert(l <= r);
	
	for(int j = l; j <= r; j++){
		int cans = calc(p, i+1, rm-j, b) + go(u, j, b);
		ans = min(ans, cans);
	}
	
	return ret = ans;
}

int go(int u, int rm, bool b){

	if(rm < 0){
		return INF;
	}
	
	if(rm==0){
		return 0;
	}
	
	int &ret = mem0[u][rm][b];
	if(ret+1) return ret;
	
	int st_path = calc(u, 0, rm-1, b) + arr[u][0] - b*arr[u][1];
	int nd_path = calc(u, 0, rm, 0);
	
	return ret = min(st_path, nd_path);
}

int32_t main(){	
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> p;
    
    for(int i = 0; i < n; i++){
    	
    	cin >> arr[i][0] >> arr[i][1];
    	
    	if(i > 0){
    		int p;
    		cin >> p;
    		p--;
    		adj[p].push_back(i);
    	}
    }
    
    dfs(0, -1);
    
    memset(mem0, -1, sizeof mem0);
    memset(mem1, -1, sizeof mem1);
    
    int ans = 0;
    for(int i = n; i >= 0; i--){	
    	if(go(0, i, 1) <= p){
    		ans = i;
    		break;
    	}
    }
    
    cout << ans << endl;
}
