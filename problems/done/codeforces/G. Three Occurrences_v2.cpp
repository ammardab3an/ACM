// Problem: G. Three Occurrences
// Contest: Codeforces - Educational Codeforces Round 95 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1418/problem/G
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
vi idxs[NMAX];
pii tree[NMAX << 2];
int lazy[NMAX << 2];

pii merge(pii p0, pii p1){
    pii ret;
    ret.first = min(p0.first, p1.first);
    ret.second = 0;
    if(p0.first == ret.first) ret.second += p0.second;
    if(p1.first == ret.first) ret.second += p1.second;
    return ret;
}

void push_down(int nd, int l, int r){
        
    tree[nd].first += lazy[nd];
    
    if(l != r){
        lazy[nd*2] += lazy[nd];
        lazy[nd*2+1] += lazy[nd];
    }
    
    lazy[nd] = 0;
}

void build(int nd, int l, int r){
    
    if(l == r){
        tree[nd] = {0, 1};
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    push_down(nd, l, r);
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
        lazy[nd] += val;
        push_down(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

pii query(int nd, int l, int r, int q_l, int q_r){
    
    push_down(nd, l, r);
    
    if(l > q_r || q_l > r) return {INF, 0};
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    pii stPath = query(nd*2, l, mid, q_l, q_r);
    pii ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    return merge(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    build(1, 1, n);
    
    lli ans = 0;

    for(int i = 1; i <= n; i++) idxs[i].push_back(0);
    
    for(int i = 1; i <= n; i++){
        
        int ai = arr[i];
        
        int sz = idxs[ai].size();
        
        if(sz >= 1)
            update(1, 1, n, idxs[ai][sz-1]+1, i, 1);
        if(sz >= 3)
            update(1, 1, n, idxs[ai][sz-3]+1, idxs[ai][sz-2], -1);
        if(sz >= 4)
            update(1, 1, n, idxs[ai][sz-4]+1, idxs[ai][sz-3], 1);
        
        idxs[ai].push_back(i);
        
        auto que = query(1, 1, n, 1, i);
        if(que.first == 0) ans += que.second;
        
        // for(int i = 1; i <= n; i++)
            // cout << query(1, 1, n, i, i).first << ' ' ; cout << endl;
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
