// Problem: B. Minimal Cost
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/contest/1491/problem/B
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        lli n, u, v;
        cin >> n >> u >> v;
        
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        lli ans = INFLL;
        
        for(int i = 0; i < n; i++){
            
            lli cc = INFLL;
            
            if(i+1 < n) if(abs(arr[i] - arr[i+1]) > 1) ans = 0;
            
            if(i+1 < n) if(abs(arr[i] - arr[i+1]) == 1) cc = min(cc, v);
            
            if(i)       if(arr[i-1] != arr[i]) cc = min(cc, u);
            if(i+1 < n) if(arr[i+1] != arr[i]) cc = min(cc, u);
            
            if(arr[i] + 2 <= 1e6) cc = min(cc, v*2);
            if(arr[i] - 2 >= 1)   cc = min(cc, v*2);
            
            if(i) if(arr[i]-1 > 0)    if(arr[i-1] != arr[i]-1) cc = min(cc, u+v);
            if(i) if(arr[i]+1 <= 1e6) if(arr[i-1] != arr[i]+1) cc = min(cc, u+v);
            
            if(i+1 < n) if(arr[i]-1 > 0)    if(arr[i+1] != arr[i]-1) cc = min(cc, u+v);
            if(i+1 < n) if(arr[i]+1 <= 1e6) if(arr[i+1] != arr[i]+1) cc = min(cc, u+v);
            
            ans = min(ans, cc);
        }
        
        cout << ans << endl;
    }	
}
