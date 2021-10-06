// Problem: 750 - 8 Queens Chess Problem
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=691
// Memory Limit: 32 MB
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

int tt = 1;
int r0, c0;
int row[8];

bool good(int r, int c){
    
    for(int i = 0; i < c; i++){
        
        int cp = i;
        int rp = row[i];
        
        if(rp == r || cp == c || (abs(rp-r) == abs(cp-c))) return false;
    }
    
    return true;
}

int grid[8][8];

void go(int c){
    
    if(c == c0){
        if(good(r0, c0)) {
            row[c0] = r0;
            go(c+1);
        }
        return;
    }
    
    if(c == 8){
        cout << setw(2) << tt++ << "     ";
        for(int i = 0; i < 8; i++)
            cout << " " << row[i]+1;
        cout << endl;
        return;
    }
    
    for(int r = 0; r < 8; r++) if(good(r, c)){
        row[c] = r;
        go(c+1);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    bool first_test_case = 1;
    
    int t; cin >> t; while(t--){
    
        if(!first_test_case) cout << endl;
        first_test_case = false;
        
        cout << ("SOLN       COLUMN") << endl;
        cout << (" #      1 2 3 4 5 6 7 8") << endl << endl;
        
        cin >> r0 >> c0; r0--, c0--;

        tt = 1;
        go(0);
    }
}
