// Problem: D1. Up the Strip (simplified version)
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/D1
// Memory Limit: 128 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * a * b) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * a + b) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

const int NMAX = 4e6 + 10;

int arr[NMAX];
int mem[NMAX];
int pre;

int go(int i){
    
    if(i == 1) return 1;
    
    int &ret = mem[i];
    if(ret+1) return ret;
    
    int st_path = pre;
    int nd_path = 0;
    
    int ci = i;
    int cj = 1;
    
    while(cj < i){
        int t = (i/(cj+1));
        nd_path = add(nd_path, mul(ci-t, go(cj)));
        ci = t;
        if(!t) break;
        cj = i/t;
    }   
     
    int ans = add(st_path, nd_path);
    
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
    cin >> n >> MOD;
    
    memset(mem, -1, sizeof mem);
    
    for(int i = 1; i <= n; i++) pre += go(i), pre %= MOD;
    
    cout << go(n) << endl;
}
