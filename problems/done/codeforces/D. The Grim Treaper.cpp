// Problem: D. The Grim Treaper
// Contest: Codeforces - Algorithms Thread Treaps Contest
// URL: https://codeforces.com/gym/102787/problem/D
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
	
	int sum, max, sec, cnt;
	
	s_data(){
		sum = max = sec = cnt = 0;
	}
	
	s_data(int v){
		sum = max = v;
		sec = -1;
		cnt = 1;
	}
};

s_data merge(const s_data &a, const s_data &b){
	
	s_data ret;
	
	ret.sum = a.sum + b.sum;
	
	if(a.max > b.max){
		ret.max = a.max;
		ret.cnt = a.cnt;
		ret.sec = max(a.sec, b.max);
	}
	else if(a.max < b.max){
		ret.max = b.max;
		ret.cnt = b.cnt;
		ret.sec = max(b.sec, a.max);
	}
	else{
		ret.max = a.max;
		ret.cnt = a.cnt + b.cnt;
		ret.sec = max(a.sec, b.sec);
	}
	
	if(!(ret.max > ret.sec)) exit(300);
	
	return ret;
}

struct node{
	
	int val;
	s_data data;
	int sz, priority;
	int lazy;
	node *lf, *ri;
	
	node(){
		exit(100);
		// assert(false);
	}		
	
	node(int v){
		val = v;
		data = s_data(v);
		sz = 1;
		priority = rand(0, 1e9);
		lf = ri = nullptr;
		lazy = 0;
	}
	
	void fix(){
		
		if(lf && lf->lazy) lf->push(false);
		if(ri && ri->lazy) ri->push(false);
		
		if(lf && (data.max < lf->data.max)){
			if(lf->lazy) exit(301);
			if(!(lf->data.sec < data.max)) exit(101);
			lf->data.sum -= (lf->data.max - data.max) * lf->data.cnt;
			lf->val = min(lf->val, data.max);
			lf->data.max = data.max;
		}	
		if(ri && (data.max < ri->data.max)){
			if(ri->lazy) exit(302);
			if(!(ri->data.sec < data.max)) exit(102);
			ri->data.sum -= (ri->data.max - data.max) * ri->data.cnt;
			ri->val = min(ri->val, data.max);
			ri->data.max = data.max;
		}
	}
	
	void push(bool b = true){
		if(b) fix();
		if(!lazy) return;
		if(lf) lf->lazy += lazy;
		if(ri) ri->lazy += lazy;
		val += lazy;
		data.max += lazy;
		data.sec += lazy;
		data.sum += lazy * sz;
		lazy = 0;
	}
	
	void calc(){
		
		if(lazy) exit(103);
		// assert(!lazy);
		
		sz = 1;
		data = s_data(val);
		
		if(lf){
			lf->push();
			sz += lf->sz;
			data = merge(data, lf->data);
		}
		
		if(ri){
			ri->push();
			sz += ri->sz;
			data = merge(data, ri->data);
		}
	}
};

int size(node *nd){
	return !nd ? 0 : nd->sz;
}

node* merge(node *l, node *r){
	
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

pair<node*, node*> split(node *nd, int k){
	
	if(!nd) return {nullptr, nullptr};
	
	nd->push();
	
	if(size(nd->lf) >= k){
		auto nxt = split(nd->lf, k);
		nd->lf = nxt.second;
		nd->calc();
		return {nxt.first, nd};
	}
	else{
		auto nxt = split(nd->ri, k-size(nd->lf)-1);
		nd->ri = nxt.first;
		nd->calc();
		return {nd, nxt.second};
	}
}

void update(node *nd, int h){
	
	if(!nd) return;
	
	nd->push();
	
	if(nd->val > h){
		nd->val = h;
		nd->calc();
	}
	
	if(nd->data.max <= h){
		return;
	}	
	
	if(nd->data.sec < h){
		nd->data.sum -= (nd->data.max - h) * (nd->data.cnt);
		nd->data.max = h;
		return;
	}
	
	update(nd->lf, h);
	update(nd->ri, h);
	nd->calc();
}

int32_t main(){
    
    fastIO;
	
	int n, m;
	cin >> n >> m;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	node *nd = new node(vec[0]);
	for(int i = 1; i < n; i++){
		nd = merge(nd, new node(vec[i]));
	}
	
	while(m--){
		
		int k;
		cin >> k;
		
		if(k==1){
			
			int l, r, h;
			cin >> l >> r >> h;
			l--, r--;
			
			auto [nd0, nd1] = split(nd, l);
			auto [nd2, nd3] = split(nd1, r-l+1);
			update(nd2, h);
			nd = merge(nd0, merge(nd2, nd3));	
		}
		else if(k==2){
			
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			auto [nd0, nd1] = split(nd, l);
			auto [nd2, nd3] = split(nd1, r-l+1);
			nd = merge(nd0, merge(nd3, nd2));
		}
		else{
			
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			
			auto [nd0, nd1] = split(nd, l);
			auto [nd2, nd3] = split(nd1, r-l+1);
			
			if(!nd2) exit(200);
			nd2->lazy += x;
			nd2->push();
			
			nd = merge(nd0, merge(nd2, nd3));
		}
		
		cout << (nd->data.sum) << endl;
	}
}
