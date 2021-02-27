// Problem: D. Children Holiday
// Contest: Codeforces - ITMO Academy: pilot course - Binary Search - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
// Memory Limit: 512 MB
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

    lli k, n;
    cin >> k >> n;
    
    vector<lll> vec(n);
    for(auto &p : vec) cin >> p.first >> p.second.first >> p.second.second;
    
    lli l = 0;
    lli r = 3e8 + 10;
    lli ans = -1;
    
    auto can = [&](lli m, bool print){
        
        lli cnt = 0;
        lli rem = k;

        for(auto p : vec){
            
            lli t = p.first;
            lli y = p.second.first;
            lli z = p.second.second;
            
            lli ccnt = 0;
            
            lli tim = t * y + z;
            ccnt += (m/tim) * y;
            
            lli rem_time = m % (tim);
            ccnt += min(rem_time/t, y);
            
            cnt += ccnt;
            
            if(print){
                cout << min(rem, ccnt) << ' ';
                rem = max(0LL, rem - ccnt);
            }
        }
        
        return cnt >= k;
    };
    
    while(l <= r){
        lli m = (l+r)/2;
        if(can(m, 0)){
            ans = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    
    
    cout << ans << endl;
    can(ans, 1);
}
