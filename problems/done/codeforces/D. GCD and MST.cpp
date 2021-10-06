// Problem: D. GCD and MST
// Contest: Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1513/D
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

int par[NMAX];

int get_par(int n){
    return par[n] == n ? n : par[n] = get_par(par[n]);
}

bool merge(int i, int j){
    
    int par_i = get_par(i);
    int par_j = get_par(j);
    
    if(par_i == par_j) return false;
    
    if(rand()&1) swap(par_i, par_j);
    
    par[par_i] = par_j;
    
    return true;
}

int32_t main(){
      
    fastIO;
        
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n, p;
        cin >> n >> p;
        
        vi vec(n);
        for(auto &i : vec) cin >> i;
        
        vi pos(n);
        for(int i = 0; i < n; i++) pos[i] = i;
        
        sort(pos.begin(), pos.end(), [&](int i, int j){return vec[i] < vec[j];});
        
        for(int i = 0; i < n; i++) par[i] = i;
        
        lli ans = 0;
        
        for(int i = 0; i < n; i++){
            
            int j = pos[i];
            int g = vec[j];
            
            if(g > p) break;
            
            for(int k = j-1; k >= 0; k--){
                
                if(__gcd(vec[k], g) == g && merge(j, k)){
                    ans += g;
                }
                else{
                    break;
                }
            }
            
            for(int k = j+1; k < n; k++){
                
                if(__gcd(vec[k], g) == g && merge(j, k)){
                    ans += g;
                }
                else{
                    break;
                }
            }
        }
        
        for(int i = 0; i+1 < n; i++){
            if(merge(i, i+1)){
                ans += p;
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
