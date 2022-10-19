// Problem: D. Tree and Queries
// Contest: Codeforces - Codeforces Round #221 (Div. 1)
// URL: https://codeforces.com/problemset/problem/375/D
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

int n, m;
int arr[NMAX];
vi adj[NMAX];
vpii queries[NMAX];
int ans[NMAX];

typedef pair<map<int, int>, vi> p_m_v;

void merge(p_m_v &a, p_m_v &b){
	
	if(a.first.size() < b.first.size()){
		swap(a, b);
	}
	
	for(auto [vl, fr] : b.first){
		
		int init_fr = a.first[vl];
		
		if((int)(a.second.size()) < fr+init_fr){
			a.second.resize(fr+init_fr);
		}
		
		for(int i = 1; i <= fr; i++){
			a.second[init_fr+i-1]++;
		}	
			
		a.first[vl] += fr;
	}
}

p_m_v go(int u, int p){
	
	p_m_v cur;
	cur.first[arr[u]] = 1;
	cur.second = {1};
	
	for(auto v : adj[u]) if(v != p){
		p_m_v nxt = go(v, u);
		merge(cur, nxt);
	}	
	
	for(auto [i, k] : queries[u]){
		if(k-1 < cur.second.size()){
			ans[i] = cur.second[k-1];
		}
		else{
			ans[i] = 0;
		}
	}
	
	return cur;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    for(int i = 0; i < m; i++){
    	int u, k;
    	cin >> u >> k;
    	u--;
    	queries[u].push_back({i, k});
    }
    
    go(0, -1);
    
    for(int i = 0; i < m; i++){
    	cout << ans[i] << endl;
    }
}
