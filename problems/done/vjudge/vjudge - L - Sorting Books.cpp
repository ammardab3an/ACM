// Problem: L - Sorting Books
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/L
// Memory Limit: 262 MB
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
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;

int n, fo;
int arr[NMAX];
int cnt[NMAX];
int lst[NMAX];
int mem[NMAX];

int go(int i){
    
    if(i == n) return 0;
    
    auto &ret = mem[i];
    if(ret + 1) return ret;
    
    int stPath = go(i+1);
    
    int ndPath = 0;
    if(cnt[i] == 1){
        ndPath = go(lst[arr[i]]+1) + cnt[lst[arr[i]]];
    }
    
    int rdPath = cnt[lst[arr[i]]] - cnt[i] + 1;
    
    return ret = max({stPath, ndPath, rdPath});    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    memset(lst, -1, sizeof lst);
    
    for(int i = 0; i < n; i++){
        cnt[i] = 1;
        if(lst[arr[i]] != -1) cnt[i] += cnt[lst[arr[i]]];
        lst[arr[i]] = i;    
    }
    
    memset(lst, -1, sizeof lst);
    
    for(int i = n-1; i >= 0; i--){
        if(lst[arr[i]] == -1) lst[arr[i]] = i;    
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << n - go(0) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    