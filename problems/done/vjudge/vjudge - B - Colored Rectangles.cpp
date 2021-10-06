// Problem: B - Colored Rectangles
// Contest: Virtual Judge - Dp 2
// URL: https://vjudge.net/contest/432549#problem/B
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

vector<vi> vec(3);
lli mem[222][222][222];

lli go(int i, int j, int k){
    
    if(bool(i==-1) + bool(j==-1) + bool(k==-1) >= 2) return 0;
    
    auto &ret = mem[i+1][j+1][k+1];
    if(ret + 1) return ret;    
    
    lli stPath = 0, ndPath = 0, rdPath = 0;
    
    if(i != -1 && j != -1) stPath = (1ll * vec[0][i] * vec[1][j]) + go(i-1, j-1, k);
    if(i != -1 && k != -1) ndPath = (1ll * vec[0][i] * vec[2][k]) + go(i-1, j, k-1);
    if(j != -1 && k != -1) rdPath = (1ll * vec[1][j] * vec[2][k]) + go(i, j-1, k-1);
    
    return ret = max({stPath, ndPath, rdPath});
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int r, b, g;
    cin >> r >> b >> g;
    
    vec[0] = vi(r);
    vec[1] = vi(b);
    vec[2] = vi(g);
    
    for(int i = 0; i < 3; i++)
    for(auto &i : vec[i]) cin >> i;
    
    for(auto &v : vec) sort(v.begin(), v.end());
    
    memset(mem, -1, sizeof mem);
       
    cout << go(vec[0].size()-1, vec[1].size()-1, vec[2].size()-1) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
