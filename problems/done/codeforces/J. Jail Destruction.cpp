
// J - Jail Destruction
// https://codeforces.com/gym/102307/problem/J

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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, q;
int arr[NMAX];

struct node{
    int sm, mx, mn, lazy, cnt_zero, flag;
    
}tree[NMAX << 2];

void push(int nd, int l, int r){
    
    if(tree[nd].lazy == 0 || tree[nd].flag){
        // tree[nd].lazy = 0;
        return;
    }    
    
    auto &_nd = tree[nd];
    
    if(l==r){
        
        int v = max(int(0), _nd.sm - _nd.lazy);
        
        if(_nd.sm == 0){
            _nd = (node){0, 0, 0, 0, 1, true};
        }
        else{
            _nd = (node){v, v, v, 0, 0, false};
        }
    }
    else{
    
        if(tree[nd*2].flag==0) 
            tree[nd*2].lazy += _nd.lazy;
        if(tree[nd*2+1].flag==0)
            tree[nd*2+1].lazy += _nd.lazy;    
        
        if(_nd.mn >= _nd.lazy){
            _nd.mn = _nd.mn - _nd.lazy;
            _nd.mx = _nd.mx - _nd.lazy;
            _nd.sm = _nd.sm - _nd.lazy * (r-l+1 - _nd.cnt_zero);
            _nd.lazy = 0;    
        }
        else if(_nd.mx <= _nd.lazy){
            _nd = (node){0, 0, 0, 0, r-l+1, true};
        }   
        else{
            assert(false);
        }
    }
}

node merge(const node &a, const node &b){
    
    assert(a.lazy==0 && b.lazy==0);
    
    if(a.flag && b.flag){
        return (node){0, 0, 0, 0, a.cnt_zero+b.cnt_zero, true};
    }
    if(a.flag){
        node ret = b;
        ret.cnt_zero += a.cnt_zero;
        return ret;
    }
    else if(b.flag){
        node ret = a;
        ret.cnt_zero += b.cnt_zero;
        return ret;
    }
    
    node ret;
    ret.sm = a.sm + b.sm;
    ret.mn = min(a.mn, b.mn);
    ret.mx = max(a.mx, b.mx);
    ret.cnt_zero = a.cnt_zero + b.cnt_zero;
    ret.lazy = ret.flag = 0;
    
    return ret;
}

void build(int nd, int l, int r){
    
    if(l == r){
        auto &_nd = tree[nd];
        _nd.sm = _nd.mx = _nd.mn = arr[l];
        _nd.flag = _nd.cnt_zero = arr[l]==0;
        _nd.lazy = 0;
        return;
    }    
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    push(nd, l, r);
    
    if(q_r < l || r < q_l || tree[nd].flag){
        return;
    }    
    
    if(q_l <= l && r <= q_r && (tree[nd].mn >= val || tree[nd].mx <= val) ){
        tree[nd].lazy = val;
        push(nd, l, r);
        return;    
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(q_r < l || r < q_l){
        return (node){0, 0, 0, 0, 0, true};
    }    
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    node st_path = query(nd*2, l, mid, q_l, q_r);
    node nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return merge(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    build(1, 0, n-1);
    
    while(q--){
        
        int ty;
        cin >> ty;
        
        if(ty == 1){
            
            int a, b;
            cin >> a >> b;
            a--, b--;
            
            if(a <= b){
                node que = query(1, 0, n-1, a, b);
                cout << que.sm << endl;
            }
            else{
                node st_path = query(1, 0, n-1, a, n-1);
                node nd_path = query(1, 0, n-1, 0, b);
                node que = merge(st_path, nd_path);
                cout << que.sm << endl;
            }
        }    
        else{
            
            int a, b, val;
            cin >> a >> b >> val;
            a--, b--;
            
            if(a <= b){
                update(1, 0, n-1, a, b, val);
            }
            else{
                update(1, 0, n-1, a, n-1, val);
                update(1, 0, n-1, 0, b, val);
            }
        }
        
        // for(int i = 0; i < n; i++){
            // cout << query(1, 0, n-1, i, i).sm << ' ';
        // } cout << endl; 
    }
}
