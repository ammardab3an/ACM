// Problem: D. Bad Luck Island
// Contest: Codeforces - Codeforces Round #301 (Div. 2)
// URL: https://codeforces.com/problemset/problem/540/D
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

int r, p, s;
bool vis[111][111][111];
double mem[111][111][111];

double go(int cr, int cp, int cs){
    
    if((cr == r) && (cp == p) && (cs == s)) return 1.0;
    
    if(vis[cr][cp][cs]) return mem[cr][cp][cs];
    vis[cr][cp][cs] = true;
    
    double ans = 0;   
    
    if(cr < r && cp > 0){
        int tot = cr + cp + cs + 1;
        double pro = double((cr+1) * cp) / (cp*cs + cs*(cr+1) + (cr+1)*cp);
        ans += go(cr+1, cp, cs) * pro;        
    }
    
    if(cp < p && cs > 0){
        int tot = cr + cp + cs + 1;
        double pro = double((cp+1) * cs) / ((cp+1)*cs + cs*cr + cr*(cp+1));
        ans += go(cr, cp+1, cs) * pro;
    }
    
    if(cs < s && cr > 0){
        int tot = cr + cp + cs + 1;
        double pro = double((cs+1) * cr) / (cp*(cs+1) + (cs+1)*cr + cr*cp);
        ans += go(cr, cp, cs+1) * pro;
    }
    
    return mem[cr][cp][cs] = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> r >> s >> p;
    
    {
        double ans = 0;
        for(int i = 1; i <= r; i++) ans += go(i, 0, 0);
        cout << fixed << setprecision(12) << ans << ' ';
    }
    {
        double ans = 0;
        for(int i = 1; i <= s; i++) ans += go(0, 0, i);
        cout << fixed << setprecision(12) << ans << ' ';
    }
    {
        double ans = 0;
        for(int i = 1; i <= p; i++) ans += go(0, i, 0);
        cout << fixed << setprecision(12) << ans << ' ';
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
