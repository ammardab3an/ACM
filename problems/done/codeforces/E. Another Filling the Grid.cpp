// Problem: E. Another Filling the Grid
// Contest: Codeforces - Codeforces Round #589 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1228/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define lli int64_t

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
    return (1ll * a + b + MOD) % MOD;
}

int mul(int a, int b){
    return(1ll * a * b) % MOD;
}

int pow_exp(int n, int p){
    if(!p) return 1;
    if(p&1) return mul(n, pow_exp(n, p-1));
    int tmp = pow_exp(n, p/2);
    return mul(tmp, tmp);
}

int n, k;
int pow_k[255];
int pow_k_1[255];
int cho[255][255];
int mem[255][255];

void init(){
    
    pow_k[0] = pow_k_1[0] = 1;
    for(int i = 1; i < 255; i++){
        pow_k[i] = mul(pow_k[i-1], k);
        pow_k_1[i] = mul(pow_k_1[i-1], k-1);
    }
    
    for(int i = 0; i < 255; i++){
        
        for(int j = 0; j <= i; j++){
            
            if(j == 0 || j == i)
                cho[i][j] = 1;
            else
                cho[i][j] = add(cho[i-1][j-1], cho[i-1][j]);
        }
    }
}

int choose(int n, int c){
    return n > c ? cho[n][c] : cho[c][n];
}

int go(int r, int c){
    
    int &ret = mem[r][c];
    if(ret+1) return ret;
    
    if(c == 0){
        return ret = pow_exp(add(pow_k[n], -pow_k_1[n]), r);
    }
    
    if(r == 1){
        return ret = pow_k[n-c];
    }
    
    int ans = 0;
    
    {
        int cans = mul(add(pow_k[n-c], -pow_k_1[n-c]), pow_k_1[c]);
        ans = add(ans, mul(cans, go(r-1, c)));
    }
    
    {
        int tans = 0;
        
        for(int c0 = 1; c0 <= c; c0++){
            int cans = mul(choose(c, c0), pow_k_1[c-c0]);
            tans = add(tans, mul(cans, go(r-1, c-c0)));
        }    
        
        ans = add(ans, mul(tans, pow_k[n-c]));
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> k;
    
    init();
    
    memset(mem, -1, sizeof mem);
    
    cout << go(n, n) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
