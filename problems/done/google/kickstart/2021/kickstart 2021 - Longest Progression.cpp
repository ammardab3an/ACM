// Problem: Increasing Substring
// Contest: Google Coding Competitions - Round B 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a882
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

const int NMAX = 3e5 + 10;

int n;
int arr[NMAX];
int mem[NMAX][5][2];

int go(int i, int lst, int k){
    
    if(i >= n-1) return 0;
    
    int &ret = mem[i][lst][k];
    if(ret+1) return ret;
    
    int ans = k;
    
    if(lst == 1){
        
        if((arr[i+1] - arr[i]) == (arr[i] - arr[i-1])){
            ans = max(ans, go(i+1, 1, k) + 1);
        }
        
        if(k && (i+2<n)){
            
            if((arr[i+2] - arr[i]) == (int(2) * (arr[i] - arr[i-1])))
                ans = max(ans, go(i+2, 2, 0) + 2);
                
        }
           
    }
    
    if(lst == 2){
        
        if((int(2) * (arr[i+1] - arr[i])) ==  (arr[i] - arr[i-2]))
            ans = max(ans, go(i+1, 1, 0) + 1);
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int tt = 1;
    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        memset(mem, -1, sizeof mem);
        
        int ans = 2;
        
        for(int i = 1; i < n; i++){
            ans = max(ans, go(i, 1, 1) + 2);
        }
        
        for(int i = 2; i < n; i++){
            ans = max(ans, go(i, 1, 0) + 3);
            ans = max(ans, go(i, 2, 0) + 3);
        }
        
        cout << "Case #" << tt++ << ": ";        
        cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
