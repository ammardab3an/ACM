// Problem: D. 13th Labour of Heracles
// Contest: Codeforces - Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
int arr[NMAX];
int deg[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        memset(deg, 0, n * sizeof(deg[0]));

        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v; u--, v--;
            deg[u]++, deg[v]++;
        }

        lli ans = 0;

        vi vec;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < deg[i]; j++)
                vec.push_back(arr[i]);
            ans += arr[i];
        }

        sort(vec.rbegin(), vec.rend());

        for(auto i : vec){
            cout << ans << ' ';
            ans += i;
        }
        cout << ans << endl;
    }	
}