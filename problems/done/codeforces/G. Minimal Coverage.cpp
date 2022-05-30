// Problem: G. Minimal Coverage
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1579/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int NMAX = 1e4 + 10;

int n;
int arr[NMAX];
int mem[NMAX][2020];
int vis[NMAX][2020], vid;

int go(int i, int cur){
	
	if(cur < 0 || cur > 2000){
		return INF;
	}
	
	if(i == n){
		return cur;
	}
	
	int &ret = mem[i][cur];
	if(vis[i][cur]==vid) return ret;
	vis[i][cur] = vid;
	
	int st_path = go(i+1, cur+arr[i]);
	int nd_path = go(i+1, cur-arr[i]);
	
	return ret = max(cur, min(st_path, nd_path));
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		vid++;
		int ans = INF;
		
		for(int i = 0; i < 2000; i++){
			int cans = go(0, i);
			ans = min(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
