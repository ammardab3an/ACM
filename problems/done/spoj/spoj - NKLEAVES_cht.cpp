// Problem: Leaves
// Contest: SPOJ - Partial
// URL: https://www.spoj.com/problems/NKLEAVES/en/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
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

struct Line{
	int m, b;
	int operator()(int x) {
		if(m==INFLL) return INFLL;
		return m * x + b; 
	}
};

struct node{
	
	Line ln;
	node *lf, *ri; 
	
	node(){
		ln.m = ln.b = INFLL;
		lf = ri = nullptr;
	}
	
	~node(){
		delete lf;
		delete ri;
	}
	
	void insert(int l, int r, Line seg){
		
		if(l==r){
			if(seg(l) < ln(l)){
				ln = seg;
			}
			return;
		}		
		
		int mid = (l+r)/2;
		
		if(ln.m < seg.m){
			swap(ln, seg);
		}
		
		if(ln(mid) > seg(mid)){
			swap(ln, seg);
			if(!lf) lf = new node();
			lf->insert(l, mid, seg);
		}
		else{
			if(!ri) ri = new node();
			ri->insert(mid+1, r, seg);
		}
	}
	
	void insert(Line seg){
		insert(0, 1e9, seg);
	}
	
	int query(int l, int r, int x){
		
		if(l==r){
			return ln(x);
		}	
		
		int ret = ln(x);
		int mid = (l+r)/2;
		
		if(x < mid){
			if(lf) ret = min(ret, lf->query(l, mid, x));
		}
		else{
			if(ri) ret = min(ret, ri->query(mid+1, r, x));
		}
		
		return ret;
	}
	
	int query(int x){
		return query(0, 1e9, x);
	}
};

int32_t main(){
    
    fastIO;
    
	int n, k;
	cin >> n >> k;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	if(n==0 && k==0){
		rng = mt19937(123);
		n = 1e3;
		k = 10;
		vec = vi(n);
		for(auto &i : vec) i = rand(1, 1000);
	}
	
	vi pre = vec;
	for(int i = 1; i < n; i++){
		pre[i] += pre[i-1];
	}
	
	vi pre2(n);
	for(int i = 0; i < n; i++){
		pre2[i] = i * vec[i];
		if(i) pre2[i] += pre2[i-1];
	}
	
	vi dp(n, INFLL);
	
	while(k--){
		
		node tree;
		tree.insert((Line){0, 0});
		
		for(int i = 0; i < n; i++){
			tree.insert((Line){-(i+1), dp[i]-pre2[i]+(i+1)*pre[i]});
			dp[i] = pre2[i] + tree.query(pre[i]);
		}
	}
	
	cout << dp.back() << endl;
}

// j <= i
// dp[j] + (pre2[i] - pre2[j]) - (pre[i] - pre[j]) * (j+1)
// dp[j] + pre2[i] - pre2[j] - (j+1)*pre[i] + (j+1)*pre[j]
// pre2[i] + ((dp[j]-pre2[j]+(j+1)*pre[j]) -(j+1)*pre[i])

// c = dp[j]-pre2[j]+(j+1)*pre[j]
// m = -(j+1)
// 
// a = pre2[i]
// x = pre[i]