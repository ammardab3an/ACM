// Problem: F. Moving Points
// Contest: Codeforces - Codeforces Round #624 (Div. 3)
// URL: https://codeforces.com/contest/1311/problem/F
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

struct FenwickTree {
    
    int n;
    vector<int> bit; 

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    vpii vec(n);
    for(auto &p : vec) cin >> p.first;
    for(auto &p : vec) cin >> p.second;
    
    sort(vec.begin(), vec.end());
    
    {
        set<int> st;
        map<int, int> mp;
        for(auto p : vec) st.insert(p.second);
        
        int lst = -INF;
        int cnt = 0;
        
        for(auto i : st){
            if(i != lst){
                lst = i;
                mp[lst] = cnt++;
            }
        }
        for(auto &p : vec) p.second = mp[p.second];
    }
    
    
    FenwickTree ft_cnt(n+1);
    FenwickTree ft_sum(n+1);
    
    int ans = 0;
    
    for(int i = n-1; i >= 0; i--){
        
        int cx = vec[i].first;
        int cv = vec[i].second;
        
        ans += ft_sum.sum(cv+1, n) - ft_cnt.sum(cv+1, n) * cx;
        
        ft_sum.add(cv+1, cx);
        ft_cnt.add(cv+1, +1);
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
