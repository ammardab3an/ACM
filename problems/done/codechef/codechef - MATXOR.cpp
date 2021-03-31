// Problem: Matrix XOR
// Contest: CodeChef - March Cook-Off 2021 Division 2
// URL: https://www.codechef.com/COOK127B/problems/MATXOR
// Memory Limit: 256 MB
// Time Limit: 500 ms
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

    int t; cin >> t; while(t--){

        int n, m, k;
        cin >> n >> m >> k;
        
        if(n > m) swap(n, m);

        int mn = 2;
        int mx = n+m;
        
        int ans = 0;
        
        if(n&1)
        for(int i = n+1; i <= m+1; i++){
            ans ^= i + k;
        }
        
        for(int i = 1; i < n; i++){
            if(i&1) ans ^= i+1 + k, ans ^= mx-i+1 + k;
        }
        
        cout << ans << endl;
    }	
}

/*
2 3 4 5 6 7 8 9 10 11 
3 4 5 6 7 8 9 10 11 12 
4 5 6 7 8 9 10 11 12 13 
5 6 7 8 9 10 11 12 13 14 
*/