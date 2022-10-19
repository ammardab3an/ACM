// Problem: D. Paths on the Tree
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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


vi adj[NMAX];
int arr[NMAX];
map<int, int> mem[NMAX];

int go(int u, int k){
	
	if(adj[u].empty()){
		return k * arr[u];
	}
	
	auto it = mem[u].find(k);
	if(it != mem[u].end()) return it->second;
	
	int cn = k / (int)(adj[u].size());
	int rm = k % (int)(adj[u].size());
	
	vi val(adj[u].size());
	
	if(rm){
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			val[i] = go(v, cn+1)-go(v, cn);
		}
	}
	
	vi pos(adj[u].size());
	iota(pos.begin(), pos.end(), 0);
	sort(pos.begin(), pos.end(), [&](int i, int j){
		return val[i] > val[j];
	});
	
	int ans = k * arr[u];
	
	for(int i = 0; i < rm; i++){
		ans += go(adj[u][pos[i]], cn+1);
	}
	for(int i = rm; i < adj[u].size(); i++){
		ans += go(adj[u][pos[i]], cn);
	}
	
	return mem[u][k] = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
			mem[i].clear();
		}
		
		for(int i = 1; i < n; i++){
			int pi;
			cin >> pi;
			pi--;
			adj[pi].push_back(i);
		}
		
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		int ans = go(0, k);
		cout << ans << endl;
    }	
}
