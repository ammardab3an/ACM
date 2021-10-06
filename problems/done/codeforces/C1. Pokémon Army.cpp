// Problem: C1. Pokémon Army (easy version)
// Contest: Codeforces - Codeforces Round #672 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1420/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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

const int NMAX = 3e5 + 10;

int n, k;
int arr[NMAX];
int mem[NMAX][2];

int go(int pos, int sgn){
    
    if(pos == n) return 0;
    
    int &ret = mem[pos][sgn];
    if(ret + 1) return ret;
    
    int stPath = go(pos+1, sgn);
    int ndPath = go(pos+1, !sgn) + ((sgn == 0) - (sgn == 1)) * arr[pos];
    
    return ret = max(stPath, ndPath);    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        memset(mem, -1, sizeof mem);
        
        cout << go(0, 0) << endl;
    }	
}
