// Problem: B. Berland Crossword
// Contest: Codeforces - Educational Codeforces Round 105 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1494/problem/B
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n;
        cin >> n;

        int tp, ri, bo, le;
        cin >> tp >> ri >> bo >> le;

        bool ans = false;

        for(int i = 0; i < 4 && !ans; i++)
        for(int j = 0; j < 4 && !ans; j++)
        for(int k = 0; k < 4 && !ans; k++)
        for(int l = 0; l < 4 && !ans; l++){

            int ctp = tp - bool(i&1) - bool(i&2) ;
            int cri = ri - bool(j&1) - bool(j&2) ; 
            int cbo = bo - bool(k&1) - bool(k&2) ; 
            int cle = le - bool(l&1) - bool(l&2) ; 

            if(ctp > (n-2) || cri > (n-2) || cbo > (n-2) || cle > (n-2)) continue;
            if(ctp < 0 || cri < 0 || cbo < 0 || cle < 0) continue;

            if((i&2) || (j&1)) ctp++, cri++;
            if((j&2) || (k&1)) cri++, cbo++;
            if((k&2) || (l&1)) cbo++, cle++;
            if((l&2) || (i&1)) cle++, ctp++;

            if(ctp == tp && cri == ri && cbo == bo && cle == le){
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }	
}