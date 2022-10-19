// Problem: D. Flood Fill
// Contest: Codeforces - Codeforces Round #538 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1114/D
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
 
const int NMAX = 5e3 + 10;

int sz;
int arr[NMAX];
int mem[NMAX][NMAX];

int go(int l, int r){
	
	if(l==0 && r==sz-1){
		return 0;
	}	
	
	int &ret = mem[l][r];
	if(ret+1) return ret;
	
	int ans = INF;
	
	if(l != 0){
		
		int nl = l-1;
		int nr = r;
		
		if((nr!=sz-1) && (arr[nl]==arr[nr+1])) nr++;
		
		int cans = 1+go(nl, nr);
		ans = min(ans, cans);
	}
	
	if(r != sz-1){
		
		int nl = l;
		int nr = r+1;
		
		if((nl!=0) && (arr[nl-1]==arr[nr])) nl--;
		
		int cans = 1+go(nl, nr);
		ans = min(ans, cans);
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
    
    int n;
    cin >> n;
    
    int lst = -1;
    for(int i = 0; i < n; i++){
    	int ai;
    	cin >> ai;
    	if(ai != lst){
    		arr[sz++] = ai;
    	}
    	lst = ai;
    }
    
    // for(int i = 0; i < sz; i++){
    	// cout << arr[i] << ' ';
    // } cout << endl;
    
    memset(mem, -1, sizeof mem);
    
    int ans = INF;
    for(int i = 0; i < sz; i++){
    	int cans = go(i, i);
    	ans = min(ans, cans);
    }
    
    cout << ans << endl;
}
