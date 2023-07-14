// Problem: E. Labeling the Tree with Distances
// Contest: Codeforces - Codeforces Round 856 (Div. 2)
// URL: https://codeforces.com/contest/1794/problem/E
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = 3; // ceil(sqrt(double(NMAX)));

int n;
vi adj[NMAX];
array<int, 2> good_hash, m, p, pow_m[NMAX], hash_sub[NMAX];
pair<array<int, 2>, int> pow_m_sorted[NMAX];
vi ans;

bool is_prime(int x){
	for(int i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

void init(){
	
	p = {rand(1e9, 2e9), rand(1e9, 2e9)};
	m = {rand(1e6, 2e6), rand(1e6, 2e6)};
	
	for(int i = 0; i < 2; i++){
		while(!is_prime(p[i])) p[i]++;
		while(!is_prime(m[i])) m[i]++;
	}
	
	pow_m[0] = {1, 1};
	for(int j = 1; j < NMAX; j++){
		for(int i = 0; i < 2; i++){
			pow_m[j][i] = (pow_m[j-1][i] * m[i]) % p[i];		
		}
	}
	
	for(int i = 0; i < NMAX; i++){
		pow_m_sorted[i] = {pow_m[i], i};
	}
	
	sort(pow_m_sorted, pow_m_sorted+NMAX);
}

int get_m(const array<int, 2> &h){
	
	int p = lower_bound(pow_m_sorted, pow_m_sorted+NMAX, 
				pair<array<int, 2>, int>({h, -1})) - pow_m_sorted;
	
	if(p==NMAX || pow_m_sorted[p].first!=h){
		return -1;
	}
	else{
		return pow_m_sorted[p].second;
	}
}

array<int, 2> calc(const vi &vec){
	
	array<int, 2> ret = {0, 0};
	
	for(int i = 0; i < 2; i++){
		for(auto e : vec){
			ret[i] = (ret[i] + pow_m[e+1][i]) % p[i];
		}
	}	
	
	return ret;
}

void dfs(int u, int _p){
	
	auto cur = pow_m[1];
	
	for(auto v : adj[u]) if(v != _p){

		dfs(v, u);

		auto nxt = hash_sub[v];
		for(int i = 0; i < 2; i++){
			cur[i] = (cur[i] + (nxt[i] * m[i])) % p[i];
		}
	}	
	
	hash_sub[u] = cur;
}

void go(int u, int _p){
	
	
	{
		auto dif = hash_sub[u];
		for(int i = 0; i < 2; i++){
			dif[i] = (dif[i] - good_hash[i]) % p[i];
			dif[i] = (dif[i] + p[i]) % p[i];
		}
		
		int r = get_m(dif);
		
		if(1 <= r && r <= n){
			ans.push_back(u+1);
		}
	}
	
	auto &cur = hash_sub[u];
	
	for(auto v : adj[u]) if(v != _p){
		
		auto &nxt = hash_sub[v];
		
		for(int i = 0; i < 2; i++){
			cur[i] = (cur[i] - (nxt[i] * m[i])) % p[i];
			cur[i] = (cur[i] + p[i]) % p[i];
		}
		for(int i = 0; i < 2; i++){
			nxt[i] = (nxt[i] + (cur[i] * m[i])) % p[i];
		}
		
		go(v, u);
		
		for(int i = 0; i < 2; i++){
			nxt[i] = (nxt[i] - (cur[i] * m[i])) % p[i];
			nxt[i] = (nxt[i] + p[i]) % p[i];
		}
		for(int i = 0; i < 2; i++){
			cur[i] = (cur[i] + (nxt[i] * m[i])) % p[i];
		}
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    
    cin >> n;
    
    vi vals(n-1);
    for(auto &i : vals) cin >> i;
    
    init();
    good_hash = calc(vals);
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    dfs(0, -1);
    go(0, -1);
    
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(auto e : ans) cout << e << ' '; 
    cout << endl;   
}
