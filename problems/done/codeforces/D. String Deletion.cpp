// Problem: D. String Deletion
// Contest: Codeforces - Educational Codeforces Round 96 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1430/problem/D
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

int n, sz;
char str[NMAX];
pii cnt[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; 
    
    while(t--){
        
        //init
        sz = 0;

        cin >> n >> str;

        int past = str[0] - '0';
        int past_cnt = 1;
        
        for(int i = 1; i < n; i++){

            int cur = str[i] - '0';

            if(cur != past){
                cnt[sz++] = {past, past_cnt};
                past = cur;
                past_cnt = 1;
            }
            else{
                past_cnt++;
            }
        }

        cnt[sz++] = {past, past_cnt};

        int ans = 0;
        int car = 0;
        
        for(int i = 0; i < sz; i++){
                      
            ans++;
            car++;
            
            int cur_over = cnt[i].second -1;
            
            if(cur_over >= 1){
                car = max(0, car-cur_over);
            }    
        }
        
        cout << ans - car/2 << endl;
    }	
}