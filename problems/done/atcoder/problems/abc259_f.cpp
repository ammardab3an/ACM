// Problem: F - Select Edges
// Contest: AtCoder - AtCoder Beginner Contest 259
// URL: https://atcoder.jp/contests/abc259/tasks/abc259_f
// Memory Limit: 1024 MB
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
 
const int NMAX = 3e5 + 10;

int n;
int mx[NMAX];
vpii adj[NMAX];
int mem[NMAX][2];

int go(int u, int p, bool b){
	
	int &ret = mem[u][b];
	if(ret+1) return ret;	
	
	int ans = 0;
	
	vi tmp;
	for(auto [v, w] : adj[u]) if(v != p){
		if(mx[v] && w > 0){
			ans += w + go(v, u, 1);
			tmp.push_back(go(v, u, 0) - (w + go(v, u, 1)));
		}
		else{
			ans += go(v, u, 0);
		}
	}
	
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	
	int cnt = int(tmp.size()) - (mx[u]-b);
	cnt = max(cnt, int(0));
	
	for(int i = 0; i < cnt; i++){
		ans += tmp[i];
	}
	
	for(int i = cnt; i < tmp.size(); i++) if(tmp[i] > 0){
		ans += tmp[i];
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> mx[i];
    }
    
    for(int i = 0; i < n-1; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(0, -1, 0);
    cout << ans << endl;
}
