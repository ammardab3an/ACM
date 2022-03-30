// Problem: Snakes capturing the Mongoose Cities
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/CAPTCITI
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

// #define endl '\n'
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
int arr_a[NMAX], arr_b[NMAX];
int mem[NMAX][2];

int go(int u, int par, int b){
	
	int &ret = mem[u][b];
	if(ret+1) return ret;
	
	vpii nxt;
	for(auto v : adj[u]) if(v != par){
		nxt.push_back({go(v, u, 0), go(v, u, 1)});
	}	
	
	int st_path=INFLL;
	int nd_path=INFLL;
	
	{
		st_path = arr_a[u];
		for(auto p : nxt){
			st_path += p.second;
		}
	}
	
	{
		int rm = max((int)(0), arr_b[u]-b);
		sort(nxt.begin(), nxt.end(), [&](const pii &a, const pii &b){
			return a.first-a.second < b.first-b.second;
		});
		
		if(rm <= nxt.size()){
			nd_path = 0;
			for(int i = 0; i < rm; i++){
				nd_path += nxt[i].first;
			}
			for(int i = rm; i < nxt.size(); i++){
				nd_path += nxt[i].second;
			}
		}
	}
	
	return ret = min(st_path, nd_path);
}

int32_t main(){
    
    // fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n;
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
		
		for(int i = 0; i < n; i++) cin >> arr_a[i];
		for(int i = 0; i < n; i++) cin >> arr_b[i];
		
		memset(mem, -1, sizeof mem);
		
		int ans = go(0, -1, 0);
		cout << ans << endl;
    }	
}
