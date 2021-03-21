// Problem: C. Minimum Grid Path
// Contest: Codeforces - Educational Codeforces Round 106 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1499/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

//typedef unsigned int        uint;
//typedef long long int       lli;
//typedef unsigned long long  ull;
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
int arr[NMAX];
int pre[NMAX];
int mn[NMAX];

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        pre[0] = arr[0];
        pre[1] = arr[1];
        for(int i = 2; i < n; i++){
            pre[i] = pre[i-2] + arr[i];
        }

        mn[0] = arr[0];
        mn[1] = arr[1];
        for(int i = 2; i < n; i++){  
            mn[i] = min(mn[i-2], arr[i]);
        }
        
        int ans = n * (arr[0] + arr[1]);
        
        for(int i = 1; i < n; i++){
            
            int odd = i%2==1 ? i : i-1;
            int eve = i%2==0 ? i : i-1;
            
            int ans0 = pre[odd] + mn[odd] * (n - odd/2 -1);
            int ans1 = pre[eve] + mn[eve] * (n - eve/2 -1);
                
            ans = min(ans, ans0 + ans1);
        }
        
        cout << ans << endl;
    }
}
