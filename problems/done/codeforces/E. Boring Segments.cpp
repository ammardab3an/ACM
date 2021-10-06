
// Problem: E. Boring Segments
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int NMAX = 1e6 + 10;

int tree[NMAX << 2];
int lazy[NMAX << 2];

void push(int nd, int l, int r){
    
    if(!lazy[nd]) return;
    
    tree[nd] = max(int(0), tree[nd] + lazy[nd]);
    
    if(l < r){
        lazy[nd*2] += lazy[nd];
        lazy[nd*2+1] += lazy[nd];
    }
    
    lazy[nd] = 0;
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return;
    }       
    
    if(q_l <= l && r <= q_r){
        lazy[nd] += val;
        push(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = min(tree[nd*2], tree[nd*2+1]);
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
    
    m--;
    
    vector<iii> vec(n);
    for(auto &p : vec){    
        cin >> p.second.first >> p.second.second >> p.first;
        p.second.second--;
    }
    
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    
    int ans = INF;
    
    int r = 0;
    for(int l = 0; l < n; l++){
        
        if(l){
            update(1, 1, m, vec[l-1].second.first, vec[l-1].second.second, -1);
        }
        
        while((r < n) && (tree[1] < 1)){
            update(1, 1, m, vec[r].second.first, vec[r].second.second, +1);
            r++;
        }
        
        if(tree[1] > 0){
            int mx = vec[l].first;
            int mn = l==r ? mx : vec[r-1].first;
            ans = min(ans, mx-mn);
        }
    }
    
    cout << ans << endl;
}