// https://codeforces.com/gym/102800

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
            ret ^= bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) ^ sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] ^= delta;
    }
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n, m;
    cin >> n >> m;
    
    vi vec(n+1);
    for(int i = 1; i <= n; i++) cin >> vec[i];
    
    vpii q(m);
    for(auto &p : q) cin >> p.first >> p.second;
    
    vi ans(m), idxs(m);
    for(int i = 0; i < m; i++) idxs[i] = i;
    
    auto cmp = [&](int i, int j){
        if(q[i].second == q[j].second)
            return q[i].first > q[j].first;
        return q[i].second > q[j].second;
    };
    
    sort(idxs.begin(), idxs.end(), cmp);
    
    FenwickTree ft(n+1);
    
    map<int, int> last;
    
    for(int i = 1; i <= n; i++){
        
        auto it = last.find(vec[i]);
        if(it != last.end()){
            ft.add(it->second, vec[i]);
        }
        
        while(!idxs.empty() && (q[idxs.back()].second == i)){
            pii tmp = q[idxs.back()]; 
            ans[idxs.back()] = ft.sum(tmp.first, tmp.second);
            idxs.pop_back();
        }
        
        last[vec[i]] = i;
    }
    
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
