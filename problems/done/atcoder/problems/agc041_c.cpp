// Problem: C - Domino Quality
// Contest: AtCoder - AtCoder Grand Contest 041
// URL: https://atcoder.jp/contests/agc041/tasks/agc041_c
// Memory Limit: 1024 MB
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
	
	if(n==2){
		cout << -1 << endl;
		return 0;
	}
	
	map<int, vector<string> > mp;
	
	mp[7] = {
	    "aabbcc.", 
	    ".nn..ka", 
	    "h....ka", 
	    "hm....b", 
	    "gm....b", 
	    "g..ll.c", 
	    "..ffeec"
	};
	
	mp[6] = {
	    "aabbcc", 
	    ".eel.d", 
	    "i..l.d", 
	    "i...ke", 
	    "h...ke", 
	    "hggff."
	};
	
	mp[5] = {
	    "aabbe", 
	    "j..le", 
	    "j..lf", 
	    "ikk.f", 
	    "ihhgg"
	};
	
	mp[4] = {
	    "aacd",
	    "bbcd",
	    "efgg",
	    "efhh"
	};
	
	mp[3] = {
	    "aa.",
	    "..b",
	    "..b"
	};
	
	if(mp.count(n)){
		for(auto s : mp[n]){
			cout << s << endl;
		}	
		return 0;
	}
	
	vi tmp = {4, 5, 6, 7};
	
	vector<string> ans(n, string(n, '.'));
	
	vi par(n+1, -1);
	
	par[0] = 0;
	for(int i = 0; i <= n; i++) if(par[i] != -1){
		for(auto j : tmp){
			if(i+j <= n){
				par[i+j] = i;
			}
		}
	}
	
	vi vals;
	int x = n;
	while(x){
		vals.push_back(x-par[x]);
		x = par[x];
	}
	
	int p = 0;
	for(auto e : vals){
		
		auto &cur = mp[e];
		
		for(int i = 0; i < e; i++)
		for(int j = 0; j < e; j++){
			ans[p+i][p+j] = cur[i][j];
		}
		
		p += e;
	}
	
	for(auto s : ans) cout << s << endl;
}
