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

vpii tree[NMAX << 2];
int par[NMAX];
int sz[NMAX];
stack<int> st;
int ans;
int _ans[NMAX];

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

void update(int nd, int l, int r, int q_l, int q_r, pii edge){
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		tree[nd].push_back(edge);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, edge);
	update(nd*2+1, mid+1, r, q_l, q_r, edge);
}

void go(int nd, int l, int r){
	
	persist();
	
	for(auto [u, v] : tree[nd]){
		merge(u, v);	
	}
	
	if(l == r){
		_ans[l] = ans;
		rollback();
		return;
	}	
	
	int mid = (l+r)/2;
	go(nd*2, l, mid);
	go(nd*2+1, mid+1, r);
	
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
    int sz = 0;
    map<pii, int> mp;
    
    for(int i = 0; i < q; i++){
        
        char c;
        cin >> c;
        
        if(c=='?'){
        	sz++;
        }
        else if(c=='+'){
            
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            u--, v--;
            
            mp[{u, v}] = sz;
        }
        else if(c=='-'){
            
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            u--, v--;
            
            auto it = mp.find({u, v});
            
            int l = it->second;
            int r = sz-1;
            
            if(l <= r){
            	update(1, 0, NMAX-1, l, r, (pii){u, v});
            }
            
            mp.erase(it);
        }
    }
    
    for(auto p : mp){
    	
    	pii edge = p.first;
    	int l = p.second;
    	int r = sz-1;
    	
    	if(l <= r){		
	    	update(1, 0, NMAX-1, l, r, edge);	
    	}
    }
    
    mp.clear();
    
    go(1, 0, NMAX-1);
    for(int i = 0; i < sz; i++){
    	cout << _ans[i] << endl;
    }
}
    