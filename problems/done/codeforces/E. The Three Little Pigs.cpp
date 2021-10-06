// Problem: E. The Three Little Pigs
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/E
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 3e6 + 10;

int fac[NMAX], ifac[NMAX];

void init(){
    fac[0] = 1;
    for(int i = 1; i < NMAX; i++) fac[i] = mul(fac[i-1], i);
    ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
    for(int i = NMAX-2; i >= 0; i--) ifac[i] = mul(ifac[i+1], i+1);
}

int choose(int n, int r){
    return mul(mul(fac[n], ifac[r]), ifac[n-r]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
        
    int n, m;
    cin >> n >> m;
    
    vector<vi> dp(3*n + 1, vi(3));
    
    dp[0][0] = dp[0][1] = dp[0][2] = n;
    
    int div_3 = pow_exp(3, MOD-2);
    
    for(int i = 1; i <= 3*n; i++){
            
        // dp[i][0] + dp[i][1] + dp[i][2] = choose(3*n, i+1)
        // dp[i][1] = dp[i][0] + dp[i-1][0]
        // dp[i][2] = dp[i][1] + dp[i-1][1]
        
        // dp[i][0] + dp[i][1] + dp[i][1] + dp[i-1][1] = choose(3*n, i+1)
        // dp[i][0] = choose(3*n, i+1) - 2 * (dp[i][0] + dp[i-1][0]) - dp[i-1][1]
        // 3 * dp[i][0] = choose(3*n, i+1) -2 * dp[i-1][0] - dp[i-1][1]
        
        dp[i][0] = add(choose(3*n, i+1), add(mul(-2, dp[i-1][0]), -dp[i-1][1]));
        dp[i][0] = mul(dp[i][0], div_3);
        
        dp[i][1] = add(dp[i][0], dp[i-1][0]);
        dp[i][2] = add(dp[i][1], dp[i-1][1]);
        
    }
    
    while(m--){
        
        int x;
        cin >> x;
        
        int cans = add(dp[x][0], choose(3*n, x));
        
        cout << cans << endl;
    }
}
