// Problem: D. Playlist
// Contest: Codeforces - Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/D
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

// #define endl '\n'
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        int n;
        cin >> n;
        
        vi vec(n);
        for(int &i : vec) cin >> i;
        
        set<int> rst, bad;
        
        for(int i = 0; i < n; i++) rst.insert(i);
        for(int i = 0; i < n; i++) if(gcd(vec[i], vec[(i+1)%n]) == 1) bad.insert(i);
        
        vi ans;
        
        int cur = 0;
        
        while(!bad.empty()){
            
            if(rst.size() == 1){
                if(vec[cur] == 1)
                    ans.push_back(cur);
                break;
            }
            
            auto it = bad.lower_bound(cur);
            if(it == bad.end()) it = bad.begin();
            
            cur = *it;
            
            it = rst.lower_bound(cur);
            
            it++;
            if(it == rst.end()) it = rst.begin();
            int nxt = *it;
            
            it++;
            if(it == rst.end()) it = rst.begin();            
            int ftr = *it;
            
            ans.push_back(nxt);
            
            rst.erase(nxt);
            bad.erase(cur);
            
            if(gcd(vec[nxt], vec[ftr]) == 1) bad.erase(nxt);
            if(gcd(vec[cur], vec[ftr]) == 1) bad.insert(cur);
            
            cur = ftr;
        }
        
        cout << ans.size() << ' ';
        for(auto i : ans) cout << i+1 << ' '; cout << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
