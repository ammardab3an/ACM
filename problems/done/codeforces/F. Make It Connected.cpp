// Problem: F. Make It Connected
// Contest: Codeforces - Codeforces Round #529 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1095/F
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int par[NMAX];
int par_mn[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool merge(int u, int v){
	
	if((u=get_par(u))==(v=get_par(v))){
		return false;
	}
	
	if(rand()&1) swap(u, v);
	
	par[u] = v;
	par_mn[v] = min(par_mn[v], par_mn[u]);
		
	return true;	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vi val(n);
    for(auto &i : val) cin >> i;
    
    vector<iii> edges(m);
    for(auto &[d, uv] : edges){
    	auto &[u, v] = uv;
    	cin >> u >> v >> d;
    	u--, v--;
    }
    
    for(int i = 0; i < n; i++){
    	par[i] = i;
    	par_mn[i] = val[i];
    }
    
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    
    set<pii> st;
    for(int i = 0; i < n; i++){
    	st.insert({val[i], i});
    }
    
    int ans = 0;
    
    while(st.size() > 1){
	    
    	int mn_d = (st.begin()->first) + ((++st.begin())->first);
    	
    	if(edges.empty() || (mn_d < edges.back().first)){
    		
    		pii a = *st.begin();
    		st.erase(st.begin());
    		pii b = *st.begin();
    		st.erase(st.begin());
    		
    		ans += a.first + b.first;
    		merge(a.second, b.second);
    		
    		int r = get_par(a.second);
    		st.insert({par_mn[r], r});
    	}
    	else{
    		
    		int d = edges.back().first;
    		auto [u, v] = edges.back().second;
    		edges.pop_back();
    		
    		int pu = get_par(u);
    		int pv = get_par(v);
    		
    		if(pu==pv) continue;
    		
    		st.erase(st.find({par_mn[pu], pu}));
    		st.erase(st.find({par_mn[pv], pv}));
    		
    		ans += d;
    		merge(u, v);
    		
    		int r = get_par(u);
    		st.insert({par_mn[r], r});
    	}
    }
    
    cout << ans << endl;
}
