// Problem: C. Classy Numbers
// Contest: Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1036/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int n;
string num;
int mem[20][20][2];

int go(int i, int cnt, bool b_l){
    
    if(i == n) return 1;
    if(cnt == 3) return go(i+1, cnt, b_l);
    
    int &ret = mem[i][cnt][b_l];
    if(ret+1) return ret;
    
    int lo = 0;
    int hi = b_l ? 9 : num[i]-'0';
    
    int ans = 0;
    
    for(int d = lo; d <= hi; d++){
        
        ans += go(i+1, cnt + bool(d), b_l || (d < num[i]-'0'));
    }    
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int t; cin >> t; while(t--){
        
        int l, r;
        cin >> l >> r;
        
        int ans = 0;
        
        num = to_string(r);
        n = num.size();
        memset(mem, -1, sizeof mem);
        ans += go(0, 0, 0);
        
        num = to_string(l-1);
        n = num.size();
        memset(mem, -1, sizeof mem);
        ans -= go(0, 0, 0);
        
        cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
