// Problem: C. Berland Regional
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/C
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

int uni[NMAX];
int s[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        lli tot = 0;
        
        map<int, vi> mp;
        
        for(int i = 0; i < n; i++) cin >> uni[i];
        for(int i = 0; i < n; i++) cin >> s[i], tot += s[i];
        
        for(int i = 0; i < n; i++) mp[uni[i]].push_back(s[i]);
        
        vector<vi> vecs;
        for(auto &p : mp) vecs.emplace_back(p.second);
        
        vi ans(n+2);
        
        for(auto & v : vecs){
            
            sort(v.begin(), v.end());
            
            int sz = v.size();
            vi pre(sz);
            
            pre[0] = v[0];
            for(int i = 1; i < sz; i++) pre[i] = pre[i-1] + v[i];
            
            for(int i = 1; i <= sz; i++){
                
                if(sz%i){
                    
                    ans[i] += pre[(sz%i) -1];
                    ans[i+1] -= pre[(sz%i) -1];
                }
            }
            
            if(n > sz){
                ans[sz+1] += pre[sz-1];
                ans.back() -= pre[sz-1];
            }
        }
        
        
        int pre = tot;
        for(int i = 1; i <= n; i++){
            pre -= ans[i];
            cout << pre << ' ' ;
        }
        cout << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
