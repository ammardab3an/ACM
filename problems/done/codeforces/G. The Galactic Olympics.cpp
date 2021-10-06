// Problem: G. The Galactic Olympics
// Contest: Codeforces - 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// URL: https://codeforces.com/gym/101147/problem/G
// Memory Limit: 64 MB
// Time Limit: 2000 ms
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
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (a + b) % MOD;
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

int fac[NMAX], ifac[NMAX];

void init(){
    
    fac[0] = 1;
    for(int i = 1; i < NMAX; i++) fac[i] = mul(fac[i-1], i);
    
    ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
    for(int i = NMAX-2; i >= 0; i--) ifac[i] = mul(ifac[i+1], i+1);
    
}

int choose(int n, int c){
    return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

int mem[1010][1010];

int s(int i, int j){
    
    if(!i) return 0;
    if(j==1) return 1;
    
    int &ret = mem[i][j];
    if(ret+1) return ret;
    
    int st_path = s(i-1, j-1);
    int nd_path = mul(j, s(i-1, j));
    
    return ret = add(st_path, nd_path);
}

int32_t main(){
      
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("galactic.in", "r", stdin);
    
    init();
    
    memset(mem, -1, sizeof mem);
    
    int t; cin >> t; while(t--){

        int n, k;
        cin >> n >> k;
        
        if(k > n){
            cout << 0 << endl;
            continue;
        }
        
        int ans = s(n, k);
        ans = mul(ans, fac[k]);
        
        cout << ans << endl;
    }	
}
