// Problem: B. Fence
// Contest: Codeforces - Codeforces Round #211 (Div. 2)
// URL: https://codeforces.com/contest/363/problem/B?outsideGroup=true
// Memory Limit: 256 MB
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

    int n, k;
    cin >> n >> k;
    
    vi vec(n);
    for(int &i : vec) cin >> i;
    
    int ans_sm = INF;
    int ans_pos = -1;
    
    int sm = 0;
    int mx = 0;
    
    for(int i = 0; i < k-1; i++) sm += vec[i];
    
    for(int i = k-1; i < n; i++){

        sm += vec[i];
        if(i-k+1) mx += vec[i-k];

        if(ans_sm > sm-mx){
            ans_sm = sm-mx;
            ans_pos = i-k+1;
        }
    }	
    
    cout << ans_pos + 1 << endl;
}