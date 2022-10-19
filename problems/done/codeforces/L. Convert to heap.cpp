// Problem: L. Convert to heap
// Contest: Codeforces - 2021 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/103577/problem/L
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

const int AMAX = 1000*1000+10;

int n, q;
vi adj[NMAX];
int arr[NMAX];
bitset<AMAX> can;
vi vals;
bool bad = false;

void go(int u, int p){
	
	if(bad) return;
	
	int mx = 0;
	for(auto v : adj[u]) if(v != p){
		go(v, u);
		mx = max(mx, arr[v]);
	}
	
	if(arr[u] < mx){
		
		int dif = mx-arr[u];
		int p = lower_bound(vals.begin(), vals.end(), dif)-vals.begin();
		
		if(p==vals.size()){
			bad = true;
			return;
		}
		
		arr[u] += vals[p];
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> q;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    for(int i = 0; i < n-1; i++){
    	
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    can[0] = 1;
    
    for(int i = 0; i < q; i++){
    	int xi;
    	cin >> xi;
    	can |= can << xi;
    }
    
    for(int i = 0; i < AMAX; i++){
    	if(can[i]){
    		vals.push_back(i);
    	}
    }
    
    go(0, -1);
    
    if(bad){
    	cout << -1 << endl;
    }
    else{
	    int ans = 0;
	    for(int i = 0; i < n; i++){
	    	ans += arr[i];
	    }
	    
	    cout << ans << endl;
    }
}
