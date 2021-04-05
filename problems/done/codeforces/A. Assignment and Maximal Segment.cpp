// Problem: A. Assignment and Maximal Segment
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/A
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

struct node{
    lli seg, pre, suf, sum;
    node(){
        seg = pre = suf = sum = 0;
    }
};

node tree[NMAX << 2];
int lazy[NMAX << 2];
bool flag[NMAX << 2];

node merge(node n0, node n1){
    
    node res;
    
    res.sum = n0.sum + n1.sum;
    res.seg = max({n0.seg, n1.seg, n0.suf + n1.pre});
    res.pre = max({n0.pre, n0.sum + n1.pre});
    res.suf = max({n1.suf, n0.suf + n1.sum});
    
    return res;
}

void push(int nd, int l, int r){
    
    if(!flag[nd]) return;
    
    node tmp;
    tmp.sum = lli(r-l+1) * lazy[nd];
    tmp.seg = tmp.pre = tmp.suf = max(tmp.sum, 0LL);
    
    tree[nd] = tmp;
    
    if(l != r){
        lazy[nd*2] = lazy[nd*2+1] = lazy[nd];
        flag[nd*2] = flag[nd*2+1] = true;
    }
    
    flag[nd] = false;
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    if(l > q_r || q_l > r) return;
    
    push(nd, l, r);
    
    if(q_l <= l && r <= q_r){
        lazy[nd] = val;
        flag[nd] = true;
        return;    
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    push(nd*2, l, mid);
    push(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
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
        
        int l, r, val;
        cin >> l >> r >> val;
        
        update(1, 1, n, l+1, r, val);
        
        push(1, 1, n);
        cout << tree[1].seg << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
