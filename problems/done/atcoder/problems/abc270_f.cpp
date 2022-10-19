// Problem: F - Transportation
// Contest: AtCoder - TOYOTA MOTOR CORPORATION Programming Contest 2022(AtCoder Beginner Contest 270)
// URL: https://atcoder.jp/contests/abc270/tasks/abc270_f
// Memory Limit: 1024 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
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

int go(const vector<iii> &edges, int a, int b, int c){
	
	int ret = 0;
	iota(par, par+n+2, 0);
	
	for(auto [d, uv] : edges){
		auto [u, v] = uv;
		
		if(v==a || v==b){
			continue;
		}
		
		if(merge(u, v)){
			ret += d;
			c--;
		}
	}	
	
	return c>1 ? INFLL : ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int m;
    cin >> n >> m;
    
    vi vec_a(n), vec_b(n);
    for(auto &i : vec_a) cin >> i;
    for(auto &i : vec_b) cin >> i;
    
    vector<iii> edges(m);
    for(auto &[d, uv] : edges){
    	auto &[u, v] = uv;
    	cin >> u >> v >> d;
    	if(u > v) swap(u, v);
    	u--, v--;
    }
    
    for(int i = 0; i < n; i++){
    	edges.push_back({vec_a[i], {i, n}});
    }
    for(int i = 0; i < n; i++){
    	edges.push_back({vec_b[i], {i, n+1}});
    }
    
    sort(edges.begin(), edges.end());
    
    int st_path = go(edges, -1, -1, n+2);
    int nd_path = go(edges, -1, n, n+1);
    int rd_path = go(edges, -1, n+1, n+1);
    int th_path = go(edges, n, n+1, n);
    
    int ans = min({st_path, nd_path, rd_path, th_path});
    
    cout << ans << endl;
}
