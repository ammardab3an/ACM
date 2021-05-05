// Problem: B. Substring Removal Game
// Contest: Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1398/problem/B
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

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

        string str;
        cin >> str;
        
        int n = str.size();
        
        vi vis(n);
        int ans = 0;
        
        bool b = true;
        
        while(true){
            
            int mx_cnt = -1;
            int mx_pos = -1;
            
            for(int i = 0; i < n; i++) if(!vis[i] && str[i] == '1'){
                
                int cur_cnt = 1;
                int cur_pos = i+1;
                
                while(cur_pos < n && (vis[cur_pos] || (str[cur_pos] == '1'))){
                    cur_cnt += !vis[cur_pos];
                    cur_pos++;
                }
                
                if(cur_cnt > mx_cnt){
                    mx_cnt = cur_cnt;
                    mx_pos = i;
                }
                
                i = cur_pos-1;
            }
            
            if(mx_cnt == -1) break;
            
            if(b) ans += mx_cnt;
            b = !b;
            
            int pos = mx_pos;
            
            while(pos < n && (vis[pos] || str[pos] == '1')){
                vis[pos] = true;
                pos++;
            }
        }
        
        cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
