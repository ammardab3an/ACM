// Problem: B. Number of Connected Components on Segments
// Contest: Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 5e4 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));
const int MAX_BLOCK = NMAX/BLOCK + 1;

struct query{
    
    int lo, hi, q_idx;
    
    bool operator < (const query &other){
        if(lo/BLOCK != other.lo/BLOCK){
            return lo/BLOCK < other.lo/BLOCK;
        }    
        return hi < other.hi;
    }
    
} que[NMAX];

pii arr[NMAX];
int par[NMAX];
int sz[NMAX];
int ans[NMAX], cans;
stack<pii> st;

int get_par(int u){
    return par[u]==u ? u : get_par(par[u]);
}

void merge(int u, int v){
    
    if((u=get_par(u)) == (v=get_par(v))){
        return;
    }    
    
    if(sz[u] > sz[v]){
        swap(u, v);
    }
    
    st.push({u, v});
    
    par[u] = v;
    sz[v] += sz[u];
    cans--;
}

bool rollback(){
    
    if(st.empty()){
        return false;
    }
    
    while(true){
        
        assert(!st.empty());
        
        pii p = st.top();
        st.pop();
        
        if(p.first == -1) break;
        
        int u = p.first;
        int v = p.second;
        
        sz[v] -= sz[u];
        par[u] = u;
        cans++;
    }    
    
    return true;
}

void persist(){
    st.push({-1, -1});    
}

void add(int i){
    int u = arr[i].first;
    int v = arr[i].second;
    merge(u, v);    
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
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        arr[i] = {u, v};
    }
    
    for(int i = 0; i < n; i++){
        sz[i] = 1;
        par[i] = i;
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++){
        
        int l, r;
        cin >> l >> r;
        l--, r--;
        
        que[i].lo = l;
        que[i].hi = r;
        que[i].q_idx = i;
    }
     
    cans = n;
    sort(que, que+q);
    int l, r, b = -1;
    
    for(int i = 0; i < q; i++){
        
        int cl = que[i].lo;
        int cr = que[i].hi;
        int ci = que[i].q_idx;
        
        if(cl/BLOCK != b){
            while(rollback());
            b = cl/BLOCK;    
            l = r = (b+1)*BLOCK;
        }
        
        if(cl/BLOCK == cr/BLOCK){
            persist();
            for(int i = cl; i <= cr; i++) add(i);
            ans[ci] = cans;
            rollback();
            continue;
        }
        
        persist();
        while(r <= cr) add(r++);
        persist();
        while(cl < l) add(--l);
        
        ans[ci] = cans;
        rollback();
        l = (b+1)*BLOCK;
    }
    
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}
