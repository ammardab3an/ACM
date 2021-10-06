// Problem: G. Coprime Segment
// Contest: Codeforces - ITMO Academy: pilot course - Two Pointers Method - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G
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

    int n;
    cin >> n;
    
    vl vec(n);
    for(auto &i : vec) cin >> i;
    
    int ans = INF;
    
    stack<lli> st0, st1;
    stack<lli> stgcd0, stgcd1;
    
    auto add = [&](lli num){
        st1.push(num);
        auto tp = stgcd1.empty() ? num : stgcd1.top();
        stgcd1.push(__gcd(num, tp));
    };
    
    auto del = [&](){

        if(st0.empty()) while(!st1.empty()){
            lli num = st1.top();
            auto tp = stgcd0.empty() ? num : stgcd0.top();
            st0.push(num); stgcd0.push(__gcd(num, tp));
            st1.pop(); stgcd1.pop();
        }

        st0.pop(); stgcd0.pop();
    };
    
    auto getgcd = [&](){
        
        if(stgcd0.empty() && stgcd1.empty()){
            return 2LL;   
        }
        else if(stgcd0.empty() || stgcd1.empty()){
            if(stgcd0.empty()) return stgcd1.top();
            else return stgcd0.top();
        }  
        else{
            return __gcd(stgcd0.top(), stgcd1.top());
        }
    };
    
    int j = 0;
    for(int i = 0; i < n; i++){
        
        if(i) del();
        
        while((j < n) && (getgcd() != 1)) add(vec[j++]);
        
        if(getgcd() == 1){
            ans = min(ans, j-i);
        }
        
    }
    
    cout << (ans == INF ? -1 : ans) << endl;
}
