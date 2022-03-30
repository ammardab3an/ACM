// Problem: D. Weight the Tree
// Contest: Codeforces - Codeforces Round #774 (Div. 2)
// URL: https://codeforces.com/contest/1646/problem/D
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

int n;
vi adj[NMAX];
pii mem[NMAX][3];
int nxt[NMAX][3];
int val[NMAX];

pii go(int u, int par, int good){
	
	pii &ret = mem[u][good+1];
	if(ret.first+1) return ret;
	
	pii st_path = {0, -1};
	pii nd_path = {1, -(int)adj[u].size()};
	
	for(auto v : adj[u]) if(v != par){
		pii st_tmp = go(v, u, 1);
		pii nd_tmp = go(v, u, 0);
		st_path.first += st_tmp.first;
		st_path.second += st_tmp.second;
		nd_path.first += nd_tmp.first;
		nd_path.second += nd_tmp.second;
	}
	
	if(good==0 || (st_path > nd_path)){
		nxt[u][good+1] = 1;
		return ret = st_path;
	}
	else{
		nxt[u][good+1] = 0;
		return ret = nd_path;
	}
}

void calc(int u, int par, int good){
	
	if(nxt[u][good+1]){
		val[u] = 1;
		for(auto v : adj[u]) if(v != par){
			calc(v, u, 1);
		}
	}	
	else{
		val[u] = adj[u].size();
		for(auto v : adj[u]) if(v != par){
			calc(v, u, 0);
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
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    if(n == 2){
    	cout << "2 2" << endl;
    	cout << "1 1" << endl;
    	return 0;
    }
	
	memset(mem, -1, sizeof mem);
	
	pii tmp = go(0, -1, -1);
	cout << tmp.first << ' ' << -tmp.second << endl;

	calc(0, -1, -1);
	for(int i = 0; i < n; i++) cout << val[i] << ' '; cout << endl;
}
