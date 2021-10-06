// Problem: C. Number of Inversions on Segment
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

const int NMAX = 1e5 + 10;

int arr[NMAX];
array<int, 42> tree[NMAX << 2];
int ans[NMAX << 2];

int merge(int nd, int l, int r){
    int res = 0;
    for(int i = 1; i <= 40; i++){
        res += (tree[nd*2][i] - tree[nd*2][i-1]) * tree[nd*2+1][i-1];
        tree[nd][i] = tree[nd*2][i] + tree[nd*2+1][i];
    }
    return ans[nd] = res + ans[nd*2] + ans[nd*2+1];
}

pair<int, array<int, 42> > _merge(array<int, 42> a0, array<int, 42> a1){
    int cnt = 0;
    array<int, 42> res;
    for(int i = 1; i <= 40; i++){
        cnt += (a0[i] - a0[i-1]) * a1[i-1];
        res[i] = a0[i] + a1[i];
    }
    return {cnt, res};
}

void build(int nd, int l, int r){
    
    if(l == r){
        for(int i = arr[l]; i <= 40; i++) tree[nd][i] = 1;
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    merge(nd, l, r);
}

void update(int nd, int l, int r, int p, int val){
    
    if(l > p || p > r) return;
    
    if(l == r){
        for(int i = arr[l]; i <= 40; i++) tree[nd][i] = 0;
        arr[l] = val;
        for(int i = arr[l]; i <= 40; i++) tree[nd][i] = 1;
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val);
    update(nd*2+1, mid+1, r, p, val);
    
    merge(nd, l, r);
}

pair<int, array<int, 42> > query(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return {0, array<int,42>({0})};
    
    if(q_l <= l && r <= q_r){
        return {ans[nd], tree[nd]};
    }
    
    int mid = (l+r)/2;
    auto stPath = query(nd*2, l, mid, q_l, q_r);
    auto ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    auto mrg = _merge(stPath.second, ndPath.second);
    
    return {mrg.first + stPath.first + ndPath.first, mrg.second};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    build(1, 1, n);
    
    while(m--){
        
        int k, x, y;
        cin >> k >> x >> y;
        
        if(k == 1){
            auto que = query(1, 1, n, x, y);
            cout << que.first << endl;
        }
        else{
            update(1, 1, n, x, y);
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
