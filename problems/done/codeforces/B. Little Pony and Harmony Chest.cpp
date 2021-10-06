// Problem: B. Little Pony and Harmony Chest
// Contest: Codeforces - Codeforces Round #259 (Div. 1)
// URL: https://codeforces.com/contest/453/problem/B?outsideGroup=true
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
int arr[110];
int fact[100];
int mem[110][1 << 17];

int go(int pos, int msk){
    
    if(pos == n) return 0;
    
    int &ret = mem[pos][msk];
    if(ret + 1) return ret;
    
    int ans = INF;
    
    for(int i = 1; i < 60; i++){
        if((msk & fact[i]) == 0){
            ans = min(ans, abs(arr[pos] - i) + go(pos+1, msk | fact[i]));    
        }
    }
    
    return ret = ans;
}

void calc(int pos, int msk){
    
    if(pos == n){
        cout << endl;
        return;
    }
    
    int ans = go(pos, msk);
    
    for(int i = 1; i < 60; i++){
        if((msk & fact[i]) == 0){
            int tans = abs(arr[pos] - i) + go(pos+1, msk | fact[i]);    
            if(tans == ans){
                cout << i << ' ';
                calc(pos+1, msk | fact[i]);
                return;
            }
        }
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    
    for(int i = 1; i < 60; i++){
        for(int j = 0; j < 17; j++){
            if(i % primes[j] == 0) fact[i] |= 1 << j;
        }
    }
    
    memset(mem, -1, sizeof mem);
    
    // cout << go(0, 0) << endl;
    
    calc(0, 0);
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
