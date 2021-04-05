// Problem: A. Addition and Minimum
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

int tree[NMAX << 2];
int lazy[NMAX << 2];

void push(int nd, int l, int r){
    
    tree[nd] += lazy[nd];
    
    if(l != r){
        lazy[nd*2] += lazy[nd];
        lazy[nd*2+1] += lazy[nd];
    }
    
    lazy[nd] = 0;    
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    if(l > q_r || q_l > r) return;
    
    push(nd, l, r);
    
    if(q_l <= l && r <= q_r){
        lazy[nd] += val;
        return;    
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    push(nd*2, l, mid);
    push(nd*2+1, mid+1, r);
    
    tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return INFLL;
    
    push(nd, l, r);
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return min(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, m;
    cin >> n >> m;
    
    while(m--){
        
        int k;
        cin >> k;
        
        if(k == 1){
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l+1, r, val);
        }
        
        else{
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l+1, r) << endl;
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
