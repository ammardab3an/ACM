// Problem: C. Baby Ehab Partitions Again
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/C
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[111];
int mem[111][100010];
int vis[111][100010], vid;

int go(int i, int rem){
    
    if(rem < 0) return 0;
    if(i == n) return !rem;
    
    if(vis[i][rem]) return mem[i][rem];
    vis[i][rem] = true;
    
    int stPath = go(i+1, rem);
    int ndPath = go(i+1, rem-arr[i]);
    
    return mem[i][rem] = stPath || ndPath;  
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int sm = 0;
    for(int i = 0; i < n; i++) sm += arr[i];
    
    vid++;

    if((sm%2==1) || !go(0, sm/2)){
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        
        sm -= arr[i];
        int tmp = arr[i];
        arr[i] = 0;
        
        vid++;
        
        if((sm%2==1) || !go(0, sm/2)){
            cout << 1 << endl << i+1 << endl;
            break;
        }
        
        sm += tmp;
        arr[i] = tmp;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
