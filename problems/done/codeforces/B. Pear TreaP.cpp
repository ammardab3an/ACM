// Problem: B. Pear TreaP
// Contest: Codeforces - Algorithms Thread Treaps Contest
// URL: https://codeforces.com/gym/102787/problem/B
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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

const int NMAX = 1e6 + 10;

const int pp = 1e9 + 9;
const int mm = 31;

int pow_m[NMAX];

void init_hash(){
	pow_m[0] = 1;
	for(int i = 1; i < NMAX; i++){
		pow_m[i] = (pow_m[i-1] * mm) % pp;
	}
}

int hash_merge(int lf, int ri, int sz_lf){
	return (lf + (ri*pow_m[sz_lf])%pp) % pp;
}

struct node{

	array<int, 2> val, sm;
	int sz, priority;
	node *lf, *ri;

	node(){

	}

	node(char c){
		val = {c-'a'+1, c-'a'+1};
		sm = val;
		sz = 1;
		priority = rand(0, 1e9);
		lf = ri = nullptr;
	}

	// ~node(){
		// delete lf;
		// delete ri;
	// }

	void calc(){
		sz = 1;
		sm = val;
		if(lf){
			sm[0] = hash_merge(lf->sm[0], val[0], lf->sz);
			sm[1] = hash_merge(val[1], lf->sm[1], 1);
			sz += lf->sz;
		}
		if(ri){
			sm[0] = hash_merge(sm[0], ri->sm[0], sz);
			sm[1] = hash_merge(ri->sm[1], sm[1], ri->sz);
			sz += ri->sz;
		}
	}

	void dfs(){
		if(lf) lf->dfs();
		cout << char('a' + val[0]-1);
		if(ri) ri->dfs();
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

node *merge(node *l, node *r){

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

int32_t main(){

    fastIO;

	init_hash();

    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    node *nd = new node(str[0]);
    for(int i = 1; i < n; i++){
    	nd = merge(nd, new node(str[i]));
    }

    while(m--){

    	int k;
    	cin >> k;

    	if(k==1){
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		auto [nd0, nd1] = split(nd, l);
    		auto [nd2, nd3] = split(nd1, r-l+1);
    		nd = merge(nd0, nd3);
    	}
    	else if(k==2){

    		char c;
    		int p;
    		cin >> c >> p;

    		auto [nd0, nd1] = split(nd, p-1);
    		nd = merge(nd0, merge(new node(c), nd1));
    	}
    	else{
    		int l, r;
    		cin >> l >> r;
    		l--, r--;

    		auto [nd0, nd1] = split(nd, l);
    		auto [nd2, nd3] = split(nd1, r-l+1);

    		bool ans = nd2->sm[0] == nd2->sm[1];
    		cout << (ans ? "yes" : "no") << endl;

    		nd = merge(nd0, merge(nd2, nd3));
    	}

    	// nd->dfs();
    	// cout << endl;
    }
}
