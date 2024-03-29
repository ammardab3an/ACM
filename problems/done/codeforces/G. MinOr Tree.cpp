// Problem: G. MinOr Tree
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: http://codeforces.com/contest/1624/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
int get_par(int n){
	return par[n] = par[n]==n ? n : get_par(par[n]);
}

void merge(int u, int v){
	
	if((u=get_par(u)) == (v=get_par(v))){
		return;
	}	
	
	if(rand()&1) swap(u, v);
	par[u] = v;
}

bool can(int n, vector<iii> edges){
	
	iota(par, par+n, 0);
	
	for(auto e: edges){
		merge(e.second.first, e.second.second);
	}
	
	bool ret = true;
	int pp = get_par(0);
	for(int i = 0; i < n; i++){
		if(get_par(i) != pp){
			ret = false;
			break;
		}
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){	

		
		int n, m;
		cin >> n >> m;
		
		vector<iii> edges(m);
		for(auto &e : edges){
			cin >> e.second.first >> e.second.second >> e.first;
			e.second.first--;
			e.second.second--;
		}
		
		int ans = (1ll << 31)-1;
		
		for(int i = 30; i >= 0; i--){
			
			vector<iii> new_edges;
			for(auto e : edges) if(((e.first>>i)&1) == 0){
				new_edges.push_back(e);
			}
			
			if(can(n, new_edges)){
				edges = new_edges;
				ans ^= (1 << i);
			}
		}
		
		cout << ans << endl;
    }	
}
