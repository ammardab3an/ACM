// Problem: C. Triangles
// Contest: Codeforces - Codeforces Round #688 (Div. 2)
// URL: https://codeforces.com/contest/1453/problem/C?outsideGroup=true
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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

// #define endl '\n'
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
char grid[2020][2020];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++) cin >> grid[i];
        
        vi ans(10, 0), mni(10, INF), mnj(10, INF), mxi(10, -INF), mxj(10, -INF);
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            
            int dig = grid[i][j] - '0';
            mni[dig] = min(mni[dig], i);
            mnj[dig] = min(mnj[dig], j);    
            mxi[dig] = max(mxi[dig], i);
            mxj[dig] = max(mxj[dig], j);
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            
            int dig = grid[i][j] - '0';
            
            ans[dig] = max(ans[dig], max(mxi[dig] - i, i - mni[dig]) * max(n-1-j, j));
            ans[dig] = max(ans[dig], max(mxj[dig] - j, j - mnj[dig]) * max(n-1-i, i));
            
        }

        for(int i = 0; i < 10; i++) cout << ans[i] << ' '; cout << endl;
    }	
}
