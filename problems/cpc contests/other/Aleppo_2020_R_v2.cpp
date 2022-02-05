
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

const int NMAX = 1e5;

int n, m, b;
vector<iii> vec[NMAX+10];
int tree[(NMAX << 2) + 10];
int mem[NMAX + 10];

void update(int nd, int l, int r, int p, int v){
    
    if(p < l || r < p) return;
    
    if(l == r){
        tree[nd] = v;
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, v);
    update(nd*2+1, mid+1, r, p, v);
    
    tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return INF;
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return min(stPath, ndPath);
}

int go(int pos){
    
    if(pos == 1) return 0;
    
    int &ret = mem[pos];
    if(ret+1) return ret;
    
    int ans = go(pos-1) + b;
    
    for(auto p : vec[pos]){
        
        int w = p.first;
        int l = p.second.first;
        int r = p.second.second;
        
        int que = query(1, 1, NMAX, l, r);
        ans = min(ans, que + w);
    }
    
    update(1, 1, NMAX, pos, ans);
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n >> m >> b;
        
        for(int i = 0; i < m; i++){
            int p, l, r, w;
            cin >> l >> r >> p >> w;
            vec[p].push_back({w, {l, r}});
        }
        
        memset(mem, -1, sizeof mem);
        
        cout << go(n) << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
