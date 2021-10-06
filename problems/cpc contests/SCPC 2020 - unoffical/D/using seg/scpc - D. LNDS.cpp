
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
char tmp_str[NMAX];
array<array<int, 10>, 10> tree[NMAX << 2];

auto merge(const array<array<int, 10>, 10> &a, const array<array<int, 10>, 10> &b){
    
    array<array<int, 10>, 10> ret = {0};
    
    for(int i = 0; i < 10; i++)
    for(int j = i; j < 10; j++)
    for(int k = i; k <= j; k++){
        ret[i][j] = max(ret[i][j], a[i][k] + b[k][j]);
    }
    
    return ret;
}

void build(int nd, int l, int r){
    
    if(l == r){
        
        int c = tmp_str[l] - '0';
        
        tree[nd].fill(array<int, 10>({0}));
        
        for(int i = 0; i <= c; i++)
        for(int j = c; j < 10; j++) tree[nd][i][j] = 1;
        
        
        return;
    }    
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

array<array<int, 10>, 10> query(int nd, int l, int r, int q_l, int q_r){
    
    if(r < q_l || q_r < l){
        return array<array<int, 10>, 10>({0});
    }
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }    
    
    int mid = (l+r)/2;
    
    auto stPath = query(nd*2, l, mid, q_l, q_r);
    auto ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return merge(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){
        
        cin >> n >> m;
        cin >> tmp_str;
        
        build(1, 0, n-1);
        
        while(m--){
            
            int l, r;
            cin >> l >> r;
            
            auto que = query(1, 0, n-1, l, r);
            
            cout << que[0][9] << endl;
        }
    }
}
