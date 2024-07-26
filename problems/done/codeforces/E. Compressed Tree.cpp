// Problem: E. Compressed Tree
// Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1901/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

int ans;
int val[NMAX];
vi adj[NMAX];
int sm_pos[NMAX];
int cnt_pos[NMAX];
multiset<int> mst[NMAX];
int cans[NMAX];

int calc(int u){
	
	int st_path = val[u];
	int nd_path = -INFLL;
	int rd_path = -INFLL;
	
	if(mst[u].size() >= 1){
		nd_path = *mst[u].rbegin();
	}
	
	if(mst[u].size() >= 2){
		
		rd_path = val[u];
		
		if(cnt_pos[u] >= 2){
			rd_path += sm_pos[u];
		}
		else{
			auto it = mst[u].rbegin();
			rd_path += *(it++);
			rd_path += *(it++);
		}
	}
	
	return max(st_path, max(nd_path, rd_path));
}

void dfs(int u, int p){
	
	sm_pos[u] = 0;
	cnt_pos[u] = 0;
	mst[u].clear();
	
	for(auto v : adj[u]) if(v != p){
		
		dfs(v, u);
		
		if(cans[v] >= 0){		
			sm_pos[u] += cans[v];
			cnt_pos[u] += 1;
		}
		
		mst[u].insert(cans[v]);
	}
	
	cans[u] = calc(u);
	
	// cout << u+1 << ' ' << cans[u] << endl;
}

void unlink(int u, int v){
	if(cans[v] >= 0){
		sm_pos[u] -= cans[v];
		cnt_pos[u] -= 1;
	}
	mst[u].erase(mst[u].find(cans[v]));
	cans[u] = calc(u);
}

void link(int u, int v){	
	if(cans[v] >= 0){
		sm_pos[u] += cans[v];
		cnt_pos[u] += 1;
	}
	mst[u].insert(cans[v]);
	cans[u] = calc(u);
}

void go(int u, int p){
	
	int st_path = val[u];
	int nd_path = 0;
	int rd_path = 0;
	int th_path = 0;
	
	if(mst[u].size() >= 1){
		nd_path = val[u] + *mst[u].rbegin();	
	}
	
	if(mst[u].size() >= 2){
		auto it = mst[u].rbegin();
		rd_path += *(it++);
		rd_path += *(it++);
	}
	
	if(mst[u].size() >= 3){
		th_path += val[u];
		if(cnt_pos[u] >= 3){
			th_path += sm_pos[u];
		}
		else{
			auto it = mst[u].rbegin();
			th_path += *(it++);
			th_path += *(it++);
			th_path += *(it++);
		}
	}
	
	int cur_ans = max(max(st_path, nd_path), max(rd_path, th_path));
	ans = max(ans, cur_ans);
	
	// cout << u+1 << ' ' << cur_ans << endl;
	
	for(auto v : adj[u]) if(v != p){		
		
		unlink(u, v);
		link(v, u);
		
		go(v, u);
		
		unlink(v, u);
		link(u, v);
	}
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

		int n;
		cin >> n;
		
		for(int i = 0; i < n; i++){
			cin >> val[i];
		}
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		ans = 0;
		dfs(0, -1);
		go(0, -1);
		
		cout << ans << endl;
    }	
}
