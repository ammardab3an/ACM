// Problem: F - XOR on Grid Path
// Contest: AtCoder - KYOCERA Programming Contest 2022（AtCoder Beginner Contest 271）
// URL: https://atcoder.jp/contests/abc271/tasks/abc271_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int h, w;
int arr[22][22];
int tmp[22][22];
vector<vi> vals;

void go(int i, int j, int x){
	
	if(i==h){
		return;
	}
	if(i==h-1){
		vals[j].push_back(x);
	}
	
	if(j+1 < w){
		go(i, j+1, x^tmp[i][j+1]);
	}
	if(i+1 <= h){
		go(i+1, j, x^tmp[i+1][j]);
	}
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
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
    	cin >> arr[i][j];
    }
    
    int m = (n+1)/2;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++){
    	tmp[i][j] = arr[i][j];
    }
    
    vals.resize(n);
    
    ::w = n;
    ::h = m;
    for(int i = 0; i < n; i++){
    	vals[i].clear();
    }
    go(0, 0, tmp[0][0]);
    auto a = vals;
    
    
    for(int i = m; i < n; i++)
    for(int j = 0; j < n; j++){
    	tmp[n-i-1][j] = arr[i][n-j-1];
    }
    
    ::w = n;
    ::h = n-m;
    for(int i = 0; i < n; i++){
    	vals[i].clear();
    }
    go(0, 0, tmp[0][0]);
    auto b = vals;
    reverse(b.begin(), b.end());
    
    ll ans = 0;
    
    for(int k = 0; k < n; k++){
    	
    	auto &vals_a = a[k];
    	auto &vals_b = b[k];
    	
    	sort(vals_a.begin(), vals_a.end());
    	
    	for(auto e : vals_b){
    		ans += upper_bound(vals_a.begin(), vals_a.end(), e) - lower_bound(vals_a.begin(), vals_a.end(), e);
    	}	
    }
    
    cout << ans << endl;
}
