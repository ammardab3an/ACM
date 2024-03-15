// Problem: G. Rudolf and Subway
// Contest: Codeforces - Codeforces Round 933 (Div. 3)
// URL: https://codeforces.com/contest/1941/problem/G
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
const int NMAX = 2e5 + 10;
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		vi tmp;
		vector<vi> adj(n);
		
		for(int i = 0; i < m; i++){
			int u, v, c;
			cin >> u >> v >> c;
			u--, v--;
			adj[u].push_back(c);
			adj[v].push_back(c);
			tmp.push_back(c);
		}
		
		int s, d;
		cin >> s >> d;
		s--, d--;
		
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		
		int sz = tmp.size();
		adj.resize(n+sz);
		
		for(int i = 0; i < n; i++){
			for(auto &c : adj[i]){
				c = n + lower_bound(tmp.begin(), tmp.end(), c) - tmp.begin();
				adj[c].push_back(i);
			}
		}
		
		int ans = -1;
		queue<int> que;
		vector<int> dist(n+sz, -1);

		dist[s] = 0;
		que.push(s);
		
		while(!que.empty()){
			
			int u = que.front();
			que.pop();
			
			int cd = dist[u];
			
			if(u==d){
				ans = cd;
				break;
			}
			
			for(auto v : adj[u]) if(dist[v]==-1){
				dist[v] = cd + (v >= n);
				que.push(v);
			}
		}		
		
		cout << ans << endl;
    }	
}
