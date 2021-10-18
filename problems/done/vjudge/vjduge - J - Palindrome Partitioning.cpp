// Problem: J - Palindrome Partitioning
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/J
// Memory Limit: 65 MB
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
char str[1010];
bool good[1010][1010];
int mem[1010];

int go(int i){
    
    if(i == n) return 0;
    
    int &ret = mem[i];
    if(ret+1) return ret;
    
    int ans = INF;
    for(int j = 0; j < n; j++){
        if(good[i][j]) ans = min(ans, 1 + go(j+1));
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){

        cin >> str;
        n = strlen(str);
        
        memset(good, 0, sizeof good);
        memset(mem, -1, sizeof mem);
        
        for(int i = 0; i < n; i++){
            
            int l = i;
            int r = i;
            
            while(l >= 0 && r < n && (str[l] == str[r])){
                good[l][r] = true;
                l--, r++;
            }
            
            l = i;
            r = i+1;
            
            while(l >= 0 && r < n && (str[l] == str[r])){
                good[l][r] = true;
                l--, r++;
            }
        }
        
        cout << "Case " << tt++ << ": ";
        cout << go(0) << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    