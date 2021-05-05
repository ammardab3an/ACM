// Problem: Closest Pick
// Contest: Google Coding Competitions - Round 1C 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/00000000004362d7/00000000007c0f00
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

    int tt = 1;
    int t; cin >> t; while(t--){

        int n, k;
        cin >> n >> k;
        
        vi vec(n);
        for(auto &i : vec) cin >> i;
        
        sort(vec.begin(), vec.end());
        
        int ans = 0;
        
        if(n == 1){
            
            ans = max(ans, k-vec[0]);
            ans = max(ans, vec[0]-1);
            
            if(vec[0] > 1 && vec[0] < k){
                ans = max(ans, vec[0]-1 + k-vec[0]);
            }
            
            cout << "Case #" << tt++ << ": ";
            cout << fixed << setprecision(10) << double(ans)/k << endl;        
            
            continue;
        }
        
        vi tmp;
        for(int i = 0; i < n-1; i++){
            int cur = vec[i+1] - vec[i] -1;
            if(cur > 0){
                tmp.push_back(cur);
                ans = max(ans, cur);
            }
        }
        
        sort(tmp.begin(), tmp.end());
        
        int bg0 = 0;
        int bg1 = 0;
        
        if(vec[0] > 1)
            bg0 = vec[0]-1;
        if(vec[n-1] < k)
            bg1 = k-vec[n-1];
        
        if(bg0 > bg1) swap(bg0, bg1);
        
        ans = max(ans, bg0 + bg1);
        
        if(tmp.size() >= 1)
            ans = max(ans, bg1 + (tmp[tmp.size()-1]+1)/2);
        if(tmp.size() >= 2)
            ans = max(ans, (tmp[tmp.size()-1]+1)/2 + (tmp[tmp.size()-2]+1)/2);
        
        cout << "Case #" << tt++ << ": ";
        cout << fixed << setprecision(10) << double(ans)/k << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
