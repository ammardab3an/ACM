// Problem: F - Box in Box
// Contest: AtCoder - Denso Create Programming Contest 2023 (AtCoder Beginner Contest 309)
// URL: https://atcoder.jp/contests/abc309/tasks/abc309_f
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
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

int tree[NMAX*3*4];

void update(int nd, int l, int r, int p, int v){
	
	if(l==r){
		tree[nd] = min(tree[nd], v);
		return;
	}	
	
	int mid = (l+r)/2;
	if(p <= mid){
		update(nd*2, l, mid, p, v);
	}
	else{
		update(nd*2+1, mid+1, r, p, v);
	}
	
	tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return INF;
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return min(st_path, nd_path);
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
	
	vi tmp;
	vector<array<int, 3>> vec(n);
	
	for(auto &v : vec){
		for(auto &e : v){
			cin >> e;
			tmp.push_back(e);
		}
	}
	
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	
	for(auto &v : vec){
		for(auto &e : v){
			e = lower_bound(tmp.begin(), tmp.end(), e)-tmp.begin();
		}
		sort(v.begin(), v.end());
	}
	
	sort(vec.begin(), vec.end());
	memset(tree, INF, sizeof tree);
	
	bool found = false;
	
	int lst_i = -1;
	vpii lst_updates;
	
	for(auto [i, x, y] : vec){
		
		if(i != lst_i){
			for(auto [x, y] : lst_updates){
				update(1, 0, tmp.size()-1, x, y);
			}
			lst_i = i;
			lst_updates.clear();
		}
		
		if(query(1, 0, tmp.size()-1, 0, x-1) < y){
			found = true;
			break;
		}
		
		lst_updates.push_back({x, y});
	}
	
	cout << (found ? "Yes" : "No") << endl;
}
