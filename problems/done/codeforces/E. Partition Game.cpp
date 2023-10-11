// Problem: E. Partition Game
// Contest: Codeforces - Codeforces Round 721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int NMAX = 35000 + 10;

struct node{
	
	int sm;
	node *lf, *ri;	
	
	node(){
		sm = 0;
		lf = ri = this;
	}	
	
	node(int val) : node() {
		sm = val;
	}
	
	node(int sm, node *lf, node *ri) : sm(sm), lf(lf), ri(ri) { }
	
	node *update(int l, int r, int p, int val){
		
		if(p < l || r < p){
			return this;
		}
		
		if(l==r){
			return new node(val);
		}
		
		int mid = (l+r)/2;
		
		if(!lf) lf = new node();
		if(!ri) ri = new node();
		node *nlf = lf->update(l, mid, p, val);
		node *nri = ri->update(mid+1, r, p, val);
		
		return new node((nlf->sm)+(nri->sm), nlf, nri);
	}
	
	int query(int l, int r, int q_l, int q_r){
		
		if(r < q_l || q_r < l){
			return 0;
		}	
		
		if(q_l <= l && r <= q_r){
			return sm;
		}
		
		int mid = (l+r)/2;
		int st_path = !lf ? 0 : lf->query(l, mid, q_l, q_r);
		int nd_path = !ri ? 0 : ri->query(mid+1, r, q_l, q_r);
		
		return st_path + nd_path;
	}
	
	void dfs(int l, int r, vi &vec){
		
		if(l==r){
			if(sm) vec.push_back(sm);
			return;
		}
		
		int mid = (l+r)/2;
		if(lf) lf->dfs(l, mid, vec);
		if(ri) ri->dfs(mid+1, r, vec);
	}
};

int n, k;
int arr[NMAX];
int ans[101][NMAX];
node *pre[NMAX];
node *suf[NMAX];
int nxt[NMAX];
int cnt;

int calc(int l, int r){
	cnt++;
	int ret = 0;
	ret += pre[r]->query(0, n-1, l, r);
	ret -= suf[l]->query(0, n-1, l, r);
	return ret;
}

void go(int k, int i, int j, int l, int r){
	
	if(i > j){
		return;
	}
	
	int mid = (i+j)/2;
	
	int mr = min(r, mid);
	int cur_calc = calc(mr, mid);
	pii cans = {cur_calc + (mr ? (k ? ans[k-1][mr-1] : INFLL) : 0), mr};
	
	for(int m = mr-1; m >= l; m--){
		if(nxt[m] <= mid) cur_calc += nxt[m]-m;
		cans = min(cans, {cur_calc + (m ? (k ? ans[k-1][m-1] : INFLL) : 0), m});
	}
	
	ans[k][mid] = cans.first;
	
	int opt = cans.second;
	go(k, i, mid-1, l, opt);
	go(k, mid+1, j, opt, r);
}

int32_t main(){
    
    fastIO;
    
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	if(n==0){
		rng = mt19937(123);
		n = 35000;
		k = 100;
		for(int i = 0; i < n; i++){
			arr[i] = rand(1, n);
		}	
	}
	
	{
		vi lst(n+1, -1);
		node *rt = new node();
		
		for(int i = 0; i < n; i++){
			
			int v = arr[i];
			
			if(lst[v] != -1){
				rt = rt->update(0, n-1, lst[v], 0);
			}
			
			lst[v] = i;
			rt = rt->update(0, n-1, i, i);
			
			// vi tmp;
			// rt->dfs(0, n-1, tmp);
			// cout << i << ' ' << v << " - "; 
			// for(auto e : tmp) cout << e << ' '; cout << endl;
			
			pre[i] = rt;
		}
	}
	{
		vi lst(n+1, -1);
		node *rt = new node();
		
		for(int i = n-1; i >= 0; i--){
			
			int v = arr[i];
			
			if(lst[v] != -1){
				rt = rt->update(0, n-1, lst[v], 0);
			}
			
			lst[v] = i;
			rt = rt->update(0, n-1, i, i);
			
			// vi tmp;
			// rt->dfs(0, n-1, tmp);
			// cout << i << ' ' << v << " - "; 
			// for(auto e : tmp) cout << e << ' '; cout << endl;
			
			suf[i] = rt;
		}
	}
	
	{
		vi lst(n+1, -1);
		for(int i = n-1; i >= 0; i--){
			nxt[i] = n;
			if(lst[arr[i]] != -1) nxt[i] = lst[arr[i]];
			lst[arr[i]] = i;
		}
	}
	
	for(int i = 0; i < k; i++){
		go(i, 0, n-1, 0, n-1);
	}
	
	cout << ans[k-1][n-1] << endl;
	cerr << cnt << endl;
}
