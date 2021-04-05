// Problem: A. Assignment, Addition, and Sum
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A
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
int lazy_ass[NMAX << 2];
int lazy_add[NMAX << 2];

void push(int nd, int l, int r){
    
    if(lazy_ass[nd] != -1){
        
        tree[nd] = (r-l+1) * lazy_ass[nd];
        
        if(l != r){
            lazy_ass[nd*2] = lazy_ass[nd];
            lazy_ass[nd*2+1] = lazy_ass[nd];
            lazy_add[nd*2] = lazy_add[nd*2+1] = 0;
        }
        
        lazy_ass[nd] = -1;
    }
    
    if(lazy_add[nd]){
        
        tree[nd] += (r-l+1) * lazy_add[nd];
        
        if(l != r){
            
            lazy_add[nd*2] += lazy_add[nd];
            lazy_add[nd*2+1] += lazy_add[nd];
        }
        
        lazy_add[nd] = 0;
    }
}

void update_ass(int nd, int l, int r, int q_l, int q_r, int val){
    
    push(nd, l, r);
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
        lazy_ass[nd] = val;
        lazy_add[nd] = 0;
        push(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update_ass(nd*2, l, mid, q_l, q_r, val);
    update_ass(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

void update_add(int nd, int l, int r, int q_l, int q_r, int val){
    
    push(nd, l, r);
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
        
        if(lazy_ass[nd] != -1){
            lazy_ass[nd] += val;
        }
        else{
            lazy_add[nd] += val;        
        }
        
        push(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update_add(nd*2, l, mid, q_l, q_r, val);
    update_add(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(l > q_r || q_l > r) return 0;
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return stPath + ndPath;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n, m;
    cin >> n >> m;
    
    memset(lazy_ass, -1, sizeof lazy_ass);
    
    while(m--){
        
        int k;
        cin >> k;
        
        if(k == 1){
            int l, r, v;
            cin >> l >> r >> v;
            update_ass(1, 1, n, l+1, r, v);
        }
        else if(k == 2){
            int l, r, v;
            cin >> l >> r >> v;
            update_add(1, 1, n, l+1, r, v);
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
