// Problem: C. Till I Collapse
// Contest: Codeforces - Codeforces Round #406 (Div. 1)
// URL: https://codeforces.com/problemset/problem/786/C
// Memory Limit: 256 MB
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

struct node{
	int sum;
	node *lf, *ri;
	node(){
		sum = 0;
		lf=ri = this;
	}
	node(int sum, node *lf, node *ri):
		sum(sum), lf(lf), ri(ri) {}
};

node *null = new node();
node *rts[NMAX];

node *update(node *rt, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return rt;
	}	
	
	if(l==r){
		return new node(rt->sum+val, null, null);
	}
	
	int mid = (l+r)/2;
	node *nlf = update(rt->lf, l, mid, p, val);
	node *nri = update(rt->ri, mid+1, r, p, val);
	
	return new node(rt->sum+val, nlf, nri);
}

int query(node *rt, int l, int r, int k){
	
	if(rt->sum <= k){
		return r+1;
	}	
	
	if(l==r){
		return r;	
	}
	
	int mid = (l+r)/2;
	if(rt->lf->sum > k){
		return query(rt->lf, l, mid, k);
	}
	else{
		return query(rt->ri, mid+1, r, k-(rt->lf->sum));
	}
}

int n;
int arr[NMAX];
int lst[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	arr[i]--;
    }
    
    memset(lst, -1, sizeof lst);
    
    rts[n] = new node();
    for(int i = n-1; i >= 0; i--){
    	
    	rts[i] = rts[i+1];
    	
    	if(lst[arr[i]]!=-1){
    		rts[i] = update(rts[i], 0, n-1, lst[arr[i]], -1);
    	}
    	
		rts[i] = update(rts[i], 0, n-1, i, +1);
    	
    	lst[arr[i]] = i;
    }
    
    for(int i = 1; i <= n; i++){
    	
    	int p = 0;
    	int cans = 0;
    	while(p < n){
    		cans++;
    		p = query(rts[p], 0, n-1, i);
    	}
    	cout << cans << ' ';
    }
    cout << endl;
}
