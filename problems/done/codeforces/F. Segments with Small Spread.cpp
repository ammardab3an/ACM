// Problem: F. Segments with Small Spread
// Contest: Codeforces - ITMO Academy: pilot course - Two Pointers Method - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

    lli n, k;
    cin >> n >> k;
    
    vl vec(n);
    for(auto &i : vec) cin >> i;
    
    lli ans = 0;
    
    stack<lli> st0, st1;
    stack<pll> stmx0, stmx1;
    
    auto add = [&](lli num){
        st1.push(num);
        auto tp = stmx1.empty() ? (pll){INFLL, -INFLL} : stmx1.top();
        tp.first = min(tp.first, num);
        tp.second = max(tp.second, num);
        stmx1.push(tp);
    };
    
    auto del = [&](){

        if(st0.empty()) while(!st1.empty()){
            lli num = st1.top();
            auto tp = stmx0.empty() ? (pll){INFLL, -INFLL} : stmx0.top();
            tp.first = min(tp.first, num);
            tp.second = max(tp.second, num);
            st0.push(num); stmx0.push(tp);
            st1.pop(); stmx1.pop();
        }

        st0.pop(); stmx0.pop();
    };
    
    auto dif = [&](){
        auto tp0 = stmx0.empty() ? pll({INFLL/2, -INFLL/2}) : stmx0.top();
        auto tp1 = stmx1.empty() ? pll({INFLL/2, -INFLL/2}) : stmx1.top();
        return max(tp0.second, tp1.second) - min(tp0.first, tp1.first);    
    };
    
    int j = 0;
    for(int i = 0; i < n; i++){
                
        if(i) del();
        
        while(j < n && dif() <= k) add(vec[j++]);
        
        if(dif() <= k){
            ans += j-i;
        }
        else{
            ans += j-1-i;
        }
    }

    cout << ans << endl;
}
