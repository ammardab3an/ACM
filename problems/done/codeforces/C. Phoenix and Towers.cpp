// Problem: C. Phoenix and Towers
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/C
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
        
        int n, m, x;
        cin >> n >> m >> x;
        
        vpii vec(n);
        for(int i = 0; i < n; i++){
            int ai;
            cin >> ai;
            int idx = i;
            vec[i] = {ai, idx};
        }
        
        sort(vec.begin(), vec.end(), greater<pii>());
        
        set<pii> st_p;
        for(int i = 1; i <= m; i++){
            st_p.insert({0, i});
        }
        
        vi res(n);
        for(int i = 0; i < n; i++){
            
            auto p = *st_p.begin();
            st_p.erase(st_p.begin());
            
            int v = vec[i].first;
            int j = vec[i].second;
            
            st_p.insert({p.first + v, p.second});

            res[j] = p.second;            
        }
        
        if(st_p.rbegin()->first <= x + st_p.begin()->first){
            cout << "YES" << endl;
            for(int i : res) cout << i << ' ' ; cout << endl;
        }
        else{
            cout << "NO" << endl;
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
