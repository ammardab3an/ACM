// Problem: E. Narrow Components
// Contest: Codeforces - Educational Codeforces Round 126 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1661/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
const int NMAX = 5e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
char grid[3][NMAX];
int val[3][NMAX];
int par[2*NMAX];
int sz[2*NMAX];
stack<int> st;
int ans;
int _cnt[NMAX];

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
    ans++;
}
 
void _merge(int i, int j){
	for(int k = 0; k < 3; k++){
		if(grid[k][i]==grid[k][j] && grid[k][i]=='1'){
			merge(val[k][i], val[k][j]);
		}
	}
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
        ans--;
    }    
    
    return true;
}
 
void persist(){
    st.push(-1);    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < 3; i++){
    	cin >> grid[i];
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < 3; j++) if(grid[j][i]=='1'){
    	if(j && grid[j-1][i]=='1'){
    		val[j][i] = val[j-1][i];
    	}
    	else{
    		val[j][i] = cnt++;
    	}
    }
    
    for(int i = 0; i < n; i++){
    	_cnt[i] = grid[0][i]=='1';
    	for(int j = 1; j < 3; j++){
    		_cnt[i] += (grid[j][i]=='1') && (grid[j-1][i]=='0');
    	}
    }
    
    vi pre(n);
    pre[0] = _cnt[0];
    for(int i = 1; i < n; i++){
    	pre[i] = pre[i-1] + _cnt[i];
    }
    auto calc = [&](int l, int r){
    	int ret = pre[r] - pre[l] + _cnt[l];
    	return ret;
    };
    
    iota(par, par+cnt, 0);
    
    int q;
    cin >> q;
    
    vi _ans(q), vis(q);
    vector<iii> queries;
    
    for(int i = 0; i < q; i++){
    	
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	
    	if(l==r){
    		_ans[i] = _cnt[l];
    		vis[i] = true;
    		continue;
    	}
    	
    	queries.push_back({i, {l, r}});
    }
    
    int block = ceil(sqrt(double(n)));
    
    vector<vector<iii>> tmp(block);
    
    for(auto e : queries){
    	tmp[e.second.first/block].push_back(e);
    }
    
    for(int i = 0; i < block; i++){
    	
    	sort(tmp[i].begin(), tmp[i].end(), [](iii a, iii b){
    		return a.second.second < b.second.second;
    	});
    	
		int j = 0;
		while(j < tmp[i].size() && tmp[i][j].second.second < ((i+1)*block+1)) j++;
		
    	persist();
    	
    	for(int r = (i+1)*block+1; (r < n) && (j < tmp[i].size()); r++){
    		
    		_merge(r-1, r);
    		
    		while(j < tmp[i].size() && (r == tmp[i][j].second.second)){
    			
    			persist();
    			
    			int l = tmp[i][j].second.first;
    			
    			for(int k = (i+1)*block-1; k >= l; k--){
    				_merge(k, k+1);
    			}
    			
    			_ans[tmp[i][j].first] = calc(l, r) - ans;
    			vis[tmp[i][j].first] = true;
    			
    			rollback();
    			j++;
    		}
    	}
    	
    	rollback();
    }
    
    for(int i = 0; i < queries.size(); i++) if(!vis[queries[i].first]){
    	
    	int l = queries[i].second.first;
    	int r = queries[i].second.second;
    	
    	assert(r-l+1 <= block+1);
    	
    	persist();
    	
    	for(int j = l+1; j <= r; j++){
    		_merge(j-1, j);
    	}	
    	
    	_ans[queries[i].first] = calc(l, r) - ans;
    	
    	rollback();
    }
    
    for(int i = 0; i < q; i++){
    	cout << _ans[i] << endl;
    }
}