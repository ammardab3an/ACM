// Problem: A. Queries
// Contest: Codeforces - KTU Programming Camp (Day 3)
// URL: https://codeforces.com/gym/100739/problem/A
// Memory Limit: 128 MB
// Time Limit: 2250 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
const int MOD = 4001; // 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e5 + 10;

struct node{
    int Xor;
    int l[2], r[2], sm[2];    
    node(){
        Xor = 0;
        l[0] = l[1] = r[0] = r[1] = sm[0] = sm[1] = 0;
    }
};

int arr[NMAX];
node tree[10][NMAX << 2];

node merge(const node &nd_l, const node &nd_r){
    
    node cur;
    
    cur.Xor  = nd_l.Xor ^ nd_r.Xor;
    
    cur.l[0] = add(nd_l.l[0], nd_r.l[nd_l.Xor==0 ? 0 : 1]);
    cur.l[1] = add(nd_l.l[1], nd_r.l[nd_l.Xor==1 ? 0 : 1]);
    cur.r[0] = add(nd_r.r[0], nd_l.r[nd_r.Xor==0 ? 0 : 1]);
    cur.r[1] = add(nd_r.r[1], nd_l.r[nd_r.Xor==1 ? 0 : 1]);
    
    cur.sm[0] = (nd_l.sm[0] + nd_r.sm[0] + nd_l.r[0] * nd_r.l[0] + nd_l.r[1] * nd_r.l[1]) % MOD;
    cur.sm[1] = (nd_l.sm[1] + nd_r.sm[1] + nd_l.r[1] * nd_r.l[0] + nd_l.r[0] * nd_r.l[1]) % MOD;
    
    return cur;
}

void build(int bit, int nd, int l, int r){
    
    if(l == r){
        node &cur = tree[bit][nd];
        int v = (arr[l]>>bit)&1;
        cur.Xor = v;
        cur.l[v] = cur.r[v] = cur.sm[v] = 1;
        v ^= 1;
        cur.l[v] = cur.r[v] = cur.sm[v] = 0;
        return;
    }   
    
    int mid = (l+r)/2;
    build(bit, nd*2, l, mid);
    build(bit, nd*2+1, mid+1, r);
    
    tree[bit][nd] = merge(tree[bit][nd*2], tree[bit][nd*2+1]);
}

void update(int bit, int nd, int l, int r, int p, int v){
    
    if(p < l || r < p){
        return;
    }
    
    if(l == r){
        node &cur = tree[bit][nd];
        cur.Xor = v;
        cur.l[v] = cur.r[v] = cur.sm[v] = 1;
        v ^= 1;
        cur.l[v] = cur.r[v] = cur.sm[v] = 0;
        return;
    }    
    
    int mid = (l+r)/2;
    update(bit, nd*2, l, mid, p, v);
    update(bit, nd*2+1, mid+1, r, p, v);
    
    tree[bit][nd] = merge(tree[bit][nd*2], tree[bit][nd*2+1]);
}

node query(int bit, int nd, int l, int r, int q_l, int q_r){
    
    if(r < q_l || q_r < l){
        return node();
    }    
    
    if(q_l <= l && r <= q_r){
        return tree[bit][nd];
    }
    
    int mid = (l+r)/2;
    node stPath = query(bit, nd*2, l, mid, q_l, q_r);
    node ndPath = query(bit, nd*2+1, mid+1, r, q_l, q_r);
    
    return merge(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int j = 0; j < 10; j++){
        build(j, 1, 0, n-1);
    }
    
    while(m--){
        
        int k;
        cin >> k;
        
        if(k == 1){
            
            int p, x;
            cin >> p >> x;
            p--;
            
            for(int j = 0; j < 10; j++){
                update(j, 1, 0, n-1, p, x&1);
                x >>= 1;
            }
        }
        else{
            
            int l, r;
            cin >> l >> r;    
            l--, r--;
            
            int ans = 0;
            
            for(int j = 0; j < 10; j++){
                node que = query(j, 1, 0, n-1, l, r);
                ans = add(ans, que.sm[1] << j);
            }
            
            cout << ans << endl;
        }
    }
}
