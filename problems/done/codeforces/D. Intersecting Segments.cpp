// Problem: D. Intersecting Segments
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D
// Memory Limit: 1024 MB
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    vi vec(2*n);
    for(auto &i : vec) cin >> i;
    
    int sz = 2 * n;
    vi left(n, -1), tree(2*sz), ans(n);
    
    for(int i = 0; i < 2*n; i++){
        
        int v_i = vec[i] -1;
        
        if(left[v_i] == -1){
            left[v_i] = i;
            int p = i + sz;
            for(tree[p] = +1; p > 1; p/=2) tree[p/2] = tree[p] + tree[p^1];
        }
        else{
            
            int l = left[v_i]+1 + sz;
            int r = i + sz;
            
            for(; l < r; l/=2, r/=2){
                if(l&1) ans[v_i] += tree[l++];
                if(r&1) ans[v_i] += tree[--r];
            }
            
            int p = i + sz;
            for(tree[p] = +1; p > 1; p/=2) tree[p/2] = tree[p] + tree[p^1];
            
            p = left[v_i] + sz;
            for(tree[p] = -1; p > 1; p/=2) tree[p/2] = tree[p] + tree[p^1];
        }
    }
    
    for(auto i : ans) cout << i << ' ' ; cout << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
