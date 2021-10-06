// Problem: B. Add Arithmetic Progression On Segment
// Contest: Codeforces - ITMO Academy: pilot course - Segment Tree, part 2 - Step 4
// URL: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B
// Memory Limit: 256 MB
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

int tree_add[NMAX << 2];
pii tree_pro[NMAX << 2];

void update(int nd, int l, int r, int q_l, int q_r, int a, int b){
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
        tree_add[nd] += a;
        tree_pro[nd].first += b;
        tree_pro[nd].second += q_l * b;
        return;
    }    
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, a, b);
    update(nd*2+1, mid+1, r, q_l, q_r, a, b);
}


int query(int nd, int l, int r, int p){
    
    if(l > p || p > r) return 0;
    
    int ret = 0;
    
    ret += tree_add[nd];
    ret += tree_pro[nd].first * p;
    ret -= tree_pro[nd].second;
    
    if(l == r) return ret;
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, p);
    int ndPath = query(nd*2+1, mid+1, r, p);
    
    return ret + stPath + ndPath;
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
            
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            update(1, 1, n, l, r, a, b);
        }
        else{
            int p;
            cin >> p;
            cout << query(1, 1, n, p) << endl;
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
