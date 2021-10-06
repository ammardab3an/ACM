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
    
    vi ans;
    int ans_dif = INF;
    
    int cnt = 0;
    queue<int> que[4];
    
    int r = 0;
    for(int l = 0; l < n; l++){
        
        if(l){
            que[arr[l-1].second].pop();
            if(que[arr[l-1].second].empty()) cnt--;
        }
        
        while(r < n && cnt < 4){
            if(que[arr[r].second].empty()) cnt++;
            que[arr[r].second].push(arr[r].first);
            r++;
        }
        
        if(cnt == 4){
            
            vi cans = {que[0].back(), que[1].back(), que[2].back(), que[3].back()};
            int cdif = que[arr[r-1].second].back() - que[arr[l].second].front();
            
            if(cdif < ans_dif){
                ans_dif = cdif;
                ans = cans;
            }
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
