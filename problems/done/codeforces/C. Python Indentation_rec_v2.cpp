// Problem: C. Python Indentation
// Contest: Codeforces - Codeforces Round #455 (Div. 2)
// URL: https://codeforces.com/contest/909/problem/C?outsideGroup=true
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

const int NMAX = 5e3 + 10;

int n;
char str[NMAX];
int mem[NMAX][NMAX];

int add(int a, int b){
    return (lli(a) + b + MOD + MOD) % MOD;
}
int go(int pos, int lvl){
    
    if(lvl < 0) return 0;
    
    if(pos == n) return 1;
    
    int &ret = mem[pos][lvl];
    if(ret+1) return ret;
    
    int ans = 0;
    
    if(str[pos-1] == 'f'){
        ans = go(pos+1, lvl+1);
    }
    else{
        ans = add(go(pos, lvl-1), go(pos+1, lvl));
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> str[i];
    
    n++;
    str[0] = 's';
    
    memset(mem, -1, sizeof mem);
    
    cout << go(1, 0) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
