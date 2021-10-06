// Problem: D. Caesar's Legions
// Contest: Codeforces - Codeforces Beta Round #89 (Div. 2)
// URL: https://codeforces.com/problemset/problem/118/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
const int MOD = 100000000; //1e9 + 7;
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

int k1, k2;
int mem[111][111][11][11];

int go(int n1, int n2, int l0, int l1){
    
    if(n1==0 && n2==0) return 1;
    
    int &ret = mem[n1][n2][l0][l1];
    if(ret+1) return ret;
    
    int st_path = n1 && (l0+1 <= k1) ? go(n1-1, n2, l0+1, 0) : 0;
    int nd_path = n2 && (l1+1 <= k2) ? go(n1, n2-1, 0, l1+1) : 0;
    
    return ret = add(st_path, nd_path);    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n1, n2;
    // freopen("name.in", "r", stdin);
    
    cin >> n1 >> n2 >> k1 >> k2;
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(n1, n2, 0, 0);
    cout << ans << endl;
}
