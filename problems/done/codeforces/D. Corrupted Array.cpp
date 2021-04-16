// Problem: D. Corrupted Array
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/D
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
int arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n; n += 2;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        sort(arr, arr+n);
        
        int sum0 = 0;
        for(int i= 0; i < n-2; i++) sum0 += arr[i];
        int sum1 = sum0 + arr[n-2];
        
        bool found = false;
        
        // arr[n-1] is x
        
        if(sum0 == arr[n-2]){
            found = true;
            for(int i = 0; i < n-2; i++) cout << arr[i] << ' '; cout << endl;
        }
        else{
            
            // arr[n-1] is sum;
            
            int x = sum1 - arr[n-1];
            
            int l = 0;
            int r = n-2;
            int ans = -1;
            
            while(l <= r){
                int m = (l+r)/2;
                if(arr[m] >= x){
                    ans = m;
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            
            if((ans == -1) || (arr[ans] != x)){
                
            }
            else{
                found = true;
                for(int i = 0; i < n-1; i++){
                    if(i == ans) continue;
                    cout << arr[i] << ' ' ;
                }
                cout << endl;
            }
        }
        
        if(!found) cout << -1 << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
