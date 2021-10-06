// Problem: F2. Pictures with Kittens (hard version)
// Contest: Codeforces - Codeforces Round #521 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1077/F2
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

struct monoQueue{
    
    stack<pii> s1, s2;
    
    int size(){
        return s1.size() + s2.size();
    }    
    
    int empty(){
        return !size();
    }
    
    void clear(){
        while(!empty()) pop();
    }
    
    int get_max(){
        
        if(empty()){
            return -INFLL;
        }
        if(!s1.empty() && !s2.empty()){
            return max(s1.top().second, s2.top().second);
        }
        if(!s2.empty()){
            return s2.top().second;
        }
        return s1.top().second;
    }
    
    void push(int val){
        
        if(s2.empty()){
            s2.push({val, val});
        }
        else{
            s2.push({val, max(s2.top().second, val)});
        }
    }
    
    void pop(){
        
        if(s1.empty()){
            while(!s2.empty()){
                
                if(s1.empty()){
                    s1.push({s2.top().first, s2.top().first});
                }
                else{
                    s1.push({s2.top().first, max(s2.top().first, s1.top().second)});
                }
                
                s2.pop();
            }
        }
        assert(!s1.empty());
        s1.pop();
    }
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n, k, x;
    cin >> n >> k >> x;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    monoQueue q;
    
    vector<vi> dp(x+2, vi(n+2));
    for(int i = 0; i < n; i++) dp[0][i] = -INFLL;
    
    for(int i = 1; i <= x; i++){
        
        q.clear();
        q.push(0);
        
        for(int j = 0; j < n; j++){
            
            dp[i][j] = vec[j] + q.get_max();
            
            q.push(dp[i-1][j]);
            if(q.size() > k) q.pop();
        }
    }
    
    int ans = -INFLL;
    for(int i = n-k; i < n; i++) ans = max(ans, dp[x][i]);
    
    cout << (ans >= 0 ? ans : -1) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
