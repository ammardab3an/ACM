// Problem: D. Fafa and Ancient Alphabet
// Contest: Codeforces - Codeforces Round #465 (Div. 2)
// URL: https://codeforces.com/problemset/problem/935/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int add(int a, int b){
    return (1ll * a + b + MOD) % MOD;
}
int mul(int a, int b){
    return (1ll * a * b) % MOD;
}
int pow_exp(int n, int p){
    if(!p) return 1; 
    if(p&1) return mul(n, pow_exp(n, p-1));
    int tmp = pow_exp(n, p/2);
    return mul(tmp, tmp);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, m;
    cin >> n >> m;
    
    vi vec_a(n), vec_b(n);
    for(int &i : vec_a) cin >> i;
    for(int &i : vec_b) cin >> i;
    
    int ans = 0;
    
    int pst = 1;
    int pow_m = pow_exp(m, MOD-2);
    int pow_m_m = mul(pow_m, pow_m);
    
    int pre_calc = 0;
    for(int i = 1; i < m; i++){
        pre_calc = add(pre_calc, mul(i, pow_m_m));
    }
    
    for(int i = 0; i < n; i++){
        
        if(vec_a[i] && vec_b[i]){   
            if(vec_a[i] > vec_b[i]){
                ans = add(ans, pst);
            }
            if(vec_a[i] != vec_b[i]){
                break;
            }
        }
        
        else if(!vec_a[i] && !vec_b[i]){
            
            // 2 : (1/m) * (1/m)
            // 3 : (1/m) * (2/m)
            // 4 : (1/m) * (3/m)
            // ...
            // m : (1/m) * ((m-1)/m)
            
            // 1 - 1 : (1/m) * (1/m)
            // 2 - 2 : (1/m) * (1/m)
            // ...
            // m - m : (1/m) * (1/m);
            
            // m * (1/m)^2
            
            ans = add(ans, mul(pst, pre_calc));
            pst = mul(pst, mul(mul(pow_m, pow_m), m));
        }
        
        else if(!vec_a[i]){
            ans = add(ans, mul(pst, mul(m-vec_b[i], pow_m)));
            pst = mul(pst, pow_m);
        }
        
        else if(!vec_b[i]){
            ans = add(ans, mul(pst, mul(vec_a[i]-1, pow_m)));
            pst = mul(pst, pow_m);
        }
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
