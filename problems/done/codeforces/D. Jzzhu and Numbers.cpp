// Problem: D. Jzzhu and Numbers
// Contest: Codeforces - Codeforces Round #257 (Div. 1)
// URL: https://codeforces.com/contest/449/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int NMAX = 1e6 + 10;
const int LOG = ceil(log2(1e6 + 10));

int n;
int pp[NMAX];
int arr[NMAX];
int dp[1 << LOG];

int add(int a, int b, int mod = MOD){
    return (1ll * a + b + mod) % mod;
}

int mul(int a, int b, int mod = MOD){
    return (1ll * a * b) % mod;
}

void init(){
    pp[0] = 1;
    for(int i = 1; i < NMAX; i++) pp[i] = mul(pp[i-1], 2);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    init();
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) dp[arr[i]] += 1;
    
    for(int i = 0; i < LOG; i++) for(int msk = (1 << LOG)-1; msk >= 0; msk--){
        
        if((msk & (1 << i)) == 0){
            dp[msk] = add(dp[msk], dp[msk^(1 << i)]);
        }
    }
    
    lli ans = 0;
    for(int i = 0; i < (1 << LOG); i++){
        ans = add(ans, __builtin_popcount(i)%2==0 ? pp[dp[i]] : -pp[dp[i]]);
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
