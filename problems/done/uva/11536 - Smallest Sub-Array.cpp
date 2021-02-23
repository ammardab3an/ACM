// Problem: 11536 - Smallest Sub-Array
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2531
// Memory Limit: 32 MB
// Time Limit: 8000 ms
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

const int NMAX = 1e6 + 10;

int n, m, k;
int arr[NMAX] = {1, 2, 3};
int fstMod[3030];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){
        
        cin >> n >> m >> k;
    
        for(int i = 0; i < 3030; i++) fstMod[i] = i%m;
    
        for(int i = 3; i < n; i++) 
            arr[i] = fstMod[arr[i-1] + arr[i-2] + arr[i-3]] + 1;
        
        int r = 0;
        int tot = 0;
        int ans = INF;
        vi vis(k+1, 0);
        
        for(int i = 0; i < n; i++){
            
            while(r < n && tot < k){
                if(arr[r] <= k && !vis[arr[r]])
                    tot++;
                if(arr[r] <= k)
                    vis[arr[r]]++;
                r++;
            }
            
            if(tot == k){
                ans = min(ans, r-i);
            }
            else if(n <= r) {
                break;
            }
            
            if(arr[i] <= k && vis[arr[i]] == 1)
                tot--;
            if(arr[i] <= k)
                vis[arr[i]]--;
        }
        
        cout << "Case " << tt++ << ": ";
        if(ans == INF) cout << "sequence nai" << endl;
        else cout << ans << endl;
    }	
}