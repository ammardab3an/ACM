// Problem: B - Special Subsets
// Contest: AtCoder - AtCoder Regular Contest 114
// URL: https://atcoder.jp/contests/arc114/tasks/arc114_b
// Memory Limit: 1024 MB
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
const int MOD = 998244353;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

inline int add(int a, int b){
    return ((lli) a + b + MOD + MOD) % MOD;
}

inline int mul(int a, int b){
    return ((lli) a * b) % MOD;
}

int fast_pow(int n, int p){
    if(!p) return 1;
    if(p&1) return mul(n, fast_pow(n, p-1));
    int tmp = fast_pow(n, p/2);
    return mul(tmp, tmp);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    for(auto &i : vec) i--;
    
    vi vis(n);
    int vid = 1;
    
    int cnt = 0;
    
    for(int i = 0; i < n; i++) if(!vis[i]){
        
        cnt++;
        vid++;
        
        int t = i;
        while(true){
            
            if(vis[t] == vid) break;
            
            if(vis[t]){
                cnt--;
                break;
            }
            
            vis[t] = vid;
            t = vec[t];
        }
    }
    
    cout << add(fast_pow(2, cnt), -1) << endl;
}
