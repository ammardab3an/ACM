// Problem: D. 2+ doors
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1715/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

int n, q;
int val[NMAX][31];
vi adj[NMAX][31];

void solve(int j){
	
	for(int i = 0; i < n; i++) if(val[i][j]==1){
		
		bool can = true;
		for(auto v : adj[i][j]){
			if((val[v][j]==0) || (v==i)){
				can = false;
				break;
			}
		}	
		
		if(can){
			val[i][j] = 0;
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
    
	cin >> n >> q;
	
	memset(val, -1, sizeof val);
	
	for(int i = 0; i < q; i++){
		
		int l, r, x;
		cin >> l >> r >> x;
		l--, r--;
		
		for(int j = 0; j < 31; j++){
			if((x>>j)&1){
				if(val[l][j]==-1) val[l][j] = 1;
				if(val[r][j]==-1) val[r][j] = 1;
				adj[l][j].push_back(r);
				adj[r][j].push_back(l);
			}
			else{
				val[l][j]=val[r][j] = 0;
			}
		}
	}
	
	for(int j = 0; j < 31; j++){
		solve(j);
	}
	
	vi vec(n);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < 31; j++) if(val[i][j]==1){
		vec[i] |= 1<<j;	
	}
	
	for(auto i : vec) cout << i << ' '; cout << endl;
}
