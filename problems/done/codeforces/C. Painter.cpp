// Problem: C. Painter
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int NMAX = 1e6 + 1010;

struct node{
	
    int cnt, sum, pre, suf, lazy;
    
    node(){
    	cnt = sum = pre = suf = 0;
    	lazy = -1;
    }
};

node tree[NMAX << 2];

void push(int nd, int l, int r){
	
	if(tree[nd].lazy == -1) return;
	
    tree[nd].cnt = tree[nd].lazy==0;
    tree[nd].sum = tree[nd].pre = tree[nd].suf = (r-l+1) * (tree[nd].lazy==0);
	
	if(l != r){
		tree[nd*2].lazy = tree[nd].lazy;
		tree[nd*2+1].lazy = tree[nd].lazy;
	}
	
	tree[nd].lazy = -1;
}

node merge(node n0, int l0, int r0, node n1, int l1, int r1){
    
    assert(n0.lazy == -1 && n1.lazy == -1);
    
    node res;
    
    res.sum = n0.sum + n1.sum;
    
    res.pre = n0.pre;
    if(n0.pre == (r0-l0+1)) res.pre += n1.pre;
    
    res.suf = n1.suf;
    if(n1.suf == (r1-l1+1)) res.suf += n0.suf;
    
    res.cnt = n0.cnt + n1.cnt;
    res.cnt -= (n0.suf != 0) && (n1.pre != 0);
    
    return res;
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    push(nd, l, r);
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
    	tree[nd].lazy = val;
    	push(nd, l, r);    
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = merge(tree[nd*2], l, mid, tree[nd*2+1], mid+1, r);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n = NMAX;
    
    int m; cin >> m; while(m--){
        
        char com;
        int x, l;
        cin >> com >> x >> l;
        
        x += 5e5 + 10;
        
        update(1, 1, n, x, x+l-1, com == 'W');
        
        cout << tree[1].cnt << ' ' << tree[1].sum << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
