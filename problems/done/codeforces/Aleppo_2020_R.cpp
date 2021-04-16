
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        int n, m, b;
        cin >> n >> m >> b;
        
        vector< pair<pii, pii> > vec(m);
        for(auto &p : vec){
            cin >> p.second.first >> p.second.second >> p.first.first >> p.first.second;
        }
        
        sort(vec.begin(), vec.end());
        int j = 0;
        
        int size = 1;
        while(size < (n+1)) size *= 2;
        
        vi tree(2 * size);
        
        for(int i = 2; i <= n; i++){
            
            int cur = tree[size + i-1] + b;
            
            while((j < vec.size()) && (vec[j].first.first == i)){
                
                int ans = INF;
                int l = vec[j].second.first + size;
                int r = vec[j].second.second + size + 1;
                
                for(; l < r; l/=2, r/=2){
                    if(l&1) ans = min(ans, tree[l++]);
                    if(r&1) ans = min(ans, tree[--r]);
                }
                
                cur = min(cur, ans + vec[j].first.second);
                
                j++;
            }
            
            int p = i+size;
            for(tree[p] = cur; p > 1; p/=2) tree[p/2] = min(tree[p], tree[p^1]);
        }
        
        cout << tree[size + n] << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
