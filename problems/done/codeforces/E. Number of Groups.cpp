// Problem: E. Number of Groups
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/E
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
int sz[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool merge(int u, int v){
	
	if((u=get_par(u)) == (v=get_par(v))){
		return false;
	}
	
	if(sz[u]>sz[v]) swap(u, v);
	
	par[u] = v;
	sz[v] += sz[u];
	
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi tmp(2*n);
		int tmp_sz = 0;
		
		vector<iii> vec(n);
		
		for(auto &p : vec){
			
			cin >> p.first >> p.second.first >> p.second.second;
			
			tmp[tmp_sz++] = p.second.first;
			tmp[tmp_sz++] = p.second.second;
		}
		
		sort(tmp.begin(), tmp.end());
		tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
		tmp_sz = tmp.size();
		
		vector<vector<array<int, 3>>> foo(tmp_sz+1);
		
		for(int i = 0; i < n; i++){
			
			auto p = vec[i];
			int c = p.first;
			int l = p.second.first;
			int r = p.second.second;
			
			l = lower_bound(tmp.begin(), tmp.end(), l) - tmp.begin();
			r = lower_bound(tmp.begin(), tmp.end(), r) - tmp.begin();
			
			foo[l].push_back({0, c, i});
			foo[r+1].push_back({1, c, i});
		}
		
		for(int i = 0; i < n; i++){
			par[i] = i;
			sz[i] = 1;
		}
		
		vi vis(n);
		vector<vector<set<int>>> st(2, vector<set<int>>(2));
		
		for(auto v : foo){
			
			for(auto [k, c, i] : v){
				if(k){
					st[c][vis[i]].erase(i);
				}
				else{
					st[c][0].insert(i);
				}
			}
			
			for(auto c : {0, 1}) if(!st[!c][0].empty() || !st[!c][1].empty()){
				
				if(st[c][1].empty() && !st[c][0].empty()){
					int u = *st[c][0].begin();
					st[c][0].erase(st[c][0].begin());
					st[c][1].insert(u);
					vis[u] = 1;
				}
				
				for(auto u : st[c][0]){
					merge(u, *st[c][1].begin());
					st[c][1].insert(u);
					vis[u] = 1;
				}
				
				st[c][0].clear();
			}
			
			
			if(!st[0][1].empty() && !st[1][1].empty()){
				int u = *st[0][1].begin();
				int v = *st[1][1].begin();
				merge(u, v);
			}
		}
		
		set<int> _st;
		for(int i = 0; i < n; i++){
			_st.insert(get_par(i));
		}
		
		cout << _st.size() << endl;
    }	
}
