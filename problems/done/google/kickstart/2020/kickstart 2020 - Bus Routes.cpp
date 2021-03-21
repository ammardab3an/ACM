// Problem: Bus Routes
// Contest: Google Coding Competitions - Round B 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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
    
    int tt = 1;
    int t; cin >> t; while(t--){
        
        int n, d;
        cin >> n >> d;
        
        vi vec(n);
        for(int &i : vec) cin >> i;
        
        auto can = [&](int m){
            
            int lst = vec[0] * m;
            
            for(int i = 1; i < n; i++){
                
                int cl = (lst + vec[i]-1) / vec[i];
                lst = cl * vec[i];
                
                assert(lst/cl == vec[i]);
                if(lst < 0) return false;
                if(lst > d) return false;
            }
            
            return lst <= d;
        };
        
        int l = 1;
        int r = d;
        
        int ans = 1;
        
        while(l <= r){
            
            int m = (l+r)/2;
            
            if(can(m)){
                ans = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        
        cout << "Case #" << tt++ << ": ";
        cout << ans*vec[0] << endl;
    }	
}
