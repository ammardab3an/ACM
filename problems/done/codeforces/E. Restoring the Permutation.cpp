// Problem: E. Restoring the Permutation
// Contest: Codeforces - Codeforces Round #710 (Div. 3)
// URL: https://codeforces.com/contest/1506/problem/E
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, vid = 1;
int arr[NMAX];
int tmp[NMAX];
int vis[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        vid++;
        set<int> st;
        
        for(int i = 0; i < n; i++) st.insert(i+1);
        
        int lst = -1;
        for(int i = 0; i < n; i++){
            if(lst != arr[i]){
                lst = arr[i];
                st.erase(lst);
                vis[i] = vid;
                tmp[i] = lst;
            }
        }
        
        for(int i = 0; i < n; i++) if(vis[i] != vid){
                
            auto it = st.begin();
            tmp[i] = *it;
            st.erase(it);
        }
        
        for(int i = 0; i < n; i++) cout << tmp[i] << ' ' ; cout << endl;
        
        // second
        
        for(int i = 0; i < n; i++) st.insert(i+1);
        
        for(int i = 0; i < n; i++){
                
            auto it = st.upper_bound(arr[i]);
            it--;
            
            tmp[i] = *it;
            
            st.erase(it);
        }
        
        for(int i = 0; i < n; i++) cout << tmp[i] << ' ' ; cout << endl; 
        
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
