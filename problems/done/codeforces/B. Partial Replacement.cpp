// Problem: B. Partial Replacement
// Contest: Codeforces - Codeforces Round #710 (Div. 3)
// URL: https://codeforces.com/contest/1506/problem/B
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
string str;
int mem[55][55];

int go(int pos, int lst){
    
    if(pos == n) return 0;
    
    if(str[pos] == '*' || str[pos] == 'x')
    if(pos - lst > k) return INF;
    
    int &ret = mem[pos][lst];
    if(ret+1) return ret;
    
    int p = 0;
    
    if(str[pos] == 'x') lst = pos, p++;
    
    int stPath = go(pos+1, lst);
    int ndPath = INF;
    
    if(str[pos] == '*'){
        ndPath = go(pos+1, pos) + 1;
    }    
    
    return ret = min(stPath, ndPath) + p;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){


        cin >> n >> k;
        cin >> str;

        int ans = 0;
        
        int i = 0;
        while(str[i] != '*') i++;
        str[i] = 'x';
        
        int b = i;
        
        i = n-1;
        while(i >= 0 && str[i] != '*') i--;
        if(i != -1) str[i] = 'x';
        
        memset(mem, -1, sizeof mem);
        
        cout << go(b, b) << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    