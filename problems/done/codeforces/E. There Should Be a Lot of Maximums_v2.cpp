// Problem: E. There Should Be a Lot of Maximums
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

// int mul(int a, int b){
	// int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	// return (ret+MOD)%MOD;
// }
//  
// int add(int a, int b){
	// int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	// return (ret+MOD)%MOD;
// }
//  
// int pow_exp(int n, int p){
	// if(!p) return 1;
	// if(p&1) return mul(n, pow_exp(n, p-1));
	// int tmp = pow_exp(n, p/2);
	// return mul(tmp, tmp);
// }
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
vi adj[NMAX];
int arr[NMAX];
int tin[NMAX], _tin[NMAX], tout[NMAX], tim;
int frq[2][NMAX];
int frq_blk[2][NMAX/BLOCK + 1];

struct query{
	
	int p, l, r;
	
	bool operator < (const query &other){
		if(l/BLOCK != other.l/BLOCK) return l < other.l;
		return (l/BLOCK)%2==0 ? r > other.r : r < other.r; 	
	}	
};

void dfs(int u, int p){
	
	tin[u] = tim;
	_tin[tim] = u;
	tim++;
	
	for(auto v : adj[u]) if(v != p){
		
		dfs(v, u);
	}	
	
	tout[u] = tim;
}

void add(bool b, int i){
	frq[b][i]++;
	if(frq[b][i]==2){
		frq_blk[b][i/BLOCK]++;
	}
}

void rem(bool b, int i){
	frq[b][i]--;
	if(frq[b][i]==1){
		frq_blk[b][i/BLOCK]--;
	}
}

void add(int i){
	int val = arr[_tin[i]];
	rem(0, val);
	add(1, val);
}

void rem(int i){
	int val = arr[_tin[i]];
	rem(1, val);
	add(0, val);	
}

int get_ans(bool b){
	
	for(int i = (n-1)/BLOCK; i >= 0; i--) if(frq_blk[b][i]){
		
		int l = i*BLOCK;
		int r = min(n, (i+1)*BLOCK);
		
		for(int j = r-1; j >= l; j--) if(frq[b][j] >= 2){
			return j;
		}
	}
	
	return 0;
}

int get_ans(){
	return max(get_ans(0), get_ans(1));
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    
    vpii edges(n-1);
    for(auto &[u, v] : edges){
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    vi tmp(arr, arr+n);
    tmp.push_back(0);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i = 0; i < n; i++){
    	arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i])-tmp.begin();
    }
    
    dfs(0, -1);
    
    vector<query> queries(n-1);
    
    for(int i = 0; i < n-1; i++){
    	
    	auto [u, v] = edges[i];
    	
    	if(tin[u] > tin[v]){
    		swap(u, v);
    	}
    	
    	int l = tin[v];
    	int r = tout[v]-1;
    	
    	queries[i] = (query){i, l, r};
    }
    
    sort(queries.begin(), queries.end());
    
    vi ans(n-1);
    
    for(int i = 0; i < n; i++){
    	add(0, arr[i]);
    }
    
    int r = 0, l = 1;
    for(auto [p, ql, qr] : queries){
    	
    	while(l < ql) rem(l++);
    	while(qr < r) rem(r--);
    	while(ql < l) add(--l);
    	while(r < qr) add(++r);
    	
    	ans[p] = get_ans();	
    }
    
    for(auto i : ans) cout << tmp[i] << endl;
}