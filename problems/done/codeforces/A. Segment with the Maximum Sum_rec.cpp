// Problem: A. Segment with the Maximum Sum
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
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

#define PAIR pair<pll, pll>
#define ANS first.first
#define SUM first.second
#define PRE second.first
#define SUF second.second

int arr[NMAX];
PAIR tree[NMAX << 4];

PAIR merge(PAIR p0, PAIR p1){
    
    PAIR res;
    
    res.SUM = p0.SUM + p1.SUM;
    res.ANS = max({p0.ANS, p1.ANS, p0.SUF + p1.PRE});  
    res.PRE = max(p0.PRE, p0.SUM + p1.PRE);
    res.SUF = max(p1.SUF, p0.SUF + p1.SUM);
    
    return res;
}

void build(int nd, int l, int r){
    
    if(l == r){
        int fo = max(arr[l], 0);
        tree[nd] = {{fo, arr[l]}, {fo, fo}};
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    if(r < q_l || q_r < l) return;
    
    if(q_l <= l && r <= q_r){
        int fo = max(val, 0);
        tree[nd] = {{fo, val}, {fo, fo}};
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

PAIR query(int nd, int l, int r, int q_l, int q_r){
    
   if(r < q_l || q_r < l) return {{0, 0}, {0, 0}};
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    } 
    
    int mid = (l+r)/2;
    PAIR stPath = query(nd*2, l, mid, q_l, q_r);
    PAIR ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return merge(stPath, ndPath);
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
    
    cout << query(1, 1, n, 1, n).ANS << endl;
    
    while(m--){
        
        int i, v;
        cin >> i >> v;
        
        update(1, 1, n, i+1, i+1, v);
        cout << query(1, 1, n, 1, n).ANS << endl;        
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
