// Problem: A. Shandom Ruffle
// Contest: Codeforces - Algorithms Thread Treaps Contest
// URL: https://codeforces.com/gym/102787/problem/A
// Memory Limit: 1024 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{
	
	int val;
	int sz, priority;
	node *lf, *ri;
	
	node(){
		
	}
	
	node(int v){
		val = v;
		sz = 1;
		priority = rand(0, 1e9);
		lf = ri = nullptr;
	}
	
	void dfs(){
		if(lf) lf->dfs();
		cout << val << ' ';
		if(ri) ri->dfs();
	}
	
	void calc(){
		sz = 1;
		if(lf) sz += lf->sz;
		if(ri) sz += ri->sz;
	}
};

int size(node *nd){
	return !nd ? 0 : nd->sz;
}

pair<node*, node*> split(node *nd, int k){
		
	if(!nd) return {nullptr, nullptr};
	
	if(size(nd->lf) >= k){
		auto nxt = split(nd->lf, k);
		nd->lf = nxt.second;
		nd->calc();
		return {nxt.first, nd};
	}
	else{
		auto nxt = split(nd->ri, k - size(nd->lf) - 1);
		nd->ri = nxt.first;
		nd->calc();
		return {nd, nxt.second};
	}
}

node *merge(node *nd_l, node *nd_r){
	
	if(!nd_l) return nd_r;
	if(!nd_r) return nd_l;
	
	if(nd_l->priority < nd_r->priority){
		nd_l->ri = merge(nd_l->ri, nd_r);
		nd_l->calc();
		return nd_l;
	}	
	else{
		nd_r->lf = merge(nd_l, nd_r->lf);
		nd_r->calc();
		return nd_r;
	}
}

int32_t main(){
    
    fastIO;
	
	int n;
	cin >> n;
	
	node *nd = new node(1);
	for(int i = 2; i <= n; i++){
		nd = merge(nd, new node(i));
	}
	
	for(int i = 0; i < n; i++){
		
		int l, r;
		cin >> l >> r;
		
		if(l > r) continue;
		
		int mn = min(r-l, n-r+1);
		
		auto [nd0, nd1] = split(nd, l-1);
		auto [nd2, nd3] = split(nd1, r-l);
		auto [nd4, nd5] = split(nd2, mn);
		auto [nd6, nd7] = split(nd3, mn);
		swap(nd4, nd6);
		
		nd = merge(nd0, merge(merge(nd4, nd5), merge(nd6, nd7)));
	}
	
	nd->dfs();
	cout << endl;
}
