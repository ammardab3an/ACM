// Problem: E. Swap and Maximum Block
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
const int NMAX = (1<<18) + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

struct node{
	int pre, suf, sum, ans;	
};

node merge(const node &a, const node &b){
	
	node ret;
	ret.sum = a.sum + b.sum;
	ret.pre = max(a.pre, a.sum + b.pre);
	ret.suf = max(b.suf, a.suf + b.sum);
	ret.ans = max({a.ans, b.ans, a.suf+b.pre});
	
	return ret;
}

int arr[NMAX];
vector<node> tree[NMAX << 2];

void build(int nd, int l, int r, int b){
	
	if(l==r){
		int tt = max(arr[l], 0ll);
		tree[nd].push_back((node){tt, tt, arr[l], tt});
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid, b-1);
	build(nd*2+1, mid+1, r, b-1);
	
	for(int x = 0; x < (1<<(b-1)); x++){
		node a = tree[nd*2][x];
		node b = tree[nd*2+1][x];
		tree[nd].push_back(merge(a, b));
	}
	
	for(int x = 0; x < (1<<(b-1)); x++){
		node a = tree[nd*2][x];
		node b = tree[nd*2+1][x];
		tree[nd].push_back(merge(b, a));
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n;
	cin >> n;
	
	for(int i = 0; i < (1<<n); i++){
		cin >> arr[i];
	}
	
	build(1, 0, (1<<n)-1, n);
	
	int x = 0;
	int q; cin >> q; while(q--){
		
		int cx;
		cin >> cx;
		x ^= 1<<cx;
		
		cout << tree[1][x].ans << endl;
	}
}
