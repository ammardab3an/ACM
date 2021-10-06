// Problem: B. RPG Protagonist
// Contest: Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1400/problem/B
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int p, f;
        cin >> p >> f;

        int cnt_s, cnt_w;
        cin >> cnt_s >> cnt_w;

        int s, w;
        cin >> s >> w;

        if(s > w){
            swap(cnt_s, cnt_w);
            swap(s, w);
        }

        int ans = 0;

        for(int i = 0; i <= cnt_s; i++){

            int cans = i;

            int left_s = cnt_s - i;
            int left_w = cnt_w;

            int take_s = i;
            int take_w = 0;

            if(take_s*s > p) break;

            int left_p = p - take_s * s;
            int take_w_p = min(left_p / w, left_w);
            left_p -= take_w_p * w;
            left_w -= take_w_p;
            cans += take_w_p;
            
            int left_f = f;
            int take_s_f = min(left_f/s, left_s);
            left_f -= take_s_f * s;
            left_s -= take_s_f;
            cans += take_s_f;

            int take_w_f = min(left_f/w, left_w);
            left_f -= take_w_f * w;
            left_w -= take_w_f;
            cans += take_w_f;

            ans = max(ans, cans);
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
