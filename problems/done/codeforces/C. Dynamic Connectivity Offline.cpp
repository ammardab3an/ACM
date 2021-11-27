// Problem: C. Dynamic Connectivity Offline
// Contest: Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 3e5 + 10;

int par[NMAX];
int sz[NMAX];
stack<int> st;
int ans;

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
    
    st.push(u);
    
    par[u] = v;
    sz[v] += sz[u];
    ans--;
}

bool rollback(){
    
    if(st.empty()){
        return false;
    }
    
    while(true){
        
        assert(!st.empty());
        
        int u = st.top();
        st.pop();
        
        if(u == -1) break;
        
        sz[par[u]] -= sz[u];
        par[u] = u;
        ans++;
    }    
    
    return true;
}

void persist(){
    st.push(-1);    
}

struct query{
    int ty;
    int u, v;
    int l, r;
};

void go(int l, int r, const vector<query> &vec){
    
    if(l==r){
        persist();
        for(auto q : vec){
            if(q.ty==1 && q.l <= l && r <= q.r){
                merge(q.u, q.v);
            }   
        }
        for(auto q : vec){
            if(q.ty==0 && q.l==l){
                cout << ans << endl;
            }
        }
        rollback();
        return;
    }    
    
    persist();
    vector<query> nvec;
    
    for(auto q : vec){
        
        if(q.ty==0 && (l <= q.l && q.l <= r)){
            nvec.push_back(q);
        }
        else if(q.ty==1){
            if(q.l <= l && r <= q.r){
                merge(q.u, q.v);
            }
            else if(!(q.r < l || r < q.l)){
                nvec.push_back(q);
            }
        }
    }
    
    int mid = (l+r)/2;
    go(l, mid, nvec);
    go(mid+1, r, nvec);
    rollback();
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
    
    if(!q) return 0;
    
    for(int i = 0; i < n; i++){
        sz[i] = 1;
        par[i] = i;
    }
    
    ans = n;
    map<pii, int> mp;
    vector<query> vec;
    
    for(int i = 0; i < q; i++){
        
        char c;
        cin >> c;
        
        if(c=='?'){
            query que;
            que.ty = 0;
            que.l = que.r = i;
            vec.push_back(que);
        }
        else if(c=='+'){
            
            query que;
            que.ty = 1;
            cin >> que.u >> que.v;
            if(que.u > que.v) swap(que.u, que.v);
            que.u--, que.v--;
            
            mp[{que.u, que.v}] = vec.size();
            
            que.l = i, que.r = q;
            vec.push_back(que);
        }
        else if(c=='-'){
            
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            u--, v--;
            
            vec[mp[{u, v}]].r = i-1;
        }
    }
    
    mp.clear();
    
    go(0, q-1, vec);
}
    