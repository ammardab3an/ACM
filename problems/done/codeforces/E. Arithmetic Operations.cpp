// Problem: E. Arithmetic Operations
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/E
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
const int SQRT = 400;

int mem[NMAX];
int vis[NMAX], vid;
vi adj[NMAX];
int frq[2*NMAX*SQRT];

int go(int i){
	
	int &ret = mem[i];
	if(vis[i]==vid) return ret;
	vis[i] = vid;
	
	int ans = 0;
	for(auto v : adj[i]){
		ans = max(ans, go(v));
	}
	
	return ret = ans+1;
}

int solve(const vi &vec){
	
	int n = vec.size();
	int ans = 1;
	
    for(int i = 0; i <= SQRT; i++){
    	for(int j = 0; j < n; j++){
    		int p = NMAX*SQRT + vec[j]-j*i;
    		ans = max(ans, ++frq[p]);
    	}
    	for(int j = 0; j < n; j++){
    		int p = NMAX*SQRT + vec[j]-j*i;
    		frq[p]--;
    	}
    }
    
    vector<iii> edges;
    
    for(int i = 0; i < n; i++){
    	for(int j = i+1; j < n; j++){
    		
    		if(100000 <= SQRT*(j-i)){
    			break;
    		}
    		
    		int x = (vec[j]-vec[i])/(j-i);
    		int r = (vec[j]-vec[i])%(j-i);
    		
    		if(r==0 && x > SQRT){
    			edges.push_back({x, {i, j}});
    		}
    	}
    }
    
    sort(edges.begin(), edges.end());
    
    int i = 0;
    while(i < edges.size()){
    	
    	int j = i;
    	while((j+1 < edges.size()) && (edges[i].first==edges[j+1].first)){
    		j++;
    	}
    	
    	for(int k = i; k <= j; k++){
    		auto [u, v] = edges[k].second;
    		adj[u].push_back(v);
    	}
    	
    	vid++;
    	
    	for(int k = i; k <= j; k++){
    		auto [u, v] = edges[k].second;
    		ans = max(ans, go(u));
    	}
    	
    	for(int k = i; k <= j; k++){
    		auto [u, v] = edges[k].second;
    		adj[u].clear();
		}
		
		i = j+1;
    }
    
    return n-ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    if(n==0){
    	n = 1e5;
    	vec = vi(n, 1);
    }
    
    int st_path = solve(vec);
    reverse(vec.begin(), vec.end());
    int nd_path = solve(vec);
    
    int ans = min(st_path, nd_path);
    cout << ans << endl;
}
