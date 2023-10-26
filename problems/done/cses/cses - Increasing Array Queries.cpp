// Problem: Increasing Array Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2416
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, m;
	cin >> n >> m;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	vi pre = vec;
	for(int i = 1; i < n; i++){
		pre[i] += pre[i-1];
	}
	
	vi nxt(n);
	stack<pii> st;
	st.push({INFLL, n});
	
	for(int i = n-1; i >= 0; i--){
		
		while(!st.empty() && st.top().first < vec[i]){
			st.pop();
		}
		
		assert(!st.empty());
		
		nxt[i] = st.top().second;
		
		st.push({vec[i], i});
	}
	
	auto calc = [&](int i, int r){	
		int j = min(nxt[i], r+1);
		int ret = (j-i-1)*vec[i] - (pre[j-1] - pre[i]);
		return ret;
	};
	
	int log_n = ceil(log2(double(n)));
	vector<vi> par(n+1, vi(log_n, n));
	vector<vi> par_val(n+1, vi(log_n));
	
	for(int i = n-1; i >= 0; i--){
		
		par[i][0] = nxt[i];
		for(int j = 1; j < log_n; j++){
			par[i][j] = par[par[i][j-1]][j-1];
		}
		
		// cout << i << ' ' << nxt[i] << ' ' << calc(i, n-1) << endl;
		
		par_val[i][0] = calc(i, n-1);
		for(int j = 1; j < log_n; j++){
			par_val[i][j] = par_val[i][j-1] + par_val[par[i][j-1]][j-1];
		}
	}
	
	
	while(m--){
		
		int l, r;
		cin >> l >> r;
		l--, r--;
		
		int cans = 0;
		
		int i = l;
		for(int j = log_n-1; j >= 0; j--){
			if(par[i][j] <= r){
				cans += par_val[i][j];
				i = par[i][j];
			}
		}
		
		cans += calc(i, r);
		
		cout << cans << endl;
	}
}
