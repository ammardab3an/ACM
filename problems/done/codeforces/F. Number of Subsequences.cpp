// Problem: F. Number of Subsequences
// Contest: Codeforces - Codeforces Round #674 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1426/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int add(int a, int b){
    return (1ll * a + b + MOD + MOD) % MOD;
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

int fac[NMAX];

int factorial(int n){
    if(!n) return 1;
    if(fac[n]) return fac[n];
    return fac[n] = mul(n, factorial(n-1));    
}

int choose(int n, int c){
    return mul(factorial(n), mul(pow_exp(factorial(c), MOD-2), pow_exp(factorial(n-c), MOD-2)));    
}

int n;
char str[NMAX];
int pre_a[NMAX], suf_c[NMAX], pre_q[NMAX], suf_q[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> str;
    
    pre_a[0] = str[0] == 'a';
    for(int i = 1; i < n; i++){
        pre_a[i] = pre_a[i-1] + (str[i] == 'a');
    }
    
    suf_c[n-1] = str[n-1] == 'c';
    for(int i = n-2; i >= 0; i--){
        suf_c[i] = suf_c[i+1] + (str[i] == 'c');
    }
    
    pre_q[0] = str[0] == '?';
    for(int i = 1; i < n; i++){
        pre_q[i] = pre_q[i-1] + (str[i] == '?');
    }
    
    suf_q[n-1] = str[n-1] == '?';
    for(int i = n-2; i >= 0; i--){
        suf_q[i] = suf_q[i+1] + (str[i] == '?');
    }
    
    lli ans = 0;
    
    {
        for(int i = 1; i+1 < n; i++){
            if(str[i] == 'b'){
                int pre = pre_a[i-1];
                int suf = suf_c[i+1];
                ans = add(ans, mul(pre, suf));
            }
        }
        ans = mul(ans, pow_exp(3, pre_q[n-1]));
    }
    
    {
        lli tmp = 0;
        for(int i = 1; i+1 < n; i++){
            if(str[i] == '?'){
                int pre = pre_a[i-1];
                int suf = suf_c[i+1];
                tmp = add(tmp, mul(pre, suf));
            }
        }
        if(pre_q[n-1]) tmp = mul(tmp, pow_exp(3, pre_q[n-1]-1));
        ans = add(ans, tmp);
    }
    
    for(int i = 1; i+1 < n; i++){
        
        if(str[i] == '?' || str[i] == 'b'){
            
            int pre = pre_q[i-1];
            int suf = suf_q[i+1];
            
            int tmp_0 = 0;
            int tmp_1 = 0;
            
            if(pre_q[i-1]) tmp_0 = add(tmp_0, mul(pre_q[i-1], pow_exp(3, pre_q[i-1]-1)));
            if(suf_q[i+1]) tmp_1 = add(tmp_1, mul(suf_q[i+1], pow_exp(3, suf_q[i+1]-1)));
            
            ans = add(ans, mul(tmp_0, tmp_1));
            
            if(suf_q[i+1]) ans = add(ans, mul(mul(pre_a[i-1], suf_q[i+1]), pow_exp(3, pre_q[n-1] -1 -(str[i] == '?'))));
            if(pre_q[i-1]) ans = add(ans, mul(mul(pre_q[i-1], suf_c[i+1]), pow_exp(3, pre_q[n-1] -1 -(str[i] == '?'))));
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
