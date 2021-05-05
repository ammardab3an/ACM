// Problem: A. Phoenix and Gold
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/A
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n, k;
        cin >> n >> k;
        
        vi vec(n);
        for(auto &i : vec) cin >> i;
        
        if(n == 1 && vec[0] == k){
            cout << "NO" << endl;
            continue;
        }
        
        sort(vec.begin(), vec.end());
        
        vi pre(n);
        pre[0] = vec[0];
        for(int i = 1; i < n; i++) pre[i] = pre[i-1] + vec[i];
        
        int lb = lower_bound(pre.begin(), pre.end(), k) - pre.begin();
        
        if((lb == n-1) && (pre[lb] == k)){
            cout << "NO" << endl;
            continue;
        }
        
        if((lb == n) || (pre[lb] > k)){
            cout << "YES" << endl;
            for(int i : vec) cout << i << ' ' ; cout << endl;
            continue;
        }
        
        if(pre[lb] == k){
            cout << "YES" << endl;
            for(int i = 0; i < lb; i++){
                cout << vec[i] << ' ';
            }
            for(int i = n-1; i >= lb; i--){
                cout << vec[i] << ' ';
            }
            cout << endl;
        }
        
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
