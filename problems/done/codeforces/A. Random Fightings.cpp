// Problem: A. Random Fightings
// Contest: Codeforces
// URL: https://codeforces.com/problemset/gymProblem/100883/A
// Memory Limit: 64 MB
// Time Limit: 4000 ms
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

int n;
double arr[22][22];
double mem[1 << 20];
bool vis[1 << 20];

double go(int msk){
    
    if(vis[msk]) return mem[msk];
    else vis[msk] = true;
    
    double ret = 0;
    
    int cnt = __builtin_popcount(msk);
    if(cnt == n) return mem[msk] = 1.0;
    
    for(int i = 0; i < n; i++) if(msk & (1 << i))
    for(int j = 0; j < n; j++) if(!(msk & (1 << j))){
        
        ret += go(msk ^ (1 << j)) * arr[i][j] * 2.0 / (cnt * cnt + cnt);
    }
    
    return mem[msk] = ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> arr[i][j];
        
        vector<double> ans(n);
        
        memset(vis, 0, sizeof vis);
        memset(mem, 0, sizeof mem);
        
        for(int i = 0; i < n; i++){
            ans[i] = go(1 << i);    
        }
                
        cout << "Case " << tt++ << ": ";
        cout << fixed << setprecision(6);
        for(int i = 0; i < n; i++) cout << ans[i] << ' '; cout << endl;
    }	
}
