// Problem: B. Inversions 2
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 1 - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B
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

// #define endl '\n'
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

void build(int nd, int l, int r){
    
    if(l == r){
        tree[nd] = 1;
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

void update(int nd, int l, int r, int q_p){
    
    if(l > q_p || q_p > r) return;
    
    if(l == r){
        tree[nd] = 0;
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_p);
    update(nd*2+1, mid+1, r, q_p);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

int query(int nd, int l, int r, int x){
    
    if(l == r) return l;
    
    int mid = (l+r)/2;
    int stPath = tree[nd*2];
    int ndPath = tree[nd*2+1];
    
    if(ndPath >= x) return query(nd*2+1, mid+1, r, x);
    else return query(nd*2, l, mid, x - ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vi ans(n);
    
    build(1, 1, n);
    
    for(int i = n-1; i >= 0; i--){
        
        int que = query(1, 1, n, arr[i]+1);
        ans[i] = que;
        update(1, 1, n, que);
    }
    
    for(auto i : ans) cout << i << ' '; cout << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
