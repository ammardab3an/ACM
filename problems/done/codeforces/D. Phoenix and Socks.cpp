// Problem: D. Phoenix and Socks
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/D
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

        int n, l, r;
        cin >> n >> l >> r;
        
        vi vec_l(l), vec_r(r);
        for(auto &i : vec_l) cin >> i;
        for(auto &i : vec_r) cin >> i;
        
        sort(vec_l.begin(), vec_l.end());
        sort(vec_r.begin(), vec_r.end());
        
        int ans = 0;
        int cnt_l = 0, cnt_r = 0;
        int fo = 0, fo_l = 0, fo_r = 0;
        
        int i = 0, j = 0;
        
        while((i < l) && (j < r)){
            
            if(vec_l[i] == vec_r[j]){
                i++, j++, fo++;
            }
            
            else if(vec_l[i] < vec_r[j]){
                
                int cnt = 1;
                
                while((i+1 < l) && (vec_l[i+1] == vec_l[i])){
                    cnt++;
                    i++;
                }
                
                ans += cnt/2;
                fo_l += cnt/2;
                cnt_l += cnt%2;
                
                i++;
            }
            
            else if(vec_r[j] < vec_l[i]){
                
                int cnt = 1;
                
                while((j+1 < r) && (vec_r[j+1] == vec_r[j])){
                    cnt++;
                    j++;
                }
                
                ans += cnt/2;
                fo_r += cnt/2;
                cnt_r += cnt%2;
                
                j++;
            }
        }
        
        while(i < l){
            
            int cnt = 1;
            
            while((i+1 < l) && (vec_l[i+1] == vec_l[i])){
                cnt++;
                i++;
            }
            
            ans += cnt/2;
            fo_l += cnt/2;
            cnt_l += cnt%2;
            
            i++;
        }
        
        while(j < r){
            
            int cnt = 1;
            
            while((j+1 < r) && (vec_r[j+1] == vec_r[j])){
                cnt++;
                j++;
            }
            
            ans += cnt/2;
            fo_r += cnt/2;
            cnt_r += cnt%2;
            
            j++;
        }
        
        
        if(cnt_l && cnt_r){
            
            int mn = min(cnt_l, cnt_r);
            ans += mn;
            cnt_l -= mn;
            cnt_r -= mn;
        }
        
        if(cnt_l){
            
            int mn = min(fo_r*2, cnt_l);
            ans -= fo_r;
            ans += mn;
            ans += (cnt_l-mn);
            ans += fo_r - mn/2;
        }
        
        if(cnt_r){
            
            int mn = min(fo_l*2, cnt_r);
            ans -= fo_l;
            ans += mn;
            ans += (cnt_r-mn);
            ans += fo_l - mn/2;
        }
        
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