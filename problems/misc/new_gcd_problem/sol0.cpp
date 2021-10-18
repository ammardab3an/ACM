
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

int n, k;
int arr[NMAX];
int tree[NMAX << 2];

void build(int nd, int l, int r){
    
    if(l == r){
        tree[nd] = arr[l];
        return;
    }    
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = __gcd(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r){
        return 0;
    }    
    
    if(q_l <= l && r <= q_r){
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return __gcd(stPath, ndPath);
}

int kk = 1000000;

int go(int pos, int k, int cgcd){
    
    if(!kk) return 0;
    kk--;
        
    if(!k){
        return __gcd(cgcd, query(1, 0, n-1, pos, n-1));
    }
    
    if(pos == n || n-pos < k){
        return 1;
    }   
    
    // int stPath = go(pos+1, k, __gcd(cgcd, arr[pos]));
    
    int l = pos+1;
    int r = n-1;
    
    int bs_ans = -1;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        int que = __gcd(cgcd, query(1, 0, n-1, pos+1, mid));
        
        if(que != cgcd){
            bs_ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    if(bs_ans == -1){
        return cgcd;    
    }
    
    int stPath = go(bs_ans, k-1, __gcd(cgcd, query(1, 0, n-1, pos+1, bs_ans-1)));
    int ndPath = go(bs_ans,  k , __gcd(cgcd, query(1, 0, n-1, pos, bs_ans-1)));
    
    return max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> arr[i];
        build(1, 0, n-1);
        cout << go(0, k, 0) << endl;
    }
}
