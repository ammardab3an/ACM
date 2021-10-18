// Gorgeous Sequence
// http://acm.hdu.edu.cn/showproblem.php?pid=5306
// seg tree beats - task 1

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

const int NMAX = 1e6 + 10;

struct node{
    ll sum;
    int max, sec, cnt;
};

int arr[NMAX];
node tree[NMAX << 2];

inline node merge(const node &a, const node &b){
    
    node ret;
    ret.sum = a.sum + b.sum;
    
    if(a.max == b.max){
        ret.max = a.max;
        ret.cnt = a.cnt + b.cnt;
        ret.sec = max(a.sec, b.sec);
    }    
    else if(a.max > b.max){
        ret.max = a.max;
        ret.cnt = a.cnt;
        ret.sec = max(a.sec, b.max);
    }
    else{
        ret.max = b.max;
        ret.cnt = b.cnt;
        ret.sec = max(a.max, b.sec);
    }
    
    return ret;
}

void push(int nd, int l, int r){
    
    if(tree[nd].max < tree[nd*2].max){
        tree[nd*2].sum -= 1ll * (tree[nd*2].max - tree[nd].max) * tree[nd*2].cnt;
        tree[nd*2].max = tree[nd].max;
    }
    
    if(tree[nd].max < tree[nd*2+1].max){
        tree[nd*2+1].sum -= 1ll * (tree[nd*2+1].max - tree[nd].max) * tree[nd*2+1].cnt;
        tree[nd*2+1].max = tree[nd].max;
    }
}

void build(int nd, int l, int r){
    
    if(l==r){
        node &_nd = tree[nd];
        _nd.cnt = 1;
        _nd.sum = _nd.max = arr[l];
        _nd.sec = -1;
        return;
    }    
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int x){
    
    if(r < q_l || q_r < l || tree[nd].max <= x){
        return;
    }    
    
    if(q_l <= l && r <= q_r && tree[nd].sec < x){
        tree[nd].sum -= 1ll * (tree[nd].max - x) * tree[nd].cnt;
        tree[nd].max = x;
        return;
    }
    
    push(nd, l, r);
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, x);
    update(nd*2+1, mid+1, r, q_l, q_r, x);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

pll query(int nd, int l, int r, int q_l, int q_r){
    
    if(r < q_l || q_r < l){
        return {0, 0};
    }    
    
    if(q_l <= l && r <= q_r){
        return {tree[nd].max, tree[nd].sum};
    }
    
    push(nd, l, r);
    
    int mid = (l+r)/2;
    auto st_path = query(nd*2, l, mid, q_l, q_r);
    auto nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return {max(st_path.first, nd_path.first), st_path.second + nd_path.second};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n, m;
        cin >> n >> m;
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        build(1, 0, n-1);
        
        while(m--){
            
            int k;
            cin >> k;
            
            if(k==0){
                int l, r, x;
                cin >> l >> r >> x;
                l--, r--;
                update(1, 0, n-1, l, r, x);
            }
            else{
                int l, r;
                cin >> l >> r;
                l--, r--;
                pll que = query(1, 0, n-1, l, r);
                cout << (k==1 ? que.first : que.second) << endl;
            }
        }
    }
}
