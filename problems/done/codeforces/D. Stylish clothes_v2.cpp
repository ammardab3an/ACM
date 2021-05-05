// Problem: D. Stylish clothes
// Contest: Codeforces - ITMO Academy: pilot course - Two Pointers Method - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D
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

const int  MAX = 2e5 + 10;
const int NMAX = 4e5 + 10;
const int MMAX = 2e5 + 10;

int n;
pii arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    for(int i = 0; i < 4; i++){
        
        int ni;
        cin >> ni;
        
        while(ni--){
            cin >> arr[n++].first;
            arr[n-1].second = i;
        }
    }
    
    sort(arr, arr+n);
    
    int cnt = 0;
    int frq[4] = {0};
    
    int ans_l = -1;
    int ans_dif = INF;
    
    int r = 0;
    for(int l = 0; l < n; l++){
        
        if(l){
            frq[arr[l-1].second]--;
            if(!frq[arr[l-1].second]) cnt--;
        }
        
        while(r < n && cnt < 4){
            if(!frq[arr[r].second]) cnt++;
            frq[arr[r].second]++;
            r++;
        }
        
        if(cnt == 4){
            int cdif = arr[r-1].first - arr[l].first;
            if(cdif < ans_dif){
                ans_l = l;
                ans_dif = cdif;
            }
        }
    }
    
    cnt = 0;
    vi vis(4);
    vi ans(4);
    
    for(int i = ans_l; cnt < 4; i++){
        if(!vis[arr[i].second]){
            vis[arr[i].second] = true;
            ans[arr[i].second] = arr[i].first;
            cnt++;
        }
    }
    
    for(auto i : ans) cout << i << ' ';
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
