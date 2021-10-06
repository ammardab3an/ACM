// Problem: D. Ezzat and Grid
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
 
const int NMAX = 2 * 3e5 + 10;

pii tree[NMAX << 2];
pii lazy[NMAX << 2];
bool vis[NMAX << 2];

void push(int nd, int l, int r){
    
    if(!vis[nd]) return;
    
    tree[nd] = max(tree[nd], lazy[nd]);
    
    if(l != r){
        lazy[nd*2] = max(lazy[nd*2], lazy[nd]);
        lazy[nd*2+1] = max(lazy[nd*2+1], lazy[nd]);
        vis[nd*2] = vis[nd*2+1] = true;
    }    
    
    vis[nd] = false;
}

void update(int nd, int l, int r, int q_l, int q_r, pii val){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return;
    }
    
    if(q_l <= l && r <= q_r){
        lazy[nd] = val;
        vis[nd] = true;
        push(nd, l, r);
        return;    
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, val);
    update(nd*2+1, mid+1, r, q_l, q_r, val);
    
    tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

pii query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(r < q_l || q_r < l){
        return {0, 0};
    }
    
    if(q_l <= l && r <= q_r){
        return tree[nd];    
    }
    
    int mid = (l+r)/2;
    
    pii stPath = query(nd*2, l, mid, q_l, q_r);
    pii ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return max(stPath, ndPath);
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
    
    vi comp;
    
    vector<iii> vec(m);
    for(auto &p : vec){
    
        int i, l, r;
        cin >> i >> l >> r;
        l--, r--;
        
        comp.push_back(l);
        comp.push_back(r);
        
        p = {i, {l, r}};
    }
    
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    
    map<int, vpii> mp;
    
    for(auto &p : vec){
        p.second.first = lower_bound(comp.begin(), comp.end(), p.second.first) - comp.begin();
        p.second.second = lower_bound(comp.begin(), comp.end(), p.second.second) - comp.begin();
        mp[-p.first].push_back(p.second);    
    }
    
    vi par(n+1);
    
    pii ans = {0, 0};
    
    for(auto &p : mp){
        
        pii mx = {0, 0};
        
        for(auto pp : p.second){
            int l = pp.first;
            int r = pp.second;
            pii que = query(1, 0, comp.size()-1, l, r);
            mx = max(mx, que);
        }
        
        int x = -p.first;
        par[x] = mx.second;
        
        mx = {mx.first+1, x};
        
        ans = max(ans, mx);
        
        for(auto pp : p.second){
            int l = pp.first;
            int r = pp.second;
            update(1, 0, comp.size()-1, l, r, mx);
        }
    }
    
    set<int> st;
    for(int i = 1; i <= n; i++) st.insert(i);
    
    int cur = ans.second;
    
    while(cur > 0){
        st.erase(st.find(cur));
        cur = par[cur];
    }
    
    cout << st.size() << endl;
    for(auto i : st) cout << i << ' ' ; cout << endl;
}
