// Problem: A. Awesome Shawarma
// Contest: Codeforces - 2018 Arab Collegiate Programming Contest (ACPC 2018)
// URL: https://codeforces.com/gym/101991/problem/A
// Memory Limit: 1024 MB
// Time Limit: 14000 ms
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
 
const int NMAX = 1e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, l, r;
vi adj[NMAX];
int64_t ans;

struct node{
	
	int lvl = 0;
	int tot_sz = 0;
	vector<vi> sts;
	
	int query(int d){
		
		int nl = (n-1)-r-d-lvl;
		int nr = (n-1)-l-d-lvl;
		
		int ans = 0;
		for(auto &v : sts){
			ans += upper_bound(v.begin(), v.end(), nr) -
				   lower_bound(v.begin(), v.end(), nl);
		}	
		
		return ans;
	}
	
	void swap(node &other){
		std::swap(lvl, other.lvl);
		std::swap(tot_sz, other.tot_sz);
		sts.swap(other.sts);	
	}
	
	void rebuild(){
		
		int p = 0;
		vi nv(tot_sz);
		priority_queue<iii, vector<iii>, greater<iii>> que;
		
		for(int i = 0; i < sts.size(); i++){
			que.push({sts[i].front(), {0, i}});
		}
		
		while(!que.empty()){
			
			auto tp = que.top();
			que.pop();
			
			nv[p++] = tp.first;
			if(tp.second.first+1 < sts[tp.second.second].size()){
				tp.first = sts[tp.second.second][++tp.second.first];
				que.push(tp);
			}
		}
		
		sts = vector<vi>(1, nv);
	}
};

node dfs(int u, int p){
		
	node cur;
	for(auto v : adj[u]) if(v != p){
		
		node nxt = dfs(v, u);
		nxt.sts.push_back(vi(1, 0-nxt.lvl));
		nxt.lvl += 1;
		nxt.tot_sz += 1;
		
		if(nxt.tot_sz > cur.tot_sz){
			cur.swap(nxt);
		}
		
		for(auto &v : nxt.sts){
			for(auto d : v){
				d += nxt.lvl;
				::ans += cur.query(d);
			}
		}
		
		for(auto &v : nxt.sts){
			for(auto &i : v) i += nxt.lvl - cur.lvl;
			cur.sts.push_back(v);
			cur.tot_sz += v.size();
		}
		
		if(cur.sts.size() > BLOCK){
			cur.rebuild();
		}
	}
	
	::ans += cur.query(0);
	
	return cur;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("awesome.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> l >> r;
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		for(int i = 0; i < n-1; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		if(n==0){
			n = 1e5;
			l = 1, r = n-1;
			for(int i = 0; i < n; i++) adj[i].clear();
			// for(int i = 1; i < n; i++) adj[rand(0, i-1)].push_back(i);	
			for(int i = 0; i < n-1; i++) adj[i].push_back(i+1);
		}
		
		ans = 0;
		dfs(0, -1);
		
		cout << ans << endl;
    }	
}
