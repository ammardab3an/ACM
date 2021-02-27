// Problem: C. Yet Another Walking Robot
// Contest: Codeforces - Codeforces Round #617 (Div. 3)
// URL: https://codeforces.com/contest/1296/problem/C
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

int n;
char str[NMAX];
int pre[2][NMAX];

int val(char c, int t){
    
    if(t){
        if(c == 'R') return +1;
        if(c == 'L') return -1;
    }
    else{
        if(c == 'U') return +1;
        if(c == 'D') return -1;
    }
    
    return 0;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n;
        cin >> str;
        
        pre[0][0] = val(str[0], 0);
        pre[1][0] = val(str[0], 1);
        
        for(int i = 1; i < n; i++) pre[0][i] = pre[0][i-1] + val(str[i], 0);
        for(int i = 1; i < n; i++) pre[1][i] = pre[1][i-1] + val(str[i], 1);
         
        int ans = INF;
        pii ans_p;
        
        map<pii, int> mp;
        mp[{0, 0}] = -1;
        
        for(int i = 0; i < n; i++){
            
            pii p = {pre[0][i], pre[1][i]};
             
            if(mp.find(p) == mp.end()){
                mp[p] = i;
            }
            else{
                
                int lst = mp[p];
                int nans = i - lst + 1;
                
                if(nans < ans){
                    ans = nans;
                    ans_p = {lst+2, i+1};
                }
                
                mp[p] = i;
            }
        }
        
        if(ans == INF){
            cout << -1 << endl;
        }
        else{
            cout << ans_p.first << ' ' << ans_p.second << endl;
        }
    }	
}
