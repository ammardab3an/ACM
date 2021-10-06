// Problem: E. Skyline Photo
// Contest: Codeforces - Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/E
// Memory Limit: 256 MB
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    vi a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    
    vi p(n);
    
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        p[i] = st.empty() ? i : st.top();   
        st.push(i);
    }
    
    int base = 1;
    while(base < n) base *= 2;
    
    vi tree(2 * base);
    
    for(int i = 0; i < n; i++){
        
        int ans, l, r;
        
        if(p[i] == i){   
            ans = b[i];
            l = base + 0;
            r = base + i;
        }
        else{
            ans = tree[base + p[i]];    
            l = base + p[i];
            r = base + i;
        }
        
        for(; l < r; l /= 2, r /= 2){
            if(l&1) ans = max(ans, tree[l++] + b[i]);
            if(r&1) ans = max(ans, tree[--r] + b[i]);
        }
        
        int p = base + i;
        for(tree[p] = ans; p > 1; p /= 2)
            tree[p/2] = max(tree[p], tree[p^1]);
    }
    
    cout << tree[base + n-1] << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
