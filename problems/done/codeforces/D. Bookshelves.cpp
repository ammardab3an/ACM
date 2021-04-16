// Problem: D. Bookshelves
// Contest: Codeforces - Avito Code Challenge 2018
// URL: https://codeforces.com/contest/981/problem/D?outsideGroup=true
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

int n, k;
lli num;
lli arr[55];
int mem[55][55];

bool go(int pos, int k){
    
    if(pos == n) return 0;
    
    auto &ret = mem[pos][k];
    if(ret + 1) return ret;
    
    if(k == 1){
        lli sum = 0;
        for(int i = pos; i < n; i++) sum += arr[i];
        return ret = (sum & num) == num;
    }
    
    lli sum = 0;
    for(int i = pos; i < n-(k-1); i++){
        sum += arr[i];
        if((sum & num) == num) if(go(i+1, k-1)) return ret = true;
    }
    
    return ret = false;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> k;    
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 60; i >= 0; i--){
        num ^= 1LL << i;
        memset(mem, -1, sizeof mem);
        if(!go(0, k)) num ^= 1LL << i;    
    }
    
    cout << num << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
