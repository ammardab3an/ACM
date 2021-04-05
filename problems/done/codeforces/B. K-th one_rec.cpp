// Problem: B. K-th one
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B
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

int arr[NMAX];
int tree[NMAX << 2];

int merge(int a, int b){
    return a + b;
}

void build(int nd, int l, int r){
    
    if(l == r){
        tree[nd] = arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_p){
    
    if(l > q_p || r < q_p) return;
    
    if(l == q_p && r == q_p){
        tree[nd] = !tree[nd];
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_p);
    update(nd*2+1, mid+1, r, q_p);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int x){
    
    if(l == r) return l;
    
    int mid = (l+r)/2;
    int stPath = tree[nd*2];
    int ndPath = tree[nd*2+1];
    
    if(stPath >= x) return query(nd*2, l, mid, x);
    else return query(nd*2+1, mid+1, r, x - stPath);
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
        
        int k, x;
        cin >> k >> x;
        
        if(k == 1){
            update(1, 1, n, x+1);
        }
        else{
            cout << query(1, 1, n, x+1)-1 << endl;
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
