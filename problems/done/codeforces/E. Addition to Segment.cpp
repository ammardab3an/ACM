// Problem: E. Addition to Segment
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/E
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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


    int n, m;
    cin >> n >> m;
    
    vi tree(2 * n);
    
    auto update = [&](int l, int r, int v){
        
        l += n;
        r += n;
        
        for(; l < r; l/=2, r/=2){
            if(l&1) tree[l++] += v;
            if(r&1) tree[--r] += v;
        }
    };
    
    auto query = [&](int p){
        
        int res = 0;
        for(p += n; p > 0; p/=2) res += tree[p];
        return res;
    };
    
    while(m--){
        
        int k;
        cin >> k;
        
        if(k == 1){
            int l, r, v;
            cin >> l >> r >> v;
            update(l, r, v);
        }
        else{
            int p;
            cin >> p;
            cout << query(p) << endl;
        }
    }
    
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
