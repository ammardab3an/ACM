// Problem: D. Final Exam
// Contest: Codeforces - bld.ai Summer22 Internship Contest [Official]
// URL: https://codeforces.com/group/tKWnzvWA4V/contest/388002/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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

struct _2SAT {
	
	int n;
	vector<vector<int>> adj, adj_t;
	vector<bool> used;
	vector<int> order, comp;
	vector<bool> assignment;
	
	_2SAT(int _n){
		n = _n*2;
		adj.resize(n);
		adj_t.resize(n);
	}
	
	void dfs1(int v) {
	    used[v] = true;
	    for (int u : adj[v]) {
	        if (!used[u])
	            dfs1(u);
	    }
	    order.push_back(v);
	}
	
	void dfs2(int v, int cl) {
	    comp[v] = cl;
	    for (int u : adj_t[v]) {
	        if (comp[u] == -1)
	            dfs2(u, cl);
	    }
	}
	
	bool solve_2SAT() {
	    order.clear();
	    used.assign(n, false);
	    for (int i = 0; i < n; ++i) {
	        if (!used[i])
	            dfs1(i);
	    }
	
	    comp.assign(n, -1);
	    for (int i = 0, j = 0; i < n; ++i) {
	        int v = order[n - i - 1];
	        if (comp[v] == -1)
	            dfs2(v, j++);
	    }
	
	    assignment.assign(n / 2, false);
	    for (int i = 0; i < n; i += 2) {
	        if (comp[i] == comp[i + 1])
	            return false;
	        assignment[i / 2] = comp[i] > comp[i + 1];
	    }
	    return true;
	}
	
	void add_disjunction(int a, bool na, int b, bool nb) {
	    // na and nb signify whether a and b are to be negated 
	    a = 2*a ^ na;
	    b = 2*b ^ nb;
	    int neg_a = a ^ 1;
	    int neg_b = b ^ 1;
	    adj[neg_a].push_back(b);
	    adj[neg_b].push_back(a);
	    adj_t[b].push_back(neg_a);
	    adj_t[a].push_back(neg_b);
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    _2SAT st(m);
    
    for(int i = 0; i < n; i++){
    	
    	int a, b;
    	cin >> a >> b;
    	
    	bool na = a < 0;
    	bool nb = b < 0;
    	
    	a = abs(a);
    	b = abs(b);
    	a--, b--;
    	
    	st.add_disjunction(a, na, b, nb);
    }
    
    if(!st.solve_2SAT()){
    	cout << -1 << endl;
    }
    else{
    	for(auto i : st.assignment){
    		cout << i << ' ';
    	}
    	cout << endl;
    }
}
