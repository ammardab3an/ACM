// Problem: D. Maximum Sum of Products
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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

int n;
int arr[2][5050];
int mem[5050][5050];
int pre[5050];

int go(int i, int j){
    
    if(i == j) return arr[0][i] * arr[1][j];
    if(i > j) return 0;
    
    int &ret = mem[i][j];
    if(ret+1) return ret;
    
    return ret = go(i+1, j-1) + arr[0][i] * arr[1][j] + arr[0][j] * arr[1][i];;    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < n; j++) cin >> arr[i][j];
    
    pre[0] = arr[0][0] * arr[1][0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + arr[0][i] * arr[1][i];
    }
    
    int ans = pre[n-1];
    int ans_l = -1;
    int ans_r = -1;
    
    memset(mem, -1, sizeof mem);
    
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            
            int cans = pre[n-1] - pre[r];
            if(l) cans += pre[l-1];
            
            cans += go(l, r);
            
            if(cans > ans){
                ans = cans;
                ans_l = l;
                ans_r = r;
            }
        }
    }
    
    // cout << ans_l << ' ' << ans_r << endl;
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
