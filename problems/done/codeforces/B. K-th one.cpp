// Problem: B. K-th one
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
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

    int n, m;
    cin >> n >> m;
    
    vi tree(2*n);
    
    for(int i = 0; i < n; i++) cin >> tree[i + n];
    
    for(int i = n-1; i > 0; i--) tree[i] = tree[i*2] + tree[i*2+1];
    
    auto query = [&](int l, int r){
        
        l += n;
        r += n;
        
        int sm = 0;
            
        for(; l < r; l/=2, r/=2){
            
            if(l&1) sm += tree[l++];
            if(r&1) sm += tree[--r];
        }
        
        return sm;
    };
    
    while(m--){
        
        int k, x;
        cin >> k >> x;
        
        if(k == 1){
            int p = x + n;
            for(tree[p] = !tree[p]; p > 1; p /= 2) tree[p/2] = tree[p] + tree[p^1];
        }
        else{
            
            int l = 0;
            int r = n;
            
            int ans = -1;
            
            while(l <= r){
                
                int m = (l+r)/2;
                
                if(query(0, m) >= x+1){
                    ans = m-1;
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            
            cout << ans << endl;
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
