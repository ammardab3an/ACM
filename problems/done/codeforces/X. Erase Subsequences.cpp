// Problem: X. Erase Subsequences
// Contest: Codeforces - DP
// URL: https://codeforces.com/gym/272904/problem/X
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

const int NMAX = 405;

int n, m, k;
string a, b;
int nxt[NMAX][30];
int mem[NMAX][NMAX];

void init(){
    
    memset(nxt, INF, sizeof nxt);
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 30; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][a[i]-'a'] = i;
    }
}

bool can(string b0, string b1){
    
    int sz0 = b0.size();
    int sz1 = b1.size();
    
    vector<vi> dp(sz0+1, vi(sz1+1, INF));
    
    dp[0][0] = 0;
    
    for(int i = 0; i <= sz0; i++)
    for(int j = 0; j <= sz1; j++){
        
        if(dp[i][j] == INF) continue;
        
        int len = dp[i][j];
        
        if(i < sz0) if(nxt[len][b0[i]-'a'] < INF)
            dp[i+1][j] = min(dp[i+1][j], nxt[len][b0[i]-'a']+1);
            
        if(j < sz1) if(nxt[len][b1[j]-'a'] < INF)
            dp[i][j+1] = min(dp[i][j+1], nxt[len][b1[j]-'a']+1);
            
    }
    
    return dp[sz0][sz1] < INF;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> a >> b;
        n = a.size(), m = b.size();
        
        init();
        
        bool ans = false;
        
        for(int i = 0; i < m; i++){
            
            if(can(b.substr(0, i), b.substr(i))){
                ans = true;
                break;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
