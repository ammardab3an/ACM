// Problem: E. Max to the Right of Min
// Contest: Codeforces - Educational Codeforces Round 152 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1849/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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
 
const int NMAX = 1e6 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

int arr[NMAX];
vi blks[(NMAX/BLOCK)+4];
int lazy[(NMAX/BLOCK)+4];

void sqrt_build(int b){
	
	int l = b*BLOCK;
	int r = (b+1)*BLOCK-1;
	
	if(lazy[b]){
		for(int i = l; i <= r; i++){
			arr[i] += lazy[b];
		}
		lazy[b] = 0;
	}	
	
	blks[b] = vi(arr+l, arr+r+1);
	sort(blks[b].begin(), blks[b].end());
}

void sqrt_update(int l, int r, int val){
	
	int bl = l/BLOCK;
	int br = r/BLOCK;
	
	if(bl==br){
		for(int i = l; i <= r; i++){
			arr[i] += val;
		}
		sqrt_build(bl);
		return;
	}
	
	for(int b = bl+1; b < br; b++){
		lazy[b] += val;
	}
	
	for(int i = l; i/BLOCK==bl && i <= r; i++){
		arr[i] += val;
	}
	
	for(int i = r; i/BLOCK==br && i >= l; i--){
		arr[i] += val;
	}
	
	sqrt_build(bl);
	sqrt_build(br);
}

int sqrt_query(){
	int ret = 0;
	for(int i = 0; i <= (NMAX/BLOCK); i++){
		ret += blks[i].end() - upper_bound(blks[i].begin(), blks[i].end(), -lazy[i]);
	}	
	return ret;
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
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	if(n==0){
		n = 5e5;
		vec = vi(n);
		iota(vec.begin(), vec.end(), 1);
		random_shuffle(vec.begin(), vec.end());
	}
	
	uint64_t ans = 0;
	
	// {val, {(mx/mn)_idx, val_idx}}
	stack<pair<int, pii>> st_min, st_max;
	st_min.push({-INF, {-1, -1}});
	st_max.push({+INF, {-1, -1}});
	
	for(int i = 0; i < n; i++){
		
		int val = vec[i];
		
		while(st_max.top().first < val){
			auto tmp = st_max.top();
			st_max.pop();
			sqrt_update(st_max.top().second.second+1, tmp.second.second, -tmp.second.first);
		}
		
		while(st_min.top().first > val){
			auto tmp = st_min.top();
			st_min.pop();
			sqrt_update(st_min.top().second.second+1, tmp.second.second, +tmp.second.first);
		}
		
		sqrt_update(st_max.top().second.second+1, i, +i);
		sqrt_update(st_min.top().second.second+1, i, -i);
		
		st_max.push({val, {i, i}});
		st_min.push({val, {i, i}});
		
		ans += sqrt_query();
	}
	
	cout << ans << endl;
}
