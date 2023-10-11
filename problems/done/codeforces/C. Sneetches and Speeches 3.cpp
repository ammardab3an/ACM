// Problem: C. Sneetches and Speeches 3
// Contest: Codeforces - Algorithms Thread Treaps Contest
// URL: https://codeforces.com/gym/102787/problem/C
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct s_data{
	
	array<int, 2> sum, pre, suf, ans;
	
	s_data(){
		sum=pre=suf=ans = (array<int, 2>){0, 0};
	}	
	
	s_data(array<int, 2> v){
		assert(!v[0] || !v[1]);
		sum=pre=suf=ans = v;
	}
	
};

s_data data_merge(const s_data &a, const s_data &b){
	
	s_data ret;
	
	for(int i = 0; i < 2; i++){
		ret.sum[i] = a.sum[i] + b.sum[i];
		ret.pre[i] = a.pre[i];
		ret.suf[i] = b.suf[i];
		if(!a.sum[!i]) ret.pre[i] += b.pre[i];
		if(!b.sum[!i]) ret.suf[i] += a.suf[i];
		ret.ans[i] = max({a.ans[i], b.ans[i], a.suf[i] + b.pre[i]});
	}
	
	return ret;
};

struct node{
	
	s_data data;
	array<int, 2> val;
	int sz, priority;
	bool lazy_rev, lazy_xor;
	node *lf, *ri;
	
	node(){
		assert(false);
	}
	
	node(array<int, 2> v){
		val = v;
		data = s_data(v);
		sz = val[0] + val[1];
		priority = rand(0, 1e9);
		lazy_rev = lazy_xor = 0;
		lf = ri = nullptr;
	}
	
	void push(){
		
		if(!lazy_rev && !lazy_xor) return;
		
		if(lf) lf->lazy_rev ^= lazy_rev;
		if(lf) lf->lazy_xor ^= lazy_xor;
		if(ri) ri->lazy_rev ^= lazy_rev;
		if(ri) ri->lazy_xor ^= lazy_xor;
		
		if(lazy_rev){
			swap(lf, ri);
			swap(data.pre, data.suf);
			lazy_rev = 0;
		}
		
		if(lazy_xor){
			swap(data.pre[0], data.pre[1]);
			swap(data.suf[0], data.suf[1]);
			swap(data.sum[0], data.sum[1]);
			swap(data.ans[0], data.ans[1]);
			swap(val[0], val[1]);
			lazy_xor = 0;
		}
	}
	
	void do_rev(){
		lazy_rev ^= 1;
		push();
	}
	
	void do_xor(){
		lazy_xor ^= 1;
		push();
	}
	
	void calc(){
		
		sz = val[0]+val[1];
		data = s_data(val);
		
		assert(!lazy_rev && !lazy_xor);
		
		if(lf){
			lf->push();
			sz += lf->sz;
			data = data_merge(lf->data, data);
		}
		
		if(ri){
			ri->push();
			sz += ri->sz;
			data = data_merge(data, ri->data);
		}
	}
	
	void dfs(){
		push();
		if(lf) lf->dfs();
		if(val[0]) cout << string(val[0], '0');
		if(val[1]) cout << string(val[1], '1');
		cout << '-';
		if(ri) ri->dfs();
	}
};

int size(node *nd){
	return !nd ? 0 : nd->sz;
}

node *merge(node *l, node *r){
	
	if(l) l->push();
	if(r) r->push();
	
	if(!l) return r;
	if(!r) return l;
	
	if(l->priority < r->priority){
		l->ri = merge(l->ri, r);
		l->calc();
		return l;
	}	
	else{
		r->lf = merge(l, r->lf);
		r->calc();
		return r;
	}
}

pair<node*, node*> split(node* nd, int k){
	
	if(!nd) return {nullptr, nullptr};
	
	nd->push();
	
	if(size(nd->lf) >= k){
		auto nxt = split(nd->lf, k);
		nd->lf = nxt.second;
		nd->calc();
		return {nxt.first, nd};
	}
	else if(size(nd->lf) + (nd->val[0] + nd->val[1]) >= k){
		
		int nk = k - size(nd->lf);
		array<int, 2> tmp = {0, 0};
		int mn = min(nd->val[0], nk);
		tmp[0] += mn;
		if(mn == nd->val[0]){
			mn = min(nd->val[1], nk-mn);
			tmp[1] += mn;
		}
		node *nd0 = new node(tmp);
		node *nd1 = new node({nd->val[0]-tmp[0], nd->val[1]-tmp[1]});
		
		nd0 = nd0->sz ? merge(nd->lf, nd0) : nd->lf;
		nd1 = nd1->sz ? merge(nd1, nd->ri) : nd->ri;
		
		return {nd0, nd1};
	}
	else{
		auto nxt = split(nd->ri, k - size(nd->lf) - (nd->val[0] + nd->val[1]));
		nd->ri = nxt.first;
		nd->calc();
		return {nd, nxt.second};
	}
}

array<int, 2> calc(char c){
	array<int, 2> ret = {0, 0};
	ret[c-'0'] = 1;
	return ret;	
}

int32_t main(){
    
    fastIO;

	int n, m;
	cin >> n >> m;
	
	string str;
	cin >> str;
	
	node *nd = new node(calc(str[0]));
	for(int i = 1; i < n; i++){
		nd = merge(nd, new node(calc(str[i])));
	}
	
	// nd->dfs();
	// cout << endl;
	
	while(m--){
		
		int k, l, r;
		cin >> k >> l >> r;
		l--, r--;
		
		// cout << ' ' << nd->sz << endl << flush;
		
		if(k==1){
			auto [nd0, nd1] = split(nd, l);
			auto [nd2, nd3] = split(nd1, r-l+1);
			nd2->do_xor();
			nd = merge(nd0, merge(nd2, nd3));	
		}
		else if(k==2){
			auto [nd0, nd1] = split(nd, l);
			auto [nd2, nd3] = split(nd1, r-l+1);
			nd2->do_rev();
			nd = merge(nd0, merge(nd2, nd3));	
		}
		else{
			auto [nd0, nd1] = split(nd, l);
			auto [nd2, nd3] = split(nd1, r-l+1);
			node *new_nd = merge(new node({nd2->data.sum[0], 0}), new node({0, nd2->data.sum[1]}));
			nd = merge(nd0, merge(new_nd, nd3));
		}
		
		// nd->dfs();
		// cout << endl;
		
		nd->push();
		cout << max(nd->data.ans[0], nd->data.ans[1]) << endl;
	}
}
