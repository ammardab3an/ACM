// Problem: D1. Painting the Array I
// Contest: Codeforces - Codeforces Round 700 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1480/D1
// Memory Limit: 512 MB
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

int m;
int arr[NMAX];
int mem[NMAX][20];

int go(int i, int dif){
	
	if(i >= m-1){
		return 0;
	}
	
	if(dif > 15){
		return 0;
	}
	
	int &ret = mem[i][dif+1];
	if(ret+1) return ret;
	
	int ans = 0;
	
	if(dif==-1){
		int st_path = go(i+1, -1) + (arr[i] != arr[i+1]);
		int nd_path = go(i+1, 1) + 1;
		ans = max(st_path, nd_path);	
	}
	else{
		int j = i-dif;
		int st_path = go(i+1, dif+1) + (arr[i] != arr[i+1]);
		int nd_path = go(i+1, 1) + (arr[j] != arr[i+1]);
		ans = max(st_path, nd_path);
	}
	
	return ret = ans;
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
	
	vpii tmp;
	int lst = vec[0];
	int cnt = 1;
	for(int i = 1; i < n; i++){
		auto e = vec[i];
		if(e != lst){
			tmp.push_back({lst, cnt});
			cnt = 0;
		}
		lst = e;
		cnt++;
	}
	
	tmp.push_back({lst, cnt});
	
	m = 0;
	for(auto [v, f] : tmp){
		f = min(f, int(2));
		while(f--) arr[m++] = v;
	}
	
	// cout << m << endl;
	// for(int i = 0; i < m; i++) cout << arr[i] << ' '; cout << endl;
	
	memset(mem, -1, sizeof mem);
	
	int ans = 1 + go(0, -1);
	cout << ans << endl;
}
