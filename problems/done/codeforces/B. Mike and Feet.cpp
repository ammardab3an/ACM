// Problem: B. Mike and Feet
// Contest: Codeforces - Codeforces Round #305 (Div. 1)
// URL: https://codeforces.com/problemset/problem/547/B
// Memory Limit: 256 MB
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

int n;
int arr[NMAX];
int ans[NMAX];

struct node{
    
    int pre, suf, sum, ans;
    
    node(){
        sum = 1;
        pre = suf = ans = 0;
    }
    
} tree[NMAX << 2];

node merge(node n0, node n1){
    
    node ret;
    ret.ans = max({n0.ans, n1.ans, n0.suf + n1.pre});
    ret.pre = n0.pre == n0.sum ? n0.sum + n1.pre : n0.pre;
    ret.suf = n1.suf == n1.sum ? n0.suf + n1.sum : n1.suf;
    ret.sum = n0.sum + n1.sum;
    
    return ret;
}

void update(int nd, int l, int r, int p){
    
    if(p > r || p < l) return;
    
    if(l == r){
        auto &cnd = tree[nd];
        cnd.pre = cnd.suf = cnd.sum = cnd.ans = 1;
        return;        
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p);
    update(nd*2+1, mid+1, r, p);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    set<pii> st;
    for(int i = 0; i < n; i++) st.insert({-arr[i], i});
    
    int lst = -1;
    for(int i = 1; i <= n; i++){
        
        while(tree[1].ans < i){
            
            pii tp = *st.begin();
            st.erase(st.begin());
            lst = tp.first * -1;
            
            update(1, 1, n, tp.second+1);
        }
        
        ans[i] = lst;
    }
    
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ' ; cout << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
