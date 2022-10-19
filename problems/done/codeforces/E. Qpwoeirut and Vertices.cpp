// Problem: E. Qpwoeirut and Vertices
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/E
// Memory Limit: 256 MB
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

struct DSU{
	
	int n;
	vi par;
	vi nxt;
	vector<vi> ch;
	
	DSU(int _n){
		n = _n;
		par = vi(n);
		nxt = vi(n);
		ch = vector<vi>(n);
		iota(par.begin(), par.end(), 0);
		iota(nxt.begin(), nxt.end(), 0);
		for(int i = 0; i < n; i++){
			ch[i].push_back(i);
		}
	}	
	
	int get_par(int u){
		return par[u] = (par[u]==u) ? u : get_par(par[u]);
	}
	int get_nxt(int u){
		return nxt[u] = (nxt[u]==u) ? u : get_nxt(nxt[u]);	
	}
	
	void fix(int u){
		int par_u = get_par(u);
		if(u){
			if(get_par(u-1) == par_u){
				nxt[u-1] = u;
			}
		}	
		if(u+1 < n){
			if(get_par(u+1) == par_u){
				nxt[u] = u+1;
			}
		}
	}
	
	bool merge(int u, int v){
		
		u = get_par(u);
		v = get_par(v);
		
		if(u==v) return false;
		
		if(ch[u].size() > ch[v].size()) swap(u, v);
		
		par[u] = v;
		
		for(auto w : ch[u]){
			ch[v].push_back(w);
			fix(w);	
		}
		
		ch[u].clear();
		
		return true;
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, m, q;
		cin >> n >> m >> q;
		
		m++;
		vpii edges(m);
		edges[0] = {0, 0};
		for(int i = 1; i < m; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			edges[i] = {u, v};
		}
		
		vpii queries(q);
		for(auto &p : queries){
			int l, r;
			cin >> l >> r;
			l--, r--;
			p = {l, r};
		}
		
		queue<pair<pii, vi>> que;
		que.push({{0, m-1}, vi(q)});
		iota(que.front().second.begin(), que.front().second.end(), 0);
		
		DSU dsu(n);
		int cur = INF;
		vi ans(q);
		
		while(!que.empty()){
			
			auto &fr = que.front();
			
			int l = fr.first.first;
			int r = fr.first.second;
			auto &v = fr.second;
			
			if(l==r){
				for(auto i : v) ans[i] = l;
				que.pop();
				continue;
			}
			
			int mid = (l+r)/2;
			
			if(cur <= mid){
				for(int i = cur; i <= mid; i++){
					int u = edges[i].first;
					int v = edges[i].second;
					dsu.merge(u, v);
				}
			}
			else{
				dsu = DSU(n);
				for(int i = 0; i <= mid; i++){
					int u = edges[i].first;
					int v = edges[i].second;
					dsu.merge(u, v);
				}
			}
			
			cur = mid;
			
			vi lf, ri;
			for(auto i : v){
				
				int l = queries[i].first;
				int r = queries[i].second;
				
				if(r <= dsu.get_nxt(l)){
					lf.push_back(i);
				}
				else{
					ri.push_back(i);
				}
			}
			
			if(!lf.empty()) que.push({{l, mid}, lf});
			if(!ri.empty()) que.push({{mid+1, r}, ri});
			que.pop();
		}
		
		for(auto i : ans) cout << i << ' '; cout << endl;
    }	
}
