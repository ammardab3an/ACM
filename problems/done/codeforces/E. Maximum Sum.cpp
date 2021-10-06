// Problem: E. Maximum Sum
// Contest: Codeforces - ACM International Collegiate Programming Contest, JUST Collegiate Programming Contest (2018)
// URL: https://codeforces.com/gym/101853/problem/E?outsideGroup=true
// Memory Limit: 512 MB
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

int n;
int grid[20][20];
int mem[20][1 << 16];

void bin(int msk){
    for(int i = n-1; i >= 0; i--) cout << bool(msk & (1 << i));
    cout << endl;
}

int go(int i, int msk){
    
    if(i == n) return 0;
    
    int &ret = mem[i][msk];
    if(ret + 1) return ret;
    
    int ans = go(i+1, 0);
    
    int nmsk = msk | (msk << 1) | (msk >> 1);
    nmsk = ((1 << n) -1) & (~nmsk);
    
    for(int tmsk = nmsk; tmsk; tmsk = (tmsk-1) & nmsk){
        
        int sm = 0;
        bool bad = false;
        for(int k = 0; k < n; k++) {
            
            if(k+1 < n && (tmsk & (1 << k)) && (tmsk & (1 << (k+1)))){
                bad = true;
                break;
            }
            
            if(tmsk & (1 << k)) sm += grid[i][k];
        }
        
        if(bad) continue;
        
        ans = max(ans, go(i+1, tmsk) + sm);
    }
    
    return ret = ans;
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> grid[i][j];
        
        memset(mem, -1, sizeof mem);
        
        cout << go(0, 0) << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
