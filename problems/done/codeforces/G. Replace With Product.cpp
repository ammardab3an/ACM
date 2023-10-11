// Problem: G. Replace With Product
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/G
// Memory Limit: 256 MB
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
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &e : vec) cin >> e;
		
		int l = 0;
		int r = n-1;
		
		while(l < n && vec[l]==1) l++;
		while(r >= 0 && vec[r]==1) r--;
		
		if(l >= r){
			cout << 1 << ' ' << 1 << endl;
			continue;
		}
		
		int sm = 0;
		for(int i = l; i <= r; i++){
			sm += vec[i];
		}
		
		bool good = false;
		
		int ml = 1;
		for(int i = l; i <= r; i++){
			if(log2(ml)+log2(vec[i]) > log2(2*sm)){
				good = true;
				break;
			}
			else{
				ml *= vec[i];
			}
		}
		
		if(good){
			cout << l+1 << ' ' << r+1 << endl;
			continue;
		}
		
		vi nxt(n);
		int lst = n;
		for(int i = n-1; i >= 0; i--){
			nxt[i] = lst;
			if(vec[i] != 1){
				lst = i;
			}
		}
		
		// for(auto e : nxt) cout << e << ' '; cout << endl << flush;
		
		pii ans = {0, 0};
		int ans_val = 0;
		
		for(int i = 0; i < n; i++) if(vec[i] != 1){
			
			int ml = 1;
			int sm = 0;
			int p = i;
			
			while(p < n){
				
				// cout << p << endl << flush;
				
				ml *= vec[p];
				sm += vec[p];
				
				if(ml-sm > ans_val){
					ans_val = ml-sm;
					ans = {i, p};
				}
				
				sm += nxt[p]-p-1;
				p = nxt[p];
			}
		}
		
		cout << ans.first+1 << ' ' << ans.second+1 << endl;
    }	
}
