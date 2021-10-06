// Problem: L Shaped Plots
// Contest: Google Coding Competitions - Round A 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068c509
// Memory Limit: 1024 MB
// Time Limit: 60000 ms
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

// #define endl '\n'
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

int n, m;
int grid[2000][2000];
int pre[4][2000][2000];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){
            
        cin >> n >> m;
        for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin >> grid[i][j];
        
        int ans = 0;
        
        memset(pre, 0, sizeof pre);
        
        for(int i = n-1; i >= 0; i--)    
        for(int j = 0; j < m; j++){
            pre[0][i][j] = grid[i][j];
            if(grid[i][j]) pre[0][i][j] += pre[0][i+1][j];
        }
        
        for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++){
            pre[1][i][j] = grid[i][j];
            if(j && grid[i][j]) pre[1][i][j] += pre[1][i][j-1];
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            pre[2][i][j] = grid[i][j];
            if(i && grid[i][j]) pre[2][i][j] += pre[2][i-1][j];
        }
        
        for(int j = m-1; j >= 0; j--)
        for(int i = 0; i < n; i++){
            pre[3][i][j] =  grid[i][j];
            if(grid[i][j]) pre[3][i][j] += pre[3][i][j+1];
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if(grid[i][j]){
            
            for(int k = 0; k < 4; k++){
                
                int cnt0 = pre[k][i][j];
                int cnt1 = pre[(k+1)%4][i][j];
                
                for(int i = 2; (i <= cnt0) && (2*i <= cnt1); i++){
                    ans++;
                }
                
                swap(cnt0, cnt1);
                
                for(int i = 2; (i <= cnt0) && (2*i <= cnt1); i++){
                    ans++;
                }
            }  
        }
        
        cout << "Case #" << tt++ << ": ";
        cout << ans << endl;
    }	
}
