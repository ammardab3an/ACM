// Problem: Z. Trick or Treap
// Contest: Codeforces - Algorithms Thread Treaps Contest
// URL: https://codeforces.com/gym/102787/problem/Z
// Memory Limit: 1024 MB
// Time Limit: 8000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{
	
	int val;
	int sum;
	int sz, priority;
	node *lf, *ri, *par;
	
	node(){
		assert(false);
	}
	
	node(int v){
		sz = 1;
		priority = rand(0, 1e9);
		val = sum = v;
		par = lf = ri = nullptr;
	}
	
	void calc(){
		
		sz = 1;
		sum = val;
		
		if(lf){
			sz += lf->sz;
			sum += lf->sum;
		}
		
		if(ri){
			sz += ri->sz;
			sum += ri->sum;
		}
	}
};

int size(node *nd){
	return !nd ? 0 : nd->sz;
}

void set_par(node *nd, node *p){
	if(!nd) return;
	nd->par = p;
}

node* merge(node *l, node *r){
	
	if(!l) return r;
	if(!r) return l;
	
	if(l->priority < r->priority){
		node *tmp = merge(l->ri, r);
		l->ri = tmp;
		set_par(tmp, l);
		l->calc();
		return l;
	}	
	else{
		node *tmp = merge(l, r->lf);
		r->lf = tmp;
		set_par(tmp, r);
		r->calc();
		return r;
	}
}

pair<node*, node*> split(node* nd, int k){
	
	if(!nd) return {nullptr, nullptr};
	
	if(size(nd->lf) >= k){
		set_par(nd->lf, nullptr);
		auto nxt = split(nd->lf, k);
		nd->lf = nxt.second;
		set_par(nxt.second, nd);
		nd->calc();
		return {nxt.first, nd};
	}
	else{
		set_par(nd->ri, nullptr);
		auto nxt = split(nd->ri, k-size(nd->lf)-1);
		nd->ri = nxt.first;
		set_par(nxt.first, nd);
		nd->calc();
		return {nd, nxt.second};
	}
}

node *get_par(node *nd){
	if(!nd) return nullptr;
	if(!nd->par) return nd;
	return get_par(nd->par);
}

node *nds[NMAX];

int32_t main(){
    
    fastIO;
	
	int m;
	cin >> m;
	
	for(int i = 1; i <= m; i++){
		
		int k;
		cin >> k;
		
		if(k==1){
			int val;
			cin >> val;
			nds[i] = new node(val);
		}
		else if(k==2){
			
			int x, y;
			cin >> x >> y;
			node *nd0 = get_par(nds[x]);
			node *nd1 = get_par(nds[y]);
			
			if(nd0 != nd1){
				merge(nd0, nd1);
			}
		}
		else if(k==3){
			
			int z, mx_sz;
			cin >> z >> mx_sz;
			
			node *nd = get_par(nds[z]);
			
			if(size(nd) > mx_sz){
				split(nd, mx_sz);
			}
		}
		else{
			int y;
			cin >> y;
			node *nd = get_par(nds[y]);
			assert(nd);
			cout << nd->sum << endl;
		}
	}
}