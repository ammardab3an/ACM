// Problem: C. Binary String Reconstruction
// Contest: Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1400/problem/C
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

int n, x;
char str[NMAX];
char ans[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> str >> x;
        n = strlen(str);
        
        bool bad = false;
        
        for(int i = 0; i < n; i++) ans[i] = '1';
        
        for(int i = 0; i < n; i++){
            
            if(str[i] == '0'){
                
                int l = i-x;
                int r = i+x;
                
                if(l >= 0) ans[l] = '0';
                if(r <  n) ans[r] = '0';
            }    
        }   
        
        for(int i = 0; i < n; i++){
            
            bool one = false;
            one |= (i-x >= 0) && (ans[i-x] == '1');
            one |= (i+x <  n) && (ans[i+x] == '1');
            
            if(str[i] != '0' + one){
                bad = true;
                break;
            }
        }
        
        if(bad){
            cout << -1 << endl;
        }
        else{
            ans[n] = 0;
            cout << ans << endl;
        }
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
