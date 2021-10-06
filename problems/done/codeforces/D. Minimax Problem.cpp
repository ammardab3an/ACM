// Problem: D. Minimax Problem
// Contest: Codeforces - Educational Codeforces Round 80 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1288/problem/D?outsideGroup=true
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
int arr[NMAX][8];

pii can(int ans){
    
    vi vec(1 << m, -1);
    
    for(int i = 0; i < n; i++){
        
        int cmsk = 0;
        for(int j = 0; j < m; j++) if(arr[i][j] >= ans) cmsk |= 1 << j;
        
        vec[cmsk] = i;
    }
    
    for(int i = 0; i < (1 << m); i++)
    for(int j = i; j < (1 << m); j++) if((i|j) == ((1 << m)-1)){
        if(vec[i] != -1 && vec[j] != -1) return {vec[i], vec[j]};
    }
    
    return {-1, -1};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> arr[i][j];
    
    int l = 0;
    int r = 1e9 + 10;
    
    int ans = -1;
    
    while(l <= r){
        
        int m = (l+r)/2;
        if(can(m).first != -1){
            ans = m;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    
    pii tmp = can(ans);
    cout << tmp.first+1 << ' ' << tmp.second+1;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
