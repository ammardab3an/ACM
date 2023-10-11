// Problem: E. Speedrun
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1863/problem/E
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

pii merge(const pii &a, const pii &b){
	if(a.first != b.first){
		return a.first > b.first ? a : b;
	}
	else{
		return a.second < b.second ? a : b;
	}
}

int n, m, k;
vi adj[NMAX];
int val[NMAX];
pii calc[NMAX];
bool vis[NMAX];

void dfs(int u){
	
	if(vis[u]) return;
	
	vis[u] = true;
	calc[u] = {0, val[u]};
	
	for(auto v : adj[u]){	
	
		dfs(v);
		
		pii nxt = calc[v];
		
		if(val[v] > val[u]){
			nxt.first++;
		}
		
		calc[u] = merge(calc[u], nxt);
	}
}

int32_t main(){
    
    fastIO;
    
    int t; cin >> t; while(t--){

		cin >> n >> m >> k;
		
		for(int i = 0; i < n; i++){
			cin >> val[i];
		}
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[v].push_back(u);
		}
		
		for(int i = 0; i < n; i++){
			vis[i] = false;
		}
		
		for(int i = 0; i < n; i++) dfs(i);
		
		vpii tmp;
		int mx_d = 0;
		for(int i = 0; i < n; i++) mx_d = max(mx_d, calc[i].first);
		
		for(int i = 0; i < n; i++){
			
			pii cur = calc[i];
			
			if(cur.first >= mx_d-1){
				tmp.push_back({calc[i].second, val[i] + cur.first*k});
			}
		}
		
		sort(tmp.begin(), tmp.end());
		
		// cout << mx_d << endl;
		// for(auto [a, b] : tmp){
			// cout << a << ' ' << b << endl;
		// }
		
		int sz = tmp.size();
		
		vi pre(sz);
		for(int i = 0; i < sz; i++){
			pre[i] = tmp[i].second;
			if(i) pre[i] = max(pre[i], pre[i-1]);
		}
		vi suf(sz);
		for(int i = sz-1; i >= 0; i--){
			suf[i] = tmp[i].second;
			if(i+1 < sz) suf[i] = max(suf[i], suf[i+1]);
		}
		
		int ans = INFLL;
		
		for(int i = 0; i < sz; i++){
			
			int s = tmp[i].first;
			
			int st_path = 0;
			int nd_path = 0;
			
			int p = lower_bound(tmp.begin(), tmp.end(), (pii){s, -1}) - tmp.begin();
			
			if(p != sz){
				st_path = suf[p] - s; 
			}
			
			if(p != 0){
				nd_path = pre[p-1] + (k-s);
			}
			
			// cout << s << ' ' << st_path << ' ' << nd_path << endl;
			
			ans = min(ans, max(st_path, nd_path));
		}
		
		cout << ans << endl;
    }	
}
