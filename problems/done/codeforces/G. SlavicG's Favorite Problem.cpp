// Problem: G. SlavicG's Favorite Problem
// Contest: Codeforces - Codeforces Round #835 (Div. 4)
// URL: https://codeforces.com/contest/1760/problem/G
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

vpii adj[NMAX];

void go(int u, int p, vi &vec, int cur, bool b, int other){
	
	if(!b){
		vec.push_back(cur);
	}
	
	for(auto [v, w] : adj[u]) if(v != p) if(v != other){
		go(v, u, vec, cur^w, 0, other);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, a, b;
		cin >> n >> a >> b;
		a--, b--;
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
		}
		
		for(int i = 0; i < n-1; i++){
			
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		
		vi vec_a, vec_b;
		
		go(a, -1, vec_a, 0, 0, b);
		go(b, -1, vec_b, 0, 1, -1);
		
		sort(vec_a.begin(), vec_a.end());
		sort(vec_b.begin(), vec_b.end());
		
		// for(auto i : vec_a) cout << i << ' '; cout << endl;
		// for(auto i : vec_b) cout << i << ' '; cout << endl;
		
		bool ans = false;
		for(auto i : vec_a){
			if(binary_search(vec_b.begin(), vec_b.end(), i)){
				ans = true;
				break;
			}
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
