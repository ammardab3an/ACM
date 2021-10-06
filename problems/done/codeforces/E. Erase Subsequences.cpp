// Problem: E. Erase Subsequences
// Contest: Codeforces - Educational Codeforces Round 82 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1303/problem/E?outsideGroup=true
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

int nxt[405][30];

void init(string str0){
    memset(nxt, INF, sizeof nxt);
    for(int i = str0.size()-1; i >= 0; i--){
        for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][str0[i] - 'a'] = i;
    }
}

bool can(string str0, string str1){
    
    int sz0 = str0.size();
    int sz1 = str1.size();
    
    vector<vi> dp(sz0+1, vi(sz1+1, INF));
    
    dp[0][0] = 0;
    
    for(int i = 0; i <= sz0; i++)
    for(int j = 0; j <= sz1; j++){
        
        if(dp[i][j] == INF) continue;
        
        int len = dp[i][j];
        
        if(i < sz0) if(nxt[len][str0[i] - 'a'] < INF) 
            dp[i+1][j] = min(dp[i+1][j], nxt[len][str0[i] - 'a'] + 1);
                
        if(j < sz1) if(nxt[len][str1[j] - 'a'] < INF)
            dp[i][j+1] = min(dp[i][j+1], nxt[len][str1[j] - 'a'] + 1);
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
        
        string str0, str1;
        cin >> str0 >> str1;
        
        init(str0);
        
        bool ans = false;
        
        for(int b = 0; b <= str1.size(); b++){
            
            if(can(str1.substr(0, b), str1.substr(b))){
            
                ans = true;
                break;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }	
}
