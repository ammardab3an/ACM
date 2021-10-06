// Problem: Multiples of 3
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/MULTQ3
// Memory Limit: 256 MB
// Time Limit: 137 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 1e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

array<int, 3> tree[NMAX << 2];
int lazy[NMAX << 2];

void push(int nd, int l, int r){
    
    lazy[nd] %= 3;
    if(!lazy[nd]) return;
    
    array<int, 3> new_node;
    for(int i = 0; i < 3; i++) 
        new_node[i] = tree[nd][(i-lazy[nd]+3)%3];
    
    tree[nd] = new_node;
    
    if(l!=r){
        lazy[nd*2] += lazy[nd];
        lazy[nd*2+1] += lazy[nd];
    }    
    
    lazy[nd] = 0;
}

void build(int nd, int l, int r){
    
    if(l==r){
        tree[nd][0] = 1;
        tree[nd][1] = tree[nd][2] = 0;
        return;
    }        
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd][0] = tree[nd*2][0] + tree[nd*2+1][0];
}

void update(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return;
    }
    
    if(q_l <= l && r <= q_r){
        lazy[nd]++;
        push(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r);
    update(nd*2+1, mid+1, r, q_l, q_r);
    
    for(int i = 0; i < 3; i++) 
        tree[nd][i] = tree[nd*2][i] + tree[nd*2+1][i];
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return 0;
    }    
    
    if(q_l <= l && r <= q_r){
        return tree[nd][0];
    }
    
    int mid = (l+r)/2;
    int st_path = query(nd*2, l, mid, q_l, q_r);
    int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return st_path + nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, q;
    cin >> n >> q;
    
    build(1, 0, n-1);
    
    while(q--){
        
        int x, l, r;
        cin >> x >> l >> r;
        
        if(x==0){
            update(1, 0, n-1, l, r);
        }
        else{
            int que = query(1, 0, n-1, l, r);
            cout << que << endl;
        }
    }
}
