// Problem: C. Famil Door and Brackets
// Contest: Codeforces - Codeforces Round #343 (Div. 2)
// URL: https://codeforces.com/problemset/problem/629/C
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
int s_sm, s_mn;
char str[NMAX];
int mem[2][2020][2020];

int add(int a, int b){
    return (a + b) % MOD;
}

int go(int p, int i, int sm){
    
    if(i > n) return 0;
    if(sm < 0) return 0;
    if(i == n && p) return !sm;
    
    int &ret = mem[p][i][sm];
    if(ret+1) return ret;
    
    int stPath = go(p, i+1, sm+1);
    int ndPath = go(p, i+1, sm-1);
    int ans = add(stPath, ndPath);
    
    if(!p){
        
        int csm = s_sm + sm;
        
        if((s_mn + sm >= 0) && (csm <= n-i)) 
        
            ans = add(ans, go(1, i, csm));
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m >> str;
    
    n = n-m;
    
    s_sm = 0;
    s_mn = INF;
    
    for(int i = 0; i < m; i++){
        
        s_sm += str[i] == '(';
        s_sm -= str[i] == ')';
        
        s_mn = min(s_mn, s_sm);
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, 0, 0) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
