// Problem: F2. Pictures with Kittens (hard version)
// Contest: Codeforces - Codeforces Round #521 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1077/F2
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n, k, x;
    cin >> n >> k >> x;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    if(n/k > x){
        cout << -1 << endl;
        return 0;
    }
    
    int base = n+1;
    vector<vi> tr(x+2, vi(2*base, -INFLL));
    
    auto query = [&](int x, int l, int r){
        
        l += base;
        r += base;
        
        int ans = -INFLL;
        
        for(; l < r; l/=2, r/=2){
            if(l&1) ans = max(ans, tr[x][l++]);
            if(r&1) ans = max(ans, tr[x][--r]);
        }
        
        return ans;
    };
    
    auto update = [&](int x, int p, int val){
        
        for(tr[x][p += base] = val; p > 1; p /= 2)
            tr[x][p/2] = max(tr[x][p], tr[x][p^1]);
    };
    
    for(int i = 0; i < k; i++) update(1, i, vec[i]);
    
    for(int i = 0; i < n; i++){
        
        for(int cx = 2; cx <= x; cx++){
            
            int que = query(cx-1, max(int(0), i-k), i);
            int ans = que + vec[i];
            
            update(cx, i, ans);
        }
        
    }
    
    int ans = query(x, max(int(0), n-k), n);
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
