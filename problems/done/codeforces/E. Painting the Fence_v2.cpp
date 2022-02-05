// Problem: E - Painting the Fence
// Contest: Virtual Judge - IFHLC - 01
// URL: https://vjudge.net/contest/459578#problem/E
// Memory Limit: 262 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 3e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{
    int mn, mx, lazy;
    node(){
        mn = mx = 0;
        lazy = -1;
    }
};

node tree[NMAX << 2];
deque<int> dq[NMAX];
int arr[NMAX];

void push(int nd, int l, int r){
    
    if(tree[nd].lazy == -1) return;
    
    tree[nd].mn = tree[nd].mx = tree[nd].lazy;
    
    if(l != r){
        tree[nd*2].lazy = tree[nd*2+1].lazy = tree[nd].lazy;
    }    
    
    tree[nd].lazy = -1;
}

node merge(int a, int b){
    
    node ret;
    
    ret.mn = min(tree[a].mn, tree[b].mn);
    ret.mx = max(tree[a].mx, tree[b].mx);
    ret.lazy = -1;
    
    return ret;    
}

void update(int nd, int l, int r, int q_l, int q_r, int c){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return;
    }    
    
    if(q_l <= l && r <= q_r){
        tree[nd].lazy = c;
        return;
    }
    
    if(tree[nd].mn == c && tree[nd].mx == c){
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, c);
    update(nd*2+1, mid+1, r, q_l, q_r, c);
    
    tree[nd] = merge(nd*2, nd*2+1);
}

int query(int nd, int l, int r, int p){
    
    push(nd, l, r);
    
    if(l == r){
        return tree[nd].mn;
    }
    
    int mid = (l+r)/2;
    if(p <= mid) return query(nd*2, l, mid, p);
    return query(nd*2+1, mid+1, r, p);
}

void build(int nd, int l, int r, bool b){
    
    push(nd, l, r);
    
    if(l==r){
        
        if(b){        
            arr[l] = tree[nd].mn;
        }
        else{
            tree[nd].mn = tree[nd].mx = arr[l];
        }
        
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid, b);
    build(nd*2+1, mid+1, r, b);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        
        int ci;
        cin >> ci;
        
        dq[ci].push_back(i);
        arr[i] = ci;
    }
    
    build(1, 0, n-1, false);
    
    int m; cin >> m; while(m--){
        
        int ci;
        cin >> ci;
        
        while(dq[ci].size() && query(1, 0, n-1, dq[ci].back()) != ci){
            dq[ci].pop_back();
        }
        
        while(dq[ci].size() && query(1, 0, n-1, dq[ci].front()) != ci){
            dq[ci].pop_front();
        }
        
        if(dq[ci].size() >= 2){
            
            int l = dq[ci].front();
            int r = dq[ci].back();
            
            update(1, 0, n-1, l, r, ci);
        }
    }
    
    build(1, 0, n-1, true);
    
    for(int i = 0; i < n; i++) cout << arr[i] << ' ' ; cout << endl;
}
