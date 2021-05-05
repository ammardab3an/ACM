// Problem: D. Unmerge
// Contest: Codeforces - Codeforces Round #658 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1382/D
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

int n, m;
int tmp[4040];
int idx[4040];
int arr[4040];
int mem[4040][4040];
int vis[4040][4040], vid;

bool go(int i, int sm){
    
    if(sm < 0) return 0;
    if(i == m) return sm == 0;
    
    if(vis[i][sm] == vid) return mem[i][sm];
    vis[i][sm] = vid;
    
    bool stPath = go(i+1, sm);
    bool ndPath = go(i+1, sm - arr[i]);
    
    return mem[i][sm] = stPath || ndPath;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n; n *= 2;
        for(int i = 0; i < n; i++) cin >> tmp[i];
        for(int i = 0; i < n; i++) idx[tmp[i]] = i;
        
        m = 0;
        int lst = n;
        arr[m++] = n-idx[n];
        
        for(int i = n-1; i >= 1; i--){
            
            if(idx[i] > idx[lst]){
                continue;
            }
            else{
                arr[m++] = idx[lst] - idx[i];
                lst = i;
            }
        }
        
        vid++;
        int ans = go(0, n/2);
        cout << (ans ? "YES" : "NO") << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
