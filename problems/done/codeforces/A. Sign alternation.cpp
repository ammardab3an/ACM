// Problem: A. Sign alternation
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/A
// Memory Limit: 1024 MB
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

int arr[NMAX];
int tree[NMAX << 2];

int merge(int a, int b){
    return a + b;
}

void build(int nd, int l, int r){
    
    if(l==r){
        tree[nd] = l%2==1 ? arr[l] : -arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_p, int val){
    
    if(l > q_p || q_p > r) return;
    
    if(l==r){
        tree[nd] = l%2==1 ? val : -val;
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_p, val);
    update(nd*2+1, mid+1, r, q_p, val);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return 0;
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return merge(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    build(1, 1, n);
    
    int m; cin >> m; while(m--){
        
        int k;
        cin >> k;
        
        if(k == 0){
            int p, val;
            cin >> p >> val;
            update(1, 1, n, p, val);
        }
        else{
            int l, r;
            cin >> l >> r;
            int que = query(1, 1, n, l, r);
            if(l%2==0) que *= -1;
            cout << que << endl;
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
