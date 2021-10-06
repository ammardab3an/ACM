// Problem: T - Permutation
// Contest: AtCoder - Educational pre Contest
// URL: https://atcoder.jp/contests/pre/tasks/pre_t
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
    string cmp;
    cin >> cmp;
    
    vi pre(n+1);
    pre[1] = 1;
    
    for(int len = 2; len <= n; len++){
        
        vi new_pre(len+1);
        
        for(int b = 1; b <= len; b++){
            
            int ans = 0;
            
            if(cmp[len-2] == '<'){
                (ans += pre[b-1]) %= MOD;
            }
            else{
                (ans += pre[len-1]) %= MOD;
                (ans -= pre[b-1] - MOD) %= MOD;
            }
            
            (new_pre[b] = new_pre[b-1] + ans) %= MOD;
        }
        
        pre = new_pre;
    }
    
    cout << pre[n];
}
